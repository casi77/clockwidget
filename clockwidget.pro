#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T14:33:49
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clockwidget
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    udpclient.cpp \
    udpserver.cpp

HEADERS  += mainwindow.h \
    udpserver.h \
    udpclient.h

FORMS    += mainwindow.ui

DISTFILES += \
    ReadMe.txt

RESOURCES += \
    resource.qrc

