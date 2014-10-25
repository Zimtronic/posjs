#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class QWebView;
class QLineEdit;

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

    void viewSource();
    void slotSourceDownloaded();

private:
    QWebView *view;
    QLineEdit *locationEdit;
    int progress;
};

#endif // MAINWINDOW_H
