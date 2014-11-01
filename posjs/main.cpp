#include <QtWidgets>
#include "browser/mainwindow.h"

#include "drivers/hidtable.h"

using namespace std;
#include <iostream>

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);

    Q_INIT_RESOURCE(resource);

    MainWindow browser(QUrl("qrc:/index.html"));

    browser.show();
    return app.exec();
}
