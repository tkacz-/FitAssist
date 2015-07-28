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
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master

    void setupUi(QDialog *infoDialog)
    {
        if (infoDialog->objectName().isEmpty())
            infoDialog->setObjectName(QStringLiteral("infoDialog"));
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

<<<<<<< HEAD
        label_4 = new QLabel(fileGroupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);
=======
        label_3 = new QLabel(infoGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);
>>>>>>> origin/master


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
<<<<<<< HEAD
        filesize = new QLabel(fileGroupBox);
        filesize->setObjectName(QStringLiteral("filesize"));

        verticalLayout_2->addWidget(filesize);

        created = new QLabel(fileGroupBox);
        created->setObjectName(QStringLiteral("created"));

        verticalLayout_2->addWidget(created);

        touched = new QLabel(fileGroupBox);
=======
        fileSize = new QLabel(infoGroupBox);
        fileSize->setObjectName(QStringLiteral("fileSize"));

        verticalLayout_2->addWidget(fileSize);

        touched = new QLabel(infoGroupBox);
>>>>>>> origin/master
        touched->setObjectName(QStringLiteral("touched"));

        verticalLayout_2->addWidget(touched);

<<<<<<< HEAD
=======
        created = new QLabel(infoGroupBox);
        created->setObjectName(QStringLiteral("created"));

        verticalLayout_2->addWidget(created);

>>>>>>> origin/master

        horizontalLayout->addLayout(verticalLayout_2);


<<<<<<< HEAD
        gridLayout->addWidget(fileGroupBox, 0, 0, 1, 1);
=======
        gridLayout->addWidget(infoGroupBox, 0, 0, 1, 1);
>>>>>>> origin/master

        headerGroupBox = new QGroupBox(infoDialog);
        headerGroupBox->setObjectName(QStringLiteral("headerGroupBox"));
        horizontalLayout_2 = new QHBoxLayout(headerGroupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
<<<<<<< HEAD
=======
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

>>>>>>> origin/master
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

<<<<<<< HEAD
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

=======
>>>>>>> origin/master

        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        fileType = new QLabel(headerGroupBox);
        fileType->setObjectName(QStringLiteral("fileType"));

        verticalLayout_4->addWidget(fileType);

<<<<<<< HEAD
        size = new QLabel(headerGroupBox);
        size->setObjectName(QStringLiteral("size"));

        verticalLayout_4->addWidget(size);
=======
        fileSize_2 = new QLabel(headerGroupBox);
        fileSize_2->setObjectName(QStringLiteral("fileSize_2"));

        verticalLayout_4->addWidget(fileSize_2);
>>>>>>> origin/master

        marker = new QLabel(headerGroupBox);
        marker->setObjectName(QStringLiteral("marker"));

        verticalLayout_4->addWidget(marker);

<<<<<<< HEAD
        name = new QLabel(headerGroupBox);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout_4->addWidget(name);

        flength = new QLabel(headerGroupBox);
        flength->setObjectName(QStringLiteral("flength"));

        verticalLayout_4->addWidget(flength);

        ftype = new QLabel(headerGroupBox);
        ftype->setObjectName(QStringLiteral("ftype"));

        verticalLayout_4->addWidget(ftype);
=======
        formatName = new QLabel(headerGroupBox);
        formatName->setObjectName(QStringLiteral("formatName"));

        verticalLayout_4->addWidget(formatName);

        formatLenght = new QLabel(headerGroupBox);
        formatLenght->setObjectName(QStringLiteral("formatLenght"));

        verticalLayout_4->addWidget(formatLenght);

        formatType = new QLabel(headerGroupBox);
        formatType->setObjectName(QStringLiteral("formatType"));

        verticalLayout_4->addWidget(formatType);
>>>>>>> origin/master

        nChannels = new QLabel(headerGroupBox);
        nChannels->setObjectName(QStringLiteral("nChannels"));

        verticalLayout_4->addWidget(nChannels);

<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addWidget(headerGroupBox, 1, 0, 1, 1);


        retranslateUi(infoDialog);

        QMetaObject::connectSlotsByName(infoDialog);
    } // setupUi

    void retranslateUi(QDialog *infoDialog)
    {
<<<<<<< HEAD
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
=======
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
>>>>>>> origin/master
    } // retranslateUi

};

namespace Ui {
    class infoDialog: public Ui_infoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFODIALOG_H
