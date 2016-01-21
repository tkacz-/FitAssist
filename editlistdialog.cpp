#include "editlistdialog.h"
#include "ui_editlistdialog.h"

EditListDialog::EditListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditListDialog)
{
    ui->setupUi(this);
    connect(ui->comboBoxCategorie, SIGNAL(currentIndexChanged(int)), this, SLOT(getCategorie(int)));
    connect(ui->pushButtonDel, &QAbstractButton::clicked, this, &EditListDialog::deleteRow);
    connect(ui->pushButtonClean, &QAbstractButton::clicked, this, &EditListDialog::removeAllRows);
}

EditListDialog::~EditListDialog()
{
    delete ui;
    delete model;
}

void EditListDialog::getCategorie(int index)
{
    QString categories[16] = { "Алкогольные_напитки",
                                  "Вода_соки_и_безалкогольные_напитки",
                                  "Грибы",
                                  "Жиры_растительные_и_животные",
                                  "Кондитерские_изделия",
                                  "Крупы_злаки_и_зернобобовые",
                                  "Молоко_и_молочные_продукты",
                                  "Мука_крахмал_и_макаронные_изделия",
                                  "Мясо_птица_и_мясные_продукты",
                                  "Овощи_и_зелень",
                                  "Орехи_и_семена",
                                  "Рыба_и_морепродукты",
                                  "Специи_приправы_и_соусы",
                                  "Фрукты_и_ягоды",
                                  "Хлеб_и_хлебобулочные_изделия",
                                  "Яйца_и_продукты_из_них" };

    QSqlDatabase *dbase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
    dbase->setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
    dbase->open();

    QSqlQuery query;
    QString str = "CREATE TABLE " + categories[index] + " ("
                  "Наименование text, "
                  "Белки double, "
                  "Жиры double, "
                  "Углеводы double, "
                  "Ккал integer"
                  ");";
    query.exec(str);

    delete model;
    model = nullptr;

    model = new QSqlTableModel;
    model->setTable(categories[index]);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

    delete dbase;
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
