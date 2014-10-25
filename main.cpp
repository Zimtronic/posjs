#include <QtWidgets>
#include "browser/mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    MainWindow browser(QUrl("file:///home/tony/workspace/browser/index.html"));

    browser.show();
    return app.exec();
}
