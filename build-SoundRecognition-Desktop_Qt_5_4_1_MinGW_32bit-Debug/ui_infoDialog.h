/********************************************************************************
** Form generated from reading UI file 'infoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFODIALOG_H
#define UI_INFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_infoDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *infoGroupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *fileSize;
    QLabel *touched;
    QLabel *created;
    QGroupBox *headerGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_4;
    QLabel *fileType;
    QLabel *fileSize_2;
    QLabel *marker;
    QLabel *formatName;
    QLabel *formatLenght;
    QLabel *formatType;
    QLabel *nChannels;
    QLabel *sRate;
    QLabel *bRate;
    QLabel *bAlign;
    QLabel *bits;

    void setupUi(QDialog *infoDialog)
    {
        if (infoDialog->objectName().isEmpty())
            infoDialog->setObjectName(QStringLiteral("infoDialog"));
        infoDialog->resize(401, 340);
        gridLayout = new QGridLayout(infoDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        infoGroupBox = new QGroupBox(infoDialog);
        infoGroupBox->setObjectName(QStringLiteral("infoGroupBox"));
        horizontalLayout = new QHBoxLayout(infoGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(infoGroupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(infoGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(infoGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        fileSize = new QLabel(infoGroupBox);
        fileSize->setObjectName(QStringLiteral("fileSize"));

        verticalLayout_2->addWidget(fileSize);

        touched = new QLabel(infoGroupBox);
        touched->setObjectName(QStringLiteral("touched"));

        verticalLayout_2->addWidget(touched);

        created = new QLabel(infoGroupBox);
        created->setObjectName(QStringLiteral("created"));

        verticalLayout_2->addWidget(created);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addWidget(infoGroupBox, 0, 0, 1, 1);

        headerGroupBox = new QGroupBox(infoDialog);
        headerGroupBox->setObjectName(QStringLiteral("headerGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(headerGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(headerGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(headerGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(headerGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(headerGroupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(headerGroupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(headerGroupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_10 = new QLabel(headerGroupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_3->addWidget(label_10);

        label_11 = new QLabel(headerGroupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_12 = new QLabel(headerGroupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_13 = new QLabel(headerGroupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_3->addWidget(label_13);

        label_14 = new QLabel(headerGroupBox);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_3->addWidget(label_14);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        fileType = new QLabel(headerGroupBox);
        fileType->setObjectName(QStringLiteral("fileType"));

        verticalLayout_4->addWidget(fileType);

        fileSize_2 = new QLabel(headerGroupBox);
        fileSize_2->setObjectName(QStringLiteral("fileSize_2"));

        verticalLayout_4->addWidget(fileSize_2);

        marker = new QLabel(headerGroupBox);
        marker->setObjectName(QStringLiteral("marker"));

        verticalLayout_4->addWidget(marker);

        formatName = new QLabel(headerGroupBox);
        formatName->setObjectName(QStringLiteral("formatName"));

        verticalLayout_4->addWidget(formatName);

        formatLenght = new QLabel(headerGroupBox);
        formatLenght->setObjectName(QStringLiteral("formatLenght"));

        verticalLayout_4->addWidget(formatLenght);

        formatType = new QLabel(headerGroupBox);
        formatType->setObjectName(QStringLiteral("formatType"));

        verticalLayout_4->addWidget(formatType);

        nChannels = new QLabel(headerGroupBox);
        nChannels->setObjectName(QStringLiteral("nChannels"));

        verticalLayout_4->addWidget(nChannels);

        sRate = new QLabel(headerGroupBox);
        sRate->setObjectName(QStringLiteral("sRate"));

        verticalLayout_4->addWidget(sRate);

        bRate = new QLabel(headerGroupBox);
        bRate->setObjectName(QStringLiteral("bRate"));

        verticalLayout_4->addWidget(bRate);

        bAlign = new QLabel(headerGroupBox);
        bAlign->setObjectName(QStringLiteral("bAlign"));

        verticalLayout_4->addWidget(bAlign);

        bits = new QLabel(headerGroupBox);
        bits->setObjectName(QStringLiteral("bits"));

        verticalLayout_4->addWidget(bits);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addWidget(headerGroupBox, 1, 0, 1, 1);


        retranslateUi(infoDialog);

        QMetaObject::connectSlotsByName(infoDialog);
    } // setupUi

    void retranslateUi(QDialog *infoDialog)
    {
        infoDialog->setWindowTitle(QApplication::translate("infoDialog", "File Info", 0));
        infoGroupBox->setTitle(QApplication::translate("infoDialog", "Input file", 0));
        label->setText(QApplication::translate("infoDialog", "File Size:", 0));
        label_2->setText(QApplication::translate("infoDialog", "Touched:", 0));
        label_3->setText(QApplication::translate("infoDialog", "File created:", 0));
        fileSize->setText(QString());
        touched->setText(QString());
        created->setText(QString());
        headerGroupBox->setTitle(QApplication::translate("infoDialog", "Wav Header info", 0));
        label_4->setText(QApplication::translate("infoDialog", "File Type:", 0));
        label_5->setText(QApplication::translate("infoDialog", "File Size:", 0));
        label_6->setText(QApplication::translate("infoDialog", "Wav Marker:", 0));
        label_7->setText(QApplication::translate("infoDialog", "Format Name:", 0));
        label_8->setText(QApplication::translate("infoDialog", "Format Length:", 0));
        label_9->setText(QApplication::translate("infoDialog", "Format Type:", 0));
        label_10->setText(QApplication::translate("infoDialog", "Number of channels:", 0));
        label_11->setText(QApplication::translate("infoDialog", "Sample rate:", 0));
        label_12->setText(QApplication::translate("infoDialog", "Byte rate:", 0));
        label_13->setText(QApplication::translate("infoDialog", "Block align:", 0));
        label_14->setText(QApplication::translate("infoDialog", "Bits per sample", 0));
        fileType->setText(QString());
        fileSize_2->setText(QString());
        marker->setText(QString());
        formatName->setText(QString());
        formatLenght->setText(QString());
        formatType->setText(QString());
        nChannels->setText(QString());
        sRate->setText(QString());
        bRate->setText(QString());
        bAlign->setText(QString());
        bits->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class infoDialog: public Ui_infoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
