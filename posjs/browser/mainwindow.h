#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

/**
 * @class MainWindow
 * @brief Posjs visual browser
 *
 * @author tony
 * @date 18-10-2014
 */

class QWebView;
class QLineEdit;

class Device;

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

    QList<Device *> devices;

    void createDevices();
};

#endif // MAINWINDOW_H
