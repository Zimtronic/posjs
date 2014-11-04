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
unsigned short Device::getIdProduct() const
{
    return idProduct;
}

void Device::setIdProduct(unsigned short value)
{
    idProduct = value;
    ((LinuxUSB*)transport)->setIdProduct(value);
}
unsigned short Device::getIdVendor() const
{
    return idVendor;
}

void Device::setIdVendor(unsigned short value)
{
    idVendor = value;
    ((LinuxUSB*)transport)->setIdVendor(value);
}
