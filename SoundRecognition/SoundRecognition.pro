#-------------------------------------------------
#
# Project created by QtCreator 2015-07-04T19:13:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SoundRecognition
TEMPLATE = app


SOURCES += main.cpp\
        SoundRecognition.cpp

HEADERS  += SoundRecognition.h

FORMS    += SoundRecognition.ui

INCLUDEPATH += C:/Qt/Qwt/include
LIBS += C:/Qt/Qwt/lib/qwtd.dll

win32 {
    RC_FILE += file.qrc
    OTHER_FILES += file.qrc
}
