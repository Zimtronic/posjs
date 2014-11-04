#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T00:07:38
#
#-------------------------------------------------

QT   += core webkitwidgets network widgets

LIBS += -L/usr/lib/$$system(uname -i)-linux-gnu
LIBS += -lusb

TARGET = posjsbrowser
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/include

SOURCES += main.cpp \
    browser/mainwindow.cpp \
    drivers/linuxusb.cpp \
    drivers/escposprinter.cpp \
    drivers/generichidscanner.cpp \
    drivers/device.cpp

HEADERS += \
    browser/mainwindow.h \
    drivers/itransport.h \
    drivers/linuxusb.h \
    drivers/iticketprinter.h \
    drivers/escposprinter.h \
    drivers/escposcommands.h \
    drivers/errors.h \
    drivers/generichidscanner.h \
    drivers/hidtable.h \
    drivers/device.h

RESOURCES += \
    resource.qrc
