#include "generichidscanner.h"
#include "errors.h"
#include "hidtable.h"

using namespace std;
#include <iostream>

GenericHIDScanner::GenericHIDScanner()
{

}

void GenericHIDScanner::run()
{
    unsigned bufferSize, ctrol, packetIndex;
    unsigned char buf[16], packet[256];

    unsigned result = errUSBIsClose;
    unsigned id;

    while (1)
    {
        if(result != OK && result != errUSBTimeout)
        {
            cout << "close open " <<(int)transport<< endl;
            transport->close();
            result = transport->open(id);
            cout << "close open " <<result<< endl;
        }

        bufferSize = 8;
        packetIndex = 0;
        memset(packet, 0, 256);

        do
        {
            result = transport->read(buf, bufferSize, 100);
            if(result == OK)
            {
                if(buf[2])
                {
                    if(buf[0] == 0x02)
                        ctrol = 1;
                    else
                        ctrol = 0;

                    packet[packetIndex++] = hidTable[(int)buf[2]][ctrol];
                }
//                cout << packet[packetIndex-1] << endl;
            }
        }while(result == OK);

        if(packetIndex)
        {
            cout << (int)packet[packetIndex-1] << endl;
            //if(packet[packetIndex-1] == '\r')
                emit packetRead(QString((const char*)packet));
        }
    }
}
