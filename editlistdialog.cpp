#include "editlistdialog.h"
#include "ui_editlistdialog.h"

EditListDialog::EditListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditListDialog)
{
    ui->setupUi(this);

    dbase.setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
    dbase.open();

    model = new QSqlTableModel;
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

    connect(ui->comboBoxCategorie, SIGNAL(currentIndexChanged(int)), this, SLOT(getCategorie(int)));
    connect(ui->pushButtonDel, &QAbstractButton::clicked, this, &EditListDialog::deleteRow);
    connect(ui->pushButtonClean, &QAbstractButton::clicked, this, &EditListDialog::removeAllRows);
}

EditListDialog::~EditListDialog()
{
    delete ui;

    dbase.close();
    delete model;
}

void EditListDialog::getCategorie(int index)
{
    QString categories[16] = { tr("Алкогольные_напитки"),
                                  tr("Вода_соки_и_безалкогольные_напитки"),
                                  tr("Грибы"),
                                  tr("Жиры_растительные_и_животные"),
                                  tr("Кондитерские_изделия"),
                                  tr("Крупы_злаки_и_зернобобовые"),
                                  tr("Молоко_и_молочные_продукты"),
                                  tr("Мука_крахмал_и_макаронные_изделия"),
                                  tr("Мясо_птица_и_мясные_продукты"),
                                  tr("Овощи_и_зелень"),
                                  tr("Орехи_и_семена"),
                                  tr("Рыба_и_морепродукты"),
                                  tr("Специи_приправы_и_соусы"),
                                  tr("Фрукты_и_ягоды"),
                                  tr("Хлеб_и_хлебобулочные_изделия"),
                                  tr("Яйца_и_продукты_из_них") };

    model->setTable(categories[index]);
    model->select();
}

void EditListDialog::deleteRow()
{
    model->removeRow(ui->tableView->currentIndex().row());
    model->select();
}

void EditListDialog::removeAllRows()
{
    for (int i = 0; i < model->rowCount(); i++)
        model->removeRow(i);
    model->select();
}
