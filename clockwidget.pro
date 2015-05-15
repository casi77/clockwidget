#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T14:33:49
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += qml
QT       += quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = clockwidget
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    myudp.cpp

HEADERS  += mainwindow.h \
    myudp.h

FORMS    += mainwindow.ui

DISTFILES += \
    ReadMe.txt

OTHER_FILES += \
    digital.qml

