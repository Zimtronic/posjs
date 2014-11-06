# USB HID scanners

### Using barcode scanner and magnetic card reader

As you can see in [Javascript API](javascriptapi.md) the scanner object expose a single signal.
In the below example we call to the connect() function to establishes a connection between the signal 
packetRead and the slot onBarcodePacketArrived or onMagneticPacketArrived. 
Whenever the object BarcodeScanner or MagneticScanner emits the signal packetRead, 
the slot onBarcodePacketArrived or onMagneticPacketArrived gets called automatically.

 ```js
	BarcodeScanner.packetRead.connect(onBarcodePacketArrived);
    MagneticScanner.packetRead.connect(onMagneticPacketArrived);

    function onBarcodePacketArrived(packet)
    {
		//processing code
        alert("Barcode: "+packet);
    }
    
    function onMagneticPacketArrived(packet)
    {
		//processing code
        alert("Magnetic: "+packet);
    }
 ```

The argument of connect(), that we call slot, can be any JavaScript function as in the above example.
To disconnect a slot from a signal, you call the signal's disconnect() function with the slot as its argument:

 ```js
	BarcodeScanner.packetRead.disconnect(onBarcodePacketArrived);
    MagneticScanner.packetRead.disconnect(onMagneticPacketArrived);
 ```
 
see [index.html] (../posjs/index.html) 
