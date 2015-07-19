#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Q_INIT_RESOURCE(resource);

    MainWindow browser(QUrl("qrc:/index.html"));

    browser.show();
    return app.exec();
}
