#include "linuxusb.h"
#include "errors.h"

#include <iostream>
using namespace std;

LinuxUSB::LinuxUSB()
{
    //printer
    this->idProduct = 0x0e15;
    this->idVendor = 0x04b8;
    this->interface = 0;
    this->inEndPoint = 0x82;
    this->outEndPoint = 0x01;

    this->isOpen = false;
    this->debug = false;
    //Barcode scanner
    //    this->idProduct = 0x1010;
    //    this->idVendor = 0x05fe;

    //Magnetic card scanner
    //    this->idProduct = 0x0001;
    //    this->idVendor = 0x0801;
}

LinuxUSB::~LinuxUSB()
{
    if(this->isOpen)
        close();
}

unsigned LinuxUSB::open(unsigned &deviceId)
{
    if(this->debug)
        cout << "LinuxUSB::open" << endl;

    this->isOpen = false;
    bool foundDevice = false;

    struct usb_bus *bus;
    struct usb_device *dev;
    struct usb_interface *iface;
    struct usb_interface_descriptor *desc;
    struct usb_endpoint_descriptor *ep;
    uint8_t buf[1024];
    int i, n, len, claimed;

    usb_init();
    usb_find_busses();
    usb_find_devices();

    for (bus = usb_get_busses(); bus; bus = bus->next)
    {
        for (dev = bus->devices; dev; dev = dev->next)
        {
            if (this->idVendor > 0 && dev->descriptor.idVendor != this->idVendor) continue;
            if (this->idProduct > 0 && dev->descriptor.idProduct != this->idProduct) continue;
            if (!dev->config) continue;
            if (dev->config->bNumInterfaces < 1) continue;

            iface = dev->config->interface;
            this->handle = NULL;
            claimed = 0;
            for (i=0; i<dev->config->bNumInterfaces && iface; i++, iface++)
            {
                desc = iface->altsetting;
                if (!desc) continue;

                if(this->debug)
                    cout << "type "<<  (int)desc->bInterfaceClass << " "
                         << (int)desc->bInterfaceSubClass << " " << (int)desc->bInterfaceProtocol << endl;

                if (desc->bInterfaceClass != 3 && desc->bInterfaceClass != 7)
                {
                    continue;
                }
                ep = desc->endpoint;
                this->inEndPoint = 0;
                this->outEndPoint = 0;
                for (n = 0; n < desc->bNumEndpoints; n++, ep++)
                {
                    if (ep->bEndpointAddress & 0x80)
                    {
                        if (!this->inEndPoint)
                            this->inEndPoint = ep->bEndpointAddress & 0x7F;

                        if(this->debug)
                            cout <<"IN endpoint " << this->inEndPoint;
                    }
                    else
                    {
                        if (!this->outEndPoint)
                            this->outEndPoint = ep->bEndpointAddress;

                        if(this->debug)
                            cout <<"OUT endpoint " << this->outEndPoint;
                    }
                }
                if (!this->inEndPoint) continue;
                if (!this->handle)
                {
                    this->handle = usb_open(dev);
                    if (!this->handle)
                    {
                        if(this->debug)
                            cout <<"unable to open device" << endl;
                        break;
                    }
                }

                if (usb_get_driver_np(this->handle, i, (char *)buf, sizeof(buf)) >= 0)
                {
                    if(this->debug)
                        cout << "in use by driver " << buf << endl;
                    if (usb_detach_kernel_driver_np(this->handle, i) < 0)
                    {
                        if(this->debug)
                            cout << "unable to detach from kernel" << endl;
                        continue;
                    }
                }
                if (usb_claim_interface(this->handle, i) < 0)
                {
                    if(this->debug)
                        cout << "unable claim interface " << i << endl;
                    continue;
                }

                if(desc->bInterfaceClass == 3)
                {
                    len = usb_control_msg(this->handle, 0x81, 6, 0x2200, i, (char *)buf, sizeof(buf), 250);

                    if(this->debug)
                        cout <<"descriptor, len= "<< len << endl;

                    if (len < 2)
                    {
                        usb_release_interface(this->handle, i);
                        continue;
                    }
                    deviceId = 2;
                }
                else
                {
                    deviceId = 1;
                }

                foundDevice = true;
                claimed++;
                this->interface = i;
            }
            if (this->handle && !claimed)
            {
                foundDevice = false;
                usb_close(this->handle);
            }
        }
    }

    if(foundDevice)
    {
        this->isOpen = true;
        return OK;
    }
    else
    {
        return errUSBDeviceNotFound;
    }
}

unsigned LinuxUSB::close()
{
    int result = OK;
    if(this->isOpen)
    {
        usb_release_interface(this->handle, this->interface);
        result = usb_close(this->handle);
    }
    this->isOpen = false;
    if(result >= 0)
        return OK;
    else
        return errUSBClose;
}

unsigned LinuxUSB::read(unsigned char *buffer, unsigned &bufferSize,
                        unsigned timeOut)
{
    if(this->isOpen)
    {
        int result = usb_interrupt_read(this->handle, this->inEndPoint, (char*)buffer, bufferSize, timeOut);
        if (result <= 0)
        {
            if(result == -110)
                return errUSBTimeout;
            return errUSBRead;
        }
        bufferSize = result;
        return OK;
    }
    else
    {
        return errUSBIsClose;
    }
}

unsigned LinuxUSB::write(unsigned char *buffer, unsigned &bufferSize,
                         unsigned timeOut)
{
    if(this->isOpen)
    {
        int result = usb_bulk_write(this->handle, this->outEndPoint, (const char*)buffer, bufferSize, timeOut);
        if (result < 0)
        {
            return errUSBWrite;
        }
        bufferSize = result;

        return OK;
    }
    else
    {
        return errUSBIsClose;
    }
}

unsigned LinuxUSB::getIdProduct() const
{
    return idProduct;
}

void LinuxUSB::setIdProduct(const unsigned &value)
{
    idProduct = value;
}

unsigned LinuxUSB::getIdVendor() const
{
    return idVendor;
}

void LinuxUSB::setIdVendor(const unsigned &value)
{
    idVendor = value;
}
