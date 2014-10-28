#ifndef ESCPOSPRINTER_H
#define ESCPOSPRINTER_H

#include <QObject>
#include <QtWidgets>
#include <QBitArray>
#include <QBitmap>
#include <QImage>
#include <QRgb>

#include "iticketprinter.h"
#include "errors.h"

   /**
    * @class ESCPOSPrinter
    * @brief @ITicketPrinter implementation.
    *
    * This class has methods to print tickets using thermal
    * printers that use the ESC/POS  protocol over USB.
    *
    * @author tony
    * @date 18-10-2014
    */

class BitmapData;
class ESCPOSPrinter : public QObject, public ITicketPrinter
{
    Q_OBJECT

public:
    /**
     * @brief Class builder.
     */
    ESCPOSPrinter();

    /**
     * @brief Class destroyer.
     */
    virtual ~ESCPOSPrinter();

    /**
     * @brief Try to open USB port and send the init
     * command to the printer.
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned init();

    /**
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned printRawText(QString text);


    /**
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned cutPaper(bool fullCut);

    /**
     * Possible values ​​for pin parameter: 2, 5
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned sendPulseToCashDrawer(unsigned pin);

    /**
     * Possible values ​​for align parameter: 0->center, 1->right, 2->left
     * Possible values ​​for font parameter: 0->A, 1->B
     * Possible values ​​for type parameter: 0->B, 1->U, 2->U2, 3->BU, 4->BU2, 5->Normal
     * Possible values ​​for width parameter: 1->Normal width, 2->Double width
     * Possible values ​​for height parameter: 1->Normal heigth, 2->Double heigth
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned setTextProperties(unsigned align, unsigned font,
                                           unsigned type, unsigned width,
                                           unsigned height);

    /**
     * Possible values ​​for crl parameter: 0->LF, 1->FF, 2->CR, 3->HT, 4->VT
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned feedControl(unsigned crl);

    /**
     * Possible values ​​for sizeScale parameter: 0 <= sizeScale <= 10
     *
     * @see ITicketPrinter
     */
    Q_INVOKABLE unsigned printImage(QString pathImage, unsigned rightTab, unsigned sizeScale);

    /**
     * @brief Return error codes information.
     */
    Q_INVOKABLE QString getErrorString(unsigned errorCode);

    Q_INVOKABLE unsigned getTimeout() const;
    Q_INVOKABLE void setTimeout(const unsigned &value);

private:
    BitmapData getBitmap(QString pathImage, unsigned sizeScale);

    unsigned timeout; /**<Read and write operations timeout. */
    unsigned char * buffer;
    unsigned cursor;
};

class BitmapData
{
public:
    QBitArray Dots;
    int Height;
    int Width;
};

#endif // ESCPOSPRINTER_H
