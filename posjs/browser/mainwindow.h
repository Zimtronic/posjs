#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class QWebView;
class QLineEdit;

class ITicketPrinter;
class ITransport;
class GenericHIDScanner;

/**
 * @class MainWindow
 * @brief
 *
 * @author tony
 * @date 18-10-2014
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QUrl& url);
    ~MainWindow();

protected slots:

    void adjustLocation();
    void changeLocation();
    void adjustTitle();
    void setProgress(int p);
    void finishLoading(bool);

    void addJSObject();

    void viewSource();
    void slotSourceDownloaded();

private:
    QWebView *view;
    QLineEdit *locationEdit;
    int progress;
    ITicketPrinter *printer;
    ITransport * transport;
    GenericHIDScanner *hidBarcode;
    GenericHIDScanner *hidMagnetic;
};

#endif // MAINWINDOW_H
