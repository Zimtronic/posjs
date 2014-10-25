#ifndef ESCPOSPRINTER_H
#define ESCPOSPRINTER_H

#include <QObject>

#include "iticketprinter.h"
#include "errors.h"

   /**
    * @class ESCPOSPrinter
    * @brief Clase que implementa la interfaz @ITicketPrinter.
    *
    * Implementa las funcionalidades necesarias para imprimir
    * tickets mediante el uso de impresoras termicas que utilicen
    * el protocolo ESC/POS y se comuniquen por USB.
    *
    * @author tony
    * @date 18-10-2014
    */

class ESCPOSPrinter : public QObject, public ITicketPrinter
{
    Q_OBJECT

public:
    /**
     * @brief Contructor de la clase. Se inicia el atributo timeout.
     */
    ESCPOSPrinter();

    /**
     * @brief Trata de abrir el puerto USB de la impresora y en caso de
     * exito envia el comando de inicio.
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned init();

    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned printRawText(QString text);


    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    unsigned printRawText(unsigned char * text, unsigned textSize);

    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned cutPaper(bool fullCut);

    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned sendPulseToCashDrawer(unsigned pin);

    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned setTextProperties(unsigned align, unsigned font,
                                           unsigned type, unsigned width,
                                           unsigned height);

    /**
     * @brief
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned feedControl(unsigned crl);

    /**
     * @brief Devuelve informacion en forma de cadena de caracteres
     * sobre cada codigo de error.
     */
    Q_INVOKABLE QString getErrorString(unsigned errorCode);

    Q_INVOKABLE unsigned getTimeout() const;
    Q_INVOKABLE void setTimeout(const unsigned &value);

private:
    unsigned timeout; /**< Timeout para las operaciones sobre el puerto USB. */
};

#endif // ESCPOSPRINTER_H
