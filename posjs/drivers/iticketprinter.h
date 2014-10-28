#ifndef ITICKETPRINTER_H
#define ITICKETPRINTER_H

#include "itransport.h"

   /**
    * @class ITicketPrinter
    * @brief Interfaz para las impresoras de tickets
    *
    *
    *@author tony
    *@date 17-10-2014
    */

class QString;

class ITicketPrinter
{
public:
    /**
     * @brief Debe implementar las funciones de inicio de la impresora,
     * por ejemplo la configuracion del hardaware, el envio de comandos
     * de inicio, etc.
     */
    virtual unsigned init() = 0;

    /**
     * @brief Una vez configurada la impresora y formateado el texto, mediante
     * este metodo se envia a imprimir texto plano.
     */
    virtual unsigned printRawText(QString text) = 0;

    /**
     * @brief Como indica su nombre este metodo le indica a la impresora de
     * ticket que corte el papel.
     */
    virtual unsigned cutPaper(bool fullCut) = 0;

    /**
     * @brief Las impresoras de tickets deben brindan una interfaz de comunicacion
     * con las cajas de efectivo, mediante este metodo se permite el acceso
     * a dichas cajas.
     */
    virtual unsigned sendPulseToCashDrawer(unsigned pin) = 0;

    /**
     * @brief Permite formatear el texto que se desea imprimir.
     */
    virtual unsigned setTextProperties(unsigned align, unsigned font,
                                       unsigned type, unsigned width,
                                       unsigned height) = 0;

    /**
     * @brief
     */
    virtual unsigned feedControl(unsigned crl) = 0;

    /**
     * @brief Print bitmap image given a path.
     */
    virtual unsigned printImage(QString pathImage, unsigned rightTab, unsigned sizeScale) = 0;

    ITransport *getTransport() const;
    void setTransport(ITransport *value);

protected:
    ITransport * transport; /**< Puntero al transporte generico. */
};

inline ITransport *ITicketPrinter::getTransport() const
{
    return transport;
}

inline void ITicketPrinter::setTransport(ITransport *value)
{
    transport = value;
}

#endif // ITICKETPRINTER_H
