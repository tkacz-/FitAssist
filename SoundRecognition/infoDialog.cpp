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

void infoDialog::receiveData(QString str)
{
    ui->size->setText(str);
}
