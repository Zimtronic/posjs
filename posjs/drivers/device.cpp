#include "device.h"
#include "linuxusb.h"

Device::Device()
{
    transport = new LinuxUSB();
}

QString Device::getName() const
{
    return name;
}

void Device::setName(const QString &value)
{
    name = value;
}

ITransport *Device::getTransport() const
{
    return transport;
}

void Device::setTransport(ITransport *value)
{
    transport = value;
}

void Device::setIdProduct(unsigned short value)
{
    ((LinuxUSB*)transport)->setIdProduct(value);
}

void Device::setIdVendor(unsigned short value)
{
    ((LinuxUSB*)transport)->setIdVendor(value);
}
