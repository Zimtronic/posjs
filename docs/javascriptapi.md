# Javascript API

## Printers

We implement ESC/POS protocol and send commands by USB directly. 
The main advantage of using raw ESC/POS commands for printing instead 
of using the usb linux kernel driver is that the printing performance will be way faster.
In addition, no other mechanism is needed to print beyond the application that we provide.

All functions return an error code, you can obtain information about the errors
using the getErrorString function.

### init()

Initialize printer, hardware configuration and write the init command.
Resets all modes back to default.

### printRawText(string text)

Lets print raw text. Function feedControl(0) should be called after this. 

Parameters:
* `text`: ascii text to print

### cutPaper()

Cut the paper. 

### sendPulseToCashDrawer(int pin)

Lets access to cash drawer pins.

Parameters:
* `pin`: there are two posibles pins 2 or 5

### setTextProperties(int align, int font, int type, int width, int height)

Parameters:
* `align`: 0->center, 1->right, 2->left
* `font`: 0->A, 1->B
* `type`: 0->B, 1->U, 2->U2, 3->BU, 4->BU2, 5->Normal
* `width`: 1->Normal width, 2->Double width
* `height`: 1->Normal heigth, 2->Double heigth

### feedControl(int crl)

Send feed control sequences.

Parameters:
* `crl`: 0->LF, 1->FF, 2->CR, 3->HT, 4->VT

### printImage(string pathImage, int rightTab, int sizeScale)

Print bitmap image given a path.

Parameters:
* `pathImage`: absolute or relative path
* `rightTab`: image position, tab numbers from the left border of paper
* `sizeScale`: 0 <= sizeScale <= 20, depend of the image's size

### printBarcode(string code, int type, int width, int height, int pos, int font)

Print barcode.

Parameters:
* `code`: string to be encoded in the barcode, different barcodes have 
		  different requirements on the length of data that can be encoded
* `type`: specify the type of barcode, 65->UPC-A, 66->UPC-E, 67->JAN13(EAN),
		  68->JAN8(EAN), 69->CODE39, 70->ITF, 71->CODABAR, 72->CODE93, 73->CODE128
* `width`: height of the barcode in points, 1 <= n <= 255
* `height`: width of module, 2 <= n <= 6
* `pos`: set position of HRI characters, 0->not printed, 1->above barcode,
		 2->below barcode, 3->both above and below barcode
* `font`: set font of HRI characters, 0->font A, 1->font B

### printQRCode(string code, int errCorrect, int moduleSize)

Print qrcode.

Parameters:
* `code`: string to be encoded in the qrcode
* `errCorrect`: 48 <= errCorrect <= 51
* `moduleSize`: 1 <= moduleSize <= 16

### getErrorString(int errorCode)

Return error codes information.

Parameters:
* `errorCode`: int error code

## USB HID devices

When we connect an usb reader barcode or magnetic card reader on Linux, 
the operating system recognizes these devices as hid devices and provides 
a keyboard driver for them. We do not use this mechanism, we detach the linux 
driver and intercept the packets directly from the USB interface, thus 
reading is faster.

### packetRead(string packet)

This signal is emited when HID packet arrived.

Parameters:
* `packet`: ascii text

### getErrorString(int errorCode)

Return error codes information.

Parameters:
* `errorCode`: int error code
