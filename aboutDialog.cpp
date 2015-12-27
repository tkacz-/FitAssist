#include "aboutDialog.h"
#include "ui_aboutDialog.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);

    ui->label->setPixmap(QIcon(":logo/images/logo.ico").pixmap(64,64));
}

aboutDialog::~aboutDialog()
{
    delete ui;
}
