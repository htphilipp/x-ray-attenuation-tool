#-------------------------------------------------
#
# Project created by QtCreator 2017-01-28T09:46:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = xrayMFPv1
TEMPLATE = app

#for distribution.
#
CONFIG += static
CONFIG += static-runtime
CONFIG += c++14
#
SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    xmat.cpp \
    xmatformula.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    xmat.h \
    xmatformula.h

FORMS    += mainwindow.ui
