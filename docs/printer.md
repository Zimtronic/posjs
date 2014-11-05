# Printer

To use the printer in javascript you must call init() function in first place. 
Below we use the `ESCPOSPrinter` object, that is the name of our printer object (see createDevices() 
function in [mainwindow.cpp](../posjs/browser/mainwindow.cpp)). 

See [index.html] (../posjs/index.html) for complete code.

### Example 1: Print "HELLO WORLD"

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.setTextProperties(0,0,4,2,2);
        ESCPOSPrinter.printRawText("...HELLO WORLD...");
        ESCPOSPrinter.feedControl(0);
 ```

see [index.html] (../posjs/index.html) 

### Example 2: Print text with different properties 

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.setTextProperties(2,0,0,1,1);
        ESCPOSPrinter.printRawText("align-left, font-A, type-B, width-normal, heigth-normal");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(0,1,0,1,1);
        ESCPOSPrinter.printRawText("align-center, font-B, type-B, width-normal, heigth-normal");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(1,1,1,2,1);
        ESCPOSPrinter.printRawText("align-right, font-B, type-U, width-double, heigth-normal");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(1,1,2,1,2);
        ESCPOSPrinter.printRawText("align-right, font-B, type-U2, width-normal, heigth-double");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(0,0,4,2,2);
        ESCPOSPrinter.printRawText("align-center, font-A, type-BU2, width-double, heigth-double");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0); 
 ```

see [index.html] (../posjs/index.html) 
 
### Example 3: Feed control and paper cut

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.setTextProperties(0,0,0,1,1);
        ESCPOSPrinter.printRawText("Two empty lines and cut..");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.cutPaper(); 
 ```

see [index.html] (../posjs/index.html)  
 
### Example 4: Print an image with different sizes and locations

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printImage(":/zimtronic-logo.png", 0, 9);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printImage(":/zimtronic-logo.png", 1, 7);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printImage(":/zimtronic-logo.png", 2, 5);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printImage(":/zimtronic-logo.png", 3, 3);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printImage(":/zimtronic-logo.png", 4, 1);
        ESCPOSPrinter.feedControl(0); 
 ```

see [index.html] (../posjs/index.html) 
 
### Example 5: Print Barcode

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.setTextProperties(0,0,0,1,1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" width-2,heigth-30,font-B");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 65, 2, 50, 0, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" width-3,heigth-50,font-B");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 65, 3, 50, 0, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" width-4,heigth-70,font-B");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 65, 4, 70, 0, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" width-5,heigth-90,font-A");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 65, 5, 90, 0, 0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" width-6,heigth-110,font-A");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 65, 6, 110, 0, 0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"12345678901\" text above");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("12345678901", 69, 2, 50, 1, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"ZIMTRONIC\" text below");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("ZIMTRONIC", 69, 2, 50, 2, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Code \"ZIMTRONIC$%\" text above and below");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("ZIMTRONIC$%", 69, 2, 50, 2, 1);
        ESCPOSPrinter.feedControl(0); 
 ```
 
see [index.html] (../posjs/index.html) 

### Example 6: Print QRCode

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.setTextProperties(0,0,0,1,1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printQRCode("HELLO", 51, 3);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printQRCode("HELLO", 51, 5);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printQRCode("ZIMTRONIC", 51, 7);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printQRCode("ZIMTRONIC", 51, 9);
        ESCPOSPrinter.feedControl(0); 
 ```

see [index.html] (../posjs/index.html) 
 
### Example 7: Print ticket example

 ```js
        ESCPOSPrinter.init();
        ESCPOSPrinter.printImage(":/zimtronic-pos.png", 1, 15);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(0,0,4,1,2);
        ESCPOSPrinter.printRawText("MANAGER -> RENE LOPEZ --STATION V");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(0,0,4,1,1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("5/11/2014   01:48 AM");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Product                      Price");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("----------------------------------");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Milk 65 Fl oz                 3.40");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Cookies                       5.00");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Subtotal                      8.40");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Tax 10%                       0.84");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Total                         9.24");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Cash tend                    10.00");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printRawText("Cash due                      0.76");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.setTextProperties(0,0,4,1,2);
        ESCPOSPrinter.printRawText("                            THANKS");
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.printBarcode("ZIMTRONIC$%", 69, 2, 50, 2, 1);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.feedControl(0);
        ESCPOSPrinter.cutPaper(); 
 ```

see [index.html] (../posjs/index.html) 
