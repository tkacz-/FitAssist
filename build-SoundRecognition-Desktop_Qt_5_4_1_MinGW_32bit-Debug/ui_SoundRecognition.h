/********************************************************************************
** Form generated from reading UI file 'SoundRecognition.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDRECOGNITION_H
#define UI_SOUNDRECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_SoundRecognition
{
public:
    QAction *actionOpen;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *controlWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *controlButtons;
    QPushButton *openButton;
    QPushButton *startButton;
    QPushButton *quitButton;
    QwtPlot *qwtPlot;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SoundRecognition)
    {
        if (SoundRecognition->objectName().isEmpty())
            SoundRecognition->setObjectName(QStringLiteral("SoundRecognition"));
        SoundRecognition->resize(465, 352);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        SoundRecognition->setWindowIcon(icon);
        actionOpen = new QAction(SoundRecognition);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionQuit = new QAction(SoundRecognition);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(SoundRecognition);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        controlWidget = new QWidget(centralWidget);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));
        gridLayout_3 = new QGridLayout(controlWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        controlButtons = new QHBoxLayout();
        controlButtons->setSpacing(6);
        controlButtons->setObjectName(QStringLiteral("controlButtons"));
        openButton = new QPushButton(controlWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        controlButtons->addWidget(openButton);

        startButton = new QPushButton(controlWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        controlButtons->addWidget(startButton);

        quitButton = new QPushButton(controlWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        controlButtons->addWidget(quitButton);


        gridLayout_3->addLayout(controlButtons, 1, 0, 1, 1);

        qwtPlot = new QwtPlot(controlWidget);
        qwtPlot->setObjectName(QStringLiteral("qwtPlot"));

        gridLayout_3->addWidget(qwtPlot, 0, 0, 1, 1);


        gridLayout->addWidget(controlWidget, 0, 1, 1, 1);

        SoundRecognition->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SoundRecognition);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 465, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SoundRecognition->setMenuBar(menuBar);
        statusBar = new QStatusBar(SoundRecognition);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SoundRecognition->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(SoundRecognition);
        QObject::connect(quitButton, SIGNAL(pressed()), SoundRecognition, SLOT(close()));

        QMetaObject::connectSlotsByName(SoundRecognition);
    } // setupUi

    void retranslateUi(QMainWindow *SoundRecognition)
    {
        SoundRecognition->setWindowTitle(QApplication::translate("SoundRecognition", "SoundRecognition", 0));
        actionOpen->setText(QApplication::translate("SoundRecognition", "Open", 0));
        actionQuit->setText(QApplication::translate("SoundRecognition", "Quit", 0));
        openButton->setText(QApplication::translate("SoundRecognition", "Open", 0));
        startButton->setText(QApplication::translate("SoundRecognition", "Start", 0));
        quitButton->setText(QApplication::translate("SoundRecognition", "Quit", 0));
        menuFile->setTitle(QApplication::translate("SoundRecognition", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class SoundRecognition: public Ui_SoundRecognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDRECOGNITION_H
