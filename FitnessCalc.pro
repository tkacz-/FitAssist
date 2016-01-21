#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T18:14:09
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FitnessCalc
TEMPLATE = app

VERSION = 0.0.0.1
QMAKE_TARGET_PRODUCT = Fitness Calculator
QMAKE_TARGET_COPYRIGHT = Andrei Tkachenko
QMAKE_TARGET_DESCRIPTION = Simple fitness calculator

SOURCES += main.cpp\
        FitnessCalc.cpp \
    profile.cpp \
    piechart.cpp \
    adddialog.cpp \
    aboutDialog.cpp \
    editdialog.cpp \
    editlistdialog.cpp

HEADERS  += FitnessCalc.h \
    profile.h \
    piechart.h \
    adddialog.h \
    aboutDialog.h \
    editdialog.h \
    editlistdialog.h

FORMS    += FitnessCalc.ui \
    adddialog.ui \
    editdialog.ui \
    aboutDialog.ui \
    editlistdialog.ui

RC_ICONS = res/images/logo.ico

CONFIG += c++11

RESOURCES += \
    res/image.qrc
