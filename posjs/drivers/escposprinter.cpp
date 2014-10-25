#include <iostream>
using namespace std;

#include "escposprinter.h"
#include "escposcommands.h"

ESCPOSPrinter::ESCPOSPrinter()
{
    this->timeout = 1000;
}

unsigned ESCPOSPrinter::init()
{
    unsigned result = transport->open();
    if(result == OK)
    {
        unsigned len = INITLENGTH;
        result = transport->write(HW_INIT, len, this->timeout);
    }
    return result;
}

unsigned ESCPOSPrinter::printRawText(QString text)
{
    return printRawText((unsigned char*)text.toStdString().c_str(), text.length());
}

unsigned ESCPOSPrinter::printRawText(unsigned char *text, unsigned textSize)
{
    unsigned result = transport->write(text, textSize, this->timeout);
    return result;
}

unsigned ESCPOSPrinter::cutPaper(bool fullCut)
{
    unsigned result = OK;
    unsigned len = PAPERCUTLENGTH;

    if(fullCut)
    {
        result = transport->write(PAPER_FULL_CUT, len, this->timeout);
    }
    else
    {
        result = transport->write(PAPER_PART_CUT, len, this->timeout);
    }
    return result;
}

unsigned ESCPOSPrinter::sendPulseToCashDrawer(unsigned pin)
{
    unsigned result = OK;
    unsigned len = CASHDRAWERLENGTH;

    switch (pin)
    {
    case 2:
        result = transport->write(CD_KICK_2, len, this->timeout);
        break;
    case 5:
        result = transport->write(CD_KICK_5, len, this->timeout);
        break;
    default:
        return errPrinterUndefineCashDrawerPin;
        break;
    }
    return result;
}

unsigned ESCPOSPrinter::setTextProperties(unsigned align, unsigned font,
                                          unsigned type, unsigned width,
                                          unsigned height)
{
    unsigned result = OK;
    unsigned len = TEXTFORMATLENGTH;

    switch (align)
    {
    case 0: //center
        result = transport->write(TXT_ALIGN_CT, len, this->timeout);
        break;
    case 1: //right
        result = transport->write(TXT_ALIGN_RT, len, this->timeout);
        break;
    case 2: //left
        result = transport->write(TXT_ALIGN_LT, len, this->timeout);
        break;
    default:
        return errPrinterUndefineAlign;
        break;
    }

    if(result != OK)
        return result;

    if(font == 0) // A
    {
        result = transport->write(TXT_FONT_A, len, this->timeout);
    }
    else if(font == 1) // B
    {
        result = transport->write(TXT_FONT_B, len, this->timeout);
    }
    else
    {
        return errPrinterUndefineFont;
    }

    if(result != OK)
        return result;

    switch (type)
    {
    case 0: //B
        result = transport->write(TXT_BOLD_ON, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL_OFF, len, this->timeout);
        break;
    case 1: //U
        result = transport->write(TXT_BOLD_OFF, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL_ON, len, this->timeout);
        break;
    case 2: //U2
        result = transport->write(TXT_BOLD_OFF, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL2_ON, len, this->timeout);
        break;
    case 3: //BU
        result = transport->write(TXT_BOLD_ON, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL_ON, len, this->timeout);
        break;
    case 4: //BU2
        result = transport->write(TXT_BOLD_ON, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL2_ON, len, this->timeout);
        break;
    case 5: //Normal
        result = transport->write(TXT_BOLD_OFF, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_UNDERL_OFF, len, this->timeout);
        break;
    default:
        return errPrinterUndefineType;
        break;
    }

    if(result != OK)
        return result;

    if(width == 2 && height != 2)
    {
        result = transport->write(TXT_NORMAL, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_2WIDTH, len, this->timeout);
    }
    else if(height == 2 && width != 2)
    {
        result = transport->write(TXT_NORMAL, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_2HEIGHT, len, this->timeout);
    }
    else if(height == 2 && width == 2)
    {
        result = transport->write(TXT_2WIDTH, len, this->timeout);
        if(result != OK)
            return result;
        result = transport->write(TXT_2HEIGHT, len, this->timeout);
    }
    else
    {
        result = transport->write(TXT_NORMAL, len, this->timeout);
    }
    return result;
}

unsigned ESCPOSPrinter::feedControl(unsigned crl)
{
    unsigned result = OK;
    unsigned len = FEEDCONTROLLENGTH;

    switch (crl)
    {
    case 0: //LF
        result = transport->write(CTL_LF, len, this->timeout);
        break;
    case 1: //FF
        result = transport->write(CTL_FF, len, this->timeout);
        break;
    case 2: //CR
        result = transport->write(CTL_CR, len, this->timeout);
        break;
    case 3: //HT
        result = transport->write(CTL_HT, len, this->timeout);
        break;
    case 4: //VT
        result = transport->write(CTL_VT, len, this->timeout);
        break;
    default:
        return errPrinterUndefineFeedControl;
        break;
    }
    return result;
}

unsigned ESCPOSPrinter::getTimeout() const
{
    return timeout;
}

void ESCPOSPrinter::setTimeout(const unsigned &value)
{
    timeout = value;
}

QString ESCPOSPrinter::getErrorString(unsigned errorCode)
{
    if(errorCode > errPrinterUndefineType)
    {
        return QString("Undefine error code");
    }
    else
    {
        return QString(errorsString[errorCode]);
    }
}

