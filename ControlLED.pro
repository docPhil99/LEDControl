#-------------------------------------------------
#
# Project created by QtCreator 2015-08-07T16:18:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlLED
TEMPLATE = app
QT += serialport

SOURCES += main.cpp\
        mainwindow.cpp \
    ledcontrol.cpp

HEADERS  += mainwindow.h \
    ledcontrol.h

FORMS    += mainwindow.ui
