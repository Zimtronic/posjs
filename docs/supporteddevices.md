# Using others devices

By default we work with three devices: printer EPSON TM-T20II, barcode scanner MJ_tech V3.00
and magnetic card reader model MSR100. For now we have a laborious mechanism to change or add 
devices:

1. Go to [mainwindow.cpp](../posjs/mainwindow.cpp) file in the source code.
2. Modify the addJSObject() function:
   ```cpp
    void MainWindow::addJSObject()
	{
		//      supported devices

		//    ESCPOSPrinter 0E15 04B8
		//    BarcodeScanner 1010 05FE
		//    MagneticScanner 0001 0801

		QWebFrame *frame = view->page()->mainFrame();

		if (posdriver)
		{
			frame->addToJavaScriptWindowObject("ESCPOSPrinter", (QObject*)posdriver->getESCPOSPrinterInstance());
			frame->addToJavaScriptWindowObject("BarcodeScanner", (QObject*)posdriver->getBarcodeScannerInstance());
			frame->addToJavaScriptWindowObject("MagneticScanner", (QObject*)posdriver->getMagneticScannerInstance());
		}
	}
   ```
   
3. Go to the project root, recompile and run again.

  ```sh
  cd posjs
  make
  export QT_PLUGIN_PATH=path_to_libposjs.so
  sudo ./posjsbrowser
  ```
