#ifndef ERRORS_H
#define ERRORS_H

   /**
    * @brief En esta cabecera se definen los codigos
    * de error
    *
    *
    * @author tony
    * @date 18-10-2014
    */

const unsigned OK = 0;

/**
 * @brief USB errors
 */
const unsigned errUSBOpen = 1; /**< */
const unsigned errUSBConfig = 2; /**< */
const unsigned errUSBDeviceNotFound = 3; /**< */
const unsigned errUSBClose = 4; /**< */
const unsigned errUSBClaimInterface = 5; /**< */
const unsigned errUSBWrite = 6; /**< */
const unsigned errUSBRead = 7; /**< */
const unsigned errUSBIsClose = 8; /**< */

/**
 * @brief Printer errors
 */
const unsigned errPrinterUndefineFeedControl = 9; /**< */
const unsigned errPrinterUndefineCashDrawerPin = 10; /**< */
const unsigned errPrinterUndefineAlign = 11; /**< */
const unsigned errPrinterUndefineFont = 12; /**< */
const unsigned errPrinterUndefineType = 13; /**< */

/**
 * @brief Arreglo con la informacion relativa a cada
 * codido de error.
 */
static const char *errorsString[] =
{
    "OK",
    "Error opening USB port",
    "Error USB config",
    "Error USB device not found",
    "Error closing USB port",
    "Error USB claim interface",
    "Error USB write",
    "Error USB read",
    "Error USB is close",
    "Error printer undefine feed control",
    "Error printer undefine cash drawer pin",
    "Error printer undefine align",
    "Error printer undefine font",
    "Error printer undefine type"
};

#endif // ERRORS_H
