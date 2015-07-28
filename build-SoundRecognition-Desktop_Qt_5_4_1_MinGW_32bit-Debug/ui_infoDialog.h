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
    QGroupBox *fileGroupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *filesize;
    QLabel *created;
    QLabel *touched;
    QGroupBox *headerGroupBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_4;
    QLabel *fileType;
    QLabel *size;
    QLabel *marker;
    QLabel *name;
    QLabel *flength;
    QLabel *ftype;
    QLabel *nChannels;
    QLabel *srate;
    QLabel *brate;
    QLabel *balign;
    QLabel *bitspersample;

    void setupUi(QDialog *infoDialog)
    {
        if (infoDialog->objectName().isEmpty())
            infoDialog->setObjectName(QStringLiteral("infoDialog"));
        infoDialog->resize(252, 367);
        gridLayout = new QGridLayout(infoDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        fileGroupBox = new QGroupBox(infoDialog);
        fileGroupBox->setObjectName(QStringLiteral("fileGroupBox"));
        horizontalLayout = new QHBoxLayout(fileGroupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(fileGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(fileGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(fileGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        filesize = new QLabel(fileGroupBox);
        filesize->setObjectName(QStringLiteral("filesize"));

        verticalLayout_2->addWidget(filesize);

        created = new QLabel(fileGroupBox);
        created->setObjectName(QStringLiteral("created"));

        verticalLayout_2->addWidget(created);

        touched = new QLabel(fileGroupBox);
        touched->setObjectName(QStringLiteral("touched"));

        verticalLayout_2->addWidget(touched);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addWidget(fileGroupBox, 0, 0, 1, 1);

        headerGroupBox = new QGroupBox(infoDialog);
        headerGroupBox->setObjectName(QStringLiteral("headerGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(headerGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
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

        label_15 = new QLabel(headerGroupBox);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_3->addWidget(label_15);

        label_16 = new QLabel(headerGroupBox);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_3->addWidget(label_16);

        label_17 = new QLabel(headerGroupBox);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_3->addWidget(label_17);

        label_18 = new QLabel(headerGroupBox);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_3->addWidget(label_18);

        label_19 = new QLabel(headerGroupBox);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_3->addWidget(label_19);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        fileType = new QLabel(headerGroupBox);
        fileType->setObjectName(QStringLiteral("fileType"));

        verticalLayout_4->addWidget(fileType);

        size = new QLabel(headerGroupBox);
        size->setObjectName(QStringLiteral("size"));

        verticalLayout_4->addWidget(size);

        marker = new QLabel(headerGroupBox);
        marker->setObjectName(QStringLiteral("marker"));

        verticalLayout_4->addWidget(marker);

        name = new QLabel(headerGroupBox);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout_4->addWidget(name);

        flength = new QLabel(headerGroupBox);
        flength->setObjectName(QStringLiteral("flength"));

        verticalLayout_4->addWidget(flength);

        ftype = new QLabel(headerGroupBox);
        ftype->setObjectName(QStringLiteral("ftype"));

        verticalLayout_4->addWidget(ftype);

        nChannels = new QLabel(headerGroupBox);
        nChannels->setObjectName(QStringLiteral("nChannels"));

        verticalLayout_4->addWidget(nChannels);

        srate = new QLabel(headerGroupBox);
        srate->setObjectName(QStringLiteral("srate"));

        verticalLayout_4->addWidget(srate);

        brate = new QLabel(headerGroupBox);
        brate->setObjectName(QStringLiteral("brate"));

        verticalLayout_4->addWidget(brate);

        balign = new QLabel(headerGroupBox);
        balign->setObjectName(QStringLiteral("balign"));

        verticalLayout_4->addWidget(balign);

        bitspersample = new QLabel(headerGroupBox);
        bitspersample->setObjectName(QStringLiteral("bitspersample"));

        verticalLayout_4->addWidget(bitspersample);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addWidget(headerGroupBox, 1, 0, 1, 1);


        retranslateUi(infoDialog);

        QMetaObject::connectSlotsByName(infoDialog);
    } // setupUi

    void retranslateUi(QDialog *infoDialog)
    {
        infoDialog->setWindowTitle(QApplication::translate("infoDialog", "Info about the file", 0));
        fileGroupBox->setTitle(QApplication::translate("infoDialog", "File info:", 0));
        label_3->setText(QApplication::translate("infoDialog", "File size:", 0));
        label_2->setText(QApplication::translate("infoDialog", "File created:", 0));
        label_4->setText(QApplication::translate("infoDialog", "File touched:", 0));
        filesize->setText(QString());
        created->setText(QString());
        touched->setText(QString());
        headerGroupBox->setTitle(QApplication::translate("infoDialog", "Wave Header:", 0));
        label_9->setText(QApplication::translate("infoDialog", "File Type:", 0));
        label_10->setText(QApplication::translate("infoDialog", "File Size:", 0));
        label_11->setText(QApplication::translate("infoDialog", "WAV marker:", 0));
        label_12->setText(QApplication::translate("infoDialog", "Format Name:", 0));
        label_13->setText(QApplication::translate("infoDialog", "Format Length:", 0));
        label_14->setText(QApplication::translate("infoDialog", "Format Type:", 0));
        label_15->setText(QApplication::translate("infoDialog", "Number of Channels:", 0));
        label_16->setText(QApplication::translate("infoDialog", "Sample Rate:", 0));
        label_17->setText(QApplication::translate("infoDialog", "Byte Rate:", 0));
        label_18->setText(QApplication::translate("infoDialog", "Block Align:", 0));
        label_19->setText(QApplication::translate("infoDialog", "Bits per Sample:", 0));
        fileType->setText(QString());
        size->setText(QString());
        marker->setText(QString());
        name->setText(QString());
        flength->setText(QString());
        ftype->setText(QString());
        nChannels->setText(QString());
        srate->setText(QString());
        brate->setText(QString());
        balign->setText(QString());
        bitspersample->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class infoDialog: public Ui_infoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
