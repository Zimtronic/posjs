#include <QtWidgets>
#include <QtNetwork>
#include <QtWebKitWidgets>
#include "mainwindow.h"

#include "drivers/escposprinter.h"
#include "drivers/linuxusb.h"
#include "drivers/generichidscanner.h"

MainWindow::MainWindow(const QUrl& url)
{
    progress = 0;

    QNetworkProxyFactory::setUseSystemConfiguration(true);

    view = new QWebView(this);
    view->load(url);
    connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
    connect(view, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));
    connect(view, SIGNAL(loadProgress(int)), SLOT(setProgress(int)));
    connect(view, SIGNAL(loadFinished(bool)), SLOT(finishLoading(bool)));

    locationEdit = new QLineEdit(this);
    locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
    connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

    QToolBar *toolBar = addToolBar(tr("Navigation"));
    toolBar->addAction(view->pageAction(QWebPage::Back));
    toolBar->addAction(view->pageAction(QWebPage::Forward));
    toolBar->addAction(view->pageAction(QWebPage::Reload));
    toolBar->addAction(view->pageAction(QWebPage::Stop));
    toolBar->addWidget(locationEdit);

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));
    QAction* viewSourceAction = new QAction("Page Source", this);
    connect(viewSourceAction, SIGNAL(triggered()), SLOT(viewSource()));
    viewMenu->addAction(viewSourceAction);

    setCentralWidget(view);
    setUnifiedTitleAndToolBarOnMac(true);

    printer = new ESCPOSPrinter();
    transport = new LinuxUSB();
    printer->setTransport(transport);

    hidBarcode = new GenericHIDScanner();
    hidBarcode->start();

    hidMagnetic = new GenericHIDScanner();
    hidMagnetic->setIdProduct(0x0001);
    hidMagnetic->setIdVendor(0x0801);
    hidMagnetic->start();

    QObject::connect(view->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
                         this, SLOT(addJSObject()));

}

MainWindow::~MainWindow()
{
    delete view;
//    delete transport;
//    delete printer;
}

void MainWindow::viewSource()
{
    QNetworkAccessManager* accessManager = view->page()->networkAccessManager();
    QNetworkRequest request(view->url());
    QNetworkReply* reply = accessManager->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(slotSourceDownloaded()));
}

void MainWindow::slotSourceDownloaded()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(const_cast<QObject*>(sender()));
    QTextEdit* textEdit = new QTextEdit(NULL);
    textEdit->setAttribute(Qt::WA_DeleteOnClose);
    textEdit->show();
    textEdit->setPlainText(reply->readAll());
    reply->deleteLater();
}

void MainWindow::adjustLocation()
{
    locationEdit->setText(view->url().toString());
}

void MainWindow::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    view->load(url);
    view->setFocus();
}

void MainWindow::adjustTitle()
{
    if (progress <= 0 || progress >= 100)
        setWindowTitle(view->title());
    else
        setWindowTitle(QString("%1 (%2%)").arg(view->title()).arg(progress));
}

void MainWindow::setProgress(int p)
{
    progress = p;
    adjustTitle();
}

void MainWindow::finishLoading(bool)
{
    progress = 100;
    adjustTitle();
}

void MainWindow::addJSObject()
{
    QWebFrame *frame = view->page()->mainFrame();
    frame->addToJavaScriptWindowObject("ESCPOSPrinter", (ESCPOSPrinter*)printer);
    frame->addToJavaScriptWindowObject("BarcodeScanner", hidBarcode);
    frame->addToJavaScriptWindowObject("MagneticScanner", hidMagnetic);
}
