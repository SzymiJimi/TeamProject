#-------------------------------------------------
#
# Project created by QtCreator 2018-03-19T19:10:46
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projektZespolowy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog/addclient.cpp \
    model/client.cpp \
    services/savefile.cpp \
    model/product.cpp \
    model/invoice.cpp \
    model/sale.cpp \
    model/productsales.cpp \
    dialog/finddialog.cpp \
    services/shopping.cpp \
    dialog/addproduct.cpp \
    services/pdfcreator.cpp \
    dialog/invoicedialog.cpp

HEADERS += \
        mainwindow.h \
    dialog/addclient.h \
    model/client.h \
    services/savefile.h \
    model/product.h \
    model/invoice.h \
    model/sale.h \
    model/productsales.h \
    dialog/finddialog.h \
    services/shopping.h \
    dialog/addproduct.h \
    services/pdfcreator.h \
    dialog/invoicedialog.h

FORMS += \
        mainwindow.ui \
    dialog/addclient.ui \
    dialog/finddialog.ui \
    dialog/addproduct.ui \
    dialog/invoicedialog.ui
