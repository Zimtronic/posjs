# Using others devices

By default we work with three devices: printer EPSON TM-T20II, barcode scanner MJ_tech V3.00
and magnetic card reader model MSR100. For now we have a laborious mechanism to change or add 
devices:

1. Go to [mainwindow.cpp](../posjs/browser/mainwindow.cpp) file in the source code.
2. Modify the createDevice() function:
   ```cpp
    void MainWindow::createDevices()
	{
		//      supported devices

		//    ESCPOSPrinter 0E15 04B8
		//    BarcodeScanner 1010 05FE
		//    MagneticScanner 0001 0801

		Device * device;
		device = new ESCPOSPrinter();
		device->setName("ESCPOSPrinter");
		device->setIdProduct(0x0e15);
		device->setIdVendor(0x04b8);
		devices.append(device);

		device = new GenericHIDScanner();
		device->setName("BarcodeScanner");
		device->setIdProduct(0x1010);
		device->setIdVendor(0x05FE);
		((GenericHIDScanner*)device)->start();
		devices.append(device);

		device = new GenericHIDScanner();
		device->setName("MagneticScanner");
		device->setIdProduct(0x0001);
		device->setIdVendor(0x0801);
		((GenericHIDScanner*)device)->start();
		devices.append(device);
	}
   ```
