#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    connect(ui->pushButtonSearch, &QAbstractButton::clicked, this, &addDialog::search);
}

addDialog::~addDialog()
{
    delete ui;
}

void addDialog::accept()
{
    if (ui->comboBox->currentIndex() == 0) {
        if (ui->tableView->currentIndex().row() == -1)
            QMessageBox::critical(this, "FitnessCalc", tr("Пожалуйста, выполните поиск или выберите строку из таблицы результатов."));
        else
            addToBaseOfMyDiet();
    } else {
        addToBaseOfProduct();
    }
}

void addDialog::search()
{
    QString name = ui->lineEditSearch->text();
    name[0] = name[0].toUpper();

    int index = ui->comboBoxMyCategorie->currentIndex();

    if (!QDir("base").exists())
        QDir().mkdir("base");



    if (ui->radioButtonBase->isChecked()) {
        QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(QDir::currentPath() + "/base/base.sqlite");
        dbase.open();

        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM " + categories[index] + " WHERE Наименование LIKE '%" + name + "%'");

        ui->tableView->setModel(model);
    } else {
        QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
        dbase.open();

        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT * FROM " + categories[index] + " WHERE Наименование LIKE '%" + name + "%'");
        ui->tableView->setModel(model);
    }
}

void addDialog::addToBaseOfMyDiet()
{
    int weight = ui->spinBoxWeight->value();

    int row = ui->tableView->currentIndex().row();

    QVariant myData;
    QModelIndex myIndex;

    myIndex = ui->tableView->model()->index(row, 0, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
    QString name = myData.toString();

    myIndex = ui->tableView->model()->index(row, 1, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
    double protein = weight * myData.toDouble() / 100;

    myIndex = ui->tableView->model()->index(row, 2, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
    double fat = weight * myData.toDouble() / 100;

    myIndex = ui->tableView->model()->index(row, 3, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
    double carbonhydrate = weight * myData.toDouble() / 100;

    myIndex = ui->tableView->model()->index(row, 4, QModelIndex());
    myData = ui->tableView->model()->data(myIndex, Qt::DisplayRole);
    int calorie = weight * myData.toInt() / 100;

    if (!QDir("base").exists())
        QDir().mkdir("base");

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(QDir::currentPath() + "/base/MyDiet.sqlite");
    dbase.open();

    QSqlQuery query;
    QString str;
    QString strInsert = "INSERT INTO Рацион (Наименование,Вес,Белки,Жиры,Углеводы,Ккал)"
                        "VALUES ('%1', %2, %3, %4, %5, %6);";

    str = strInsert.arg(name)
            .arg(QString::number(weight))
            .arg(QString::number(protein))
            .arg(QString::number(fat))
            .arg(QString::number(carbonhydrate))
            .arg(QString::number(calorie));
    query.exec(str);

    ui->lineEditSearch->clear();
    ui->spinBoxWeight->clear();

    emit sendUpdateFlag(true);
}

void addDialog::addToBaseOfProduct()
{    
    QString name = ui->lineEditName->text();
    double protein = ui->doubleSpinBoxProtein->value();
    double fat = ui->doubleSpinBoxFat->value();
    double carbonhydrate = ui->doubleSpinBoxCarbonhydrate->value();
    int calorie = ui->spinBoxCalorie->value();

    int index = ui->comboBoxCategorie->currentIndex();

    if (!QDir("base").exists())
        QDir().mkdir("base");

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
    dbase.open();

    QSqlQuery query;
    QString str = "CREATE TABLE " + categories[index] + " ("
                  "Наименование text, "
                  "Белки double, "
                  "Жиры double, "
                  "Углеводы double, "
                  "Ккал integer"
                  ");";
    query.exec(str);

    QString strInsert = "INSERT INTO " + categories[index] + " (Наименование,Белки,Жиры,Углеводы,Ккал)"
                        "VALUES ('%1', %2, %3, %4, %5);";

    str = strInsert.arg(name)
            .arg(QString::number(protein))
            .arg(QString::number(fat))
            .arg(QString::number(carbonhydrate))
            .arg(QString::number(calorie));
    query.exec(str);

    ui->lineEditName->clear();
    ui->doubleSpinBoxProtein->clear();
    ui->doubleSpinBoxFat->clear();
    ui->doubleSpinBoxCarbonhydrate->clear();
    ui->spinBoxCalorie->clear();
}
