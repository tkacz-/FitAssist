#-------------------------------------------------
#
# Project created by QtCreator 2015-08-29T18:14:09
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FitAssist
TEMPLATE = app

VERSION = 0.0.0.13
QMAKE_TARGET_PRODUCT = FitAssist
QMAKE_TARGET_COPYRIGHT = Copyright(C) 2016 Andrii Tkachenko
QMAKE_TARGET_DESCRIPTION = Simple fitness assistant

SOURCES += main.cpp\
    Profile.cpp \
    PieChart.cpp \
    FitAssist.cpp \
    AboutDialog.cpp \
    AddDialog.cpp \
    EditDialog.cpp \
    EditListDialog.cpp

HEADERS  += \
    Profile.h \
    PieChart.h \
    FitAssist.h \
    AboutDialog.h \
    AddDialog.h \
    EditDialog.h \
    EditListDialog.h

FORMS    += \
    FitAssist.ui \
    AboutDialog.ui \
    AddDialog.ui \
    EditDialog.ui \
    EditListDialog.ui

RC_ICONS = res/images/logo.ico

CONFIG += c++11

RESOURCES += \
    res/image.qrc \
    res/image.qrc

#TRANSLATIONS += translations/ru.ts \
#    translations/en.ts
#DISTFILES += translations/*
