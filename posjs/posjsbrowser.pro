#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T00:07:38
#
#-------------------------------------------------

QT   += core webkitwidgets network widgets testlib

LIBS += -L/usr/lib/$$system(uname -i)-linux-gnu
LIBS += -lusb

TARGET = posjsbrowser
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/include

SOURCES += main.cpp \
    mainwindow.cpp

HEADERS += \
    posdriverinterface.h \
    mainwindow.h

RESOURCES += \
    resource.qrc
