#ifndef GENERICHIDSCANNER_H
#define GENERICHIDSCANNER_H

#include <QThread>

#include "linuxusbhid.h"

class GenericHIDScanner : public QThread
{
    Q_OBJECT

public:
    GenericHIDScanner();
    void run();
    Q_INVOKABLE void setIdProduct(const unsigned &value);
    Q_INVOKABLE void setIdVendor(const unsigned &value);

signals:
    void packetRead(QString packet);

private:
    LinuxUSBHid * hid;
};

#endif // GENERICHIDSCANNER_H
