#ifndef GENERICHIDSCANNER_H
#define GENERICHIDSCANNER_H

#include <QThread>

#include "device.h"
#include "linuxusb.h"

    /**
     * @class GenericHIDScanner
     * @brief Thread to scan USB HID devices
     *
     * This class try to read ASCII packets from USB
     * HID devices
     *
     * @author tony
     * @date 28-10-2014
     */

class GenericHIDScanner: public QThread , public Device
{
    Q_OBJECT

public:
    /**
     * @brief Class builder
     */
    GenericHIDScanner();

    /**
     * @brief Reimplemented thread run method
     */
    void run();

    /**
     * @brief Return error codes information
     */
    Q_INVOKABLE QString getErrorString(unsigned errorCode);

signals:
    /**
     * @brief This signal is emited when HID packet arrived
     */
    void packetRead(QString packet);
};

#endif // GENERICHIDSCANNER_H
