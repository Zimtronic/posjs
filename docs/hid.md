# USB HID scanners

### Using barcode scanner and magnetic card reader

 ```js
	BarcodeScanner.packetRead.connect(onBarcodePacketArrived)
    MagneticScanner.packetRead.connect(onMagneticPacketArrived)

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

see [index.html] (../posjs/index.html) 
