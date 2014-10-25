#ifndef LINUXUSB_H
#define LINUXUSB_H

#include "itransport.h"
#include <usb.h>

   /**
    * @class LinuxUSB
    * @brief Clase que implementa la interfaz @ITransport.
    *
    * Implementa las funcionalidades necesarias la comunicacion
    * USB en linux. Hace uso de la biblioteca libusb.
    *
    * @author tony
    * @date 18-10-2014
    */

class LinuxUSB : public ITransport
{
public:
    /**
     * @brief Constructor de la clase
     */
    LinuxUSB();

    /**
     * @brief Destructor de la clase
     */
    ~LinuxUSB();

    /**
     * @brief Inicializa la biblioteca libusb, encuentra los buses y
     * los dispositivos usb del sistema. Verifica si el dispositivo
     * configurado se encuentra conectado en algun bus del sistema,
     * si el disposito no aparece se devuelve el codigo de error
     * correspondiente.
     *
     * @see ITransport
     */
    unsigned open();

    /**
     * @brief Cierra la interface USB, libera el handle de la comunicacion.
     *
     * @see ITransport
     */
    unsigned close();

    /**
     * @brief Trata de leer datos del puerto USB.
     *
     * @see ITransport
     */
    unsigned read(unsigned char* buffer, unsigned &bufferSize, unsigned timeOut);

    /**
     * @brief Trata de escribir datos en el puerto USB.
     *
     * @see ITransport
     */
    unsigned write(unsigned char* buffer, unsigned &bufferSize, unsigned timeOut);

    unsigned getIdProduct() const;
    void setIdProduct(const unsigned &value);

    unsigned getIdVendor() const;
    void setIdVendor(const unsigned &value);

    unsigned getInterface() const;
    void setInterface(const unsigned &value);

    unsigned getInEndPoint() const;
    void setInEndPoint(const unsigned &value);

    unsigned getOutEndPoint() const;
    void setOutEndPoint(const unsigned &value);

    unsigned getConfiguration() const;
    void setConfiguration(const unsigned &value);

private:
    unsigned idProduct; /**< */
    unsigned idVendor; /**< */
    unsigned interface; /**< */
    unsigned configuration; /**< */
    unsigned inEndPoint; /**< */
    unsigned outEndPoint; /**< */

    struct usb_dev_handle *handle; /**< Manipulador para la conexion con el dispositivo USB. */

    bool isOpen; /**< Estado de la conexion. */
};

#endif // LINUXUSB_H
