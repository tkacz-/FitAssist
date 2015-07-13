#include "infoDialog.h"
#include "ui_infoDialog.h"

infoDialog::infoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoDialog)
{
    ui->setupUi(this);
}

infoDialog::~infoDialog()
{
    delete ui;
}

void infoDialog::receiveData(QVector <QString> v)
{
    QString* str = v.data();
    ui->fileType->setText(str[0]);
    ui->size->setText(str[1]);
    ui->marker->setText(str[2]);
    ui->name->setText(str[3]);
    ui->flength->setText(str[4]);
    ui->ftype->setText(str[5]);
    ui->nChannels->setText(str[6]);
    ui->srate->setText(str[7]);
    ui->brate->setText(str[8]);
    ui->balign->setText(str[9]);
    ui->bitspersample->setText(str[10]);
    ui->created->setText(str[11]);
    ui->touched->setText(str[12]);
    ui->filesize->setText(str[13]);
}
