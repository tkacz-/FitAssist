#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T18:14:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FitnessCalc
TEMPLATE = app

VERSION = 0.0.0.1
QMAKE_TARGET_PRODUCT = Fitness Calculator
QMAKE_TARGET_COPYRIGHT = Andrei Tkachenko
QMAKE_TARGET_DESCRIPTION = Simple fitness calculator

SOURCES += main.cpp\
        FitnessCalc.cpp \
    aboutDialog.cpp \
    profile.cpp

HEADERS  += FitnessCalc.h \
    aboutDialog.h \
    profile.h

FORMS    += FitnessCalc.ui \
    aboutDialog.ui

RC_ICONS = res/images/logo.ico

RESOURCES += \
    res/image.qrc
