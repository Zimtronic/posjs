#ifndef LINUXUSBHID_H
#define LINUXUSBHID_H

#include "linuxusb.h"

class LinuxUSBHid : public LinuxUSB
{
public:
    LinuxUSBHid();
    unsigned open();
    unsigned read(unsigned char* buffer, unsigned &bufferSize, unsigned timeOut);

    void test();
};

#endif // LINUXUSBHID_H
