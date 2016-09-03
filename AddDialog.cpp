#include "AddDialog.h"
#include "ui_AddDialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    categories[0] = tr("Алкогольные_напитки");
    categories[1] = tr("Вода_соки_и_безалкогольные_напитки");
    categories[2] = tr("Грибы");
    categories[3] = tr("Жиры_растительные_и_животные");
    categories[4] = tr("Кондитерские_изделия");
    categories[5] = tr("Крупы_злаки_и_зернобобовые");
    categories[6] = tr("Молоко_и_молочные_продукты");
    categories[7] = tr("Мука_крахмал_и_макаронные_изделия");
    categories[8] = tr("Мясо_птица_и_мясные_продукты");
    categories[9] = tr("Овощи_и_зелень");
    categories[10] = tr("Орехи_и_семена");
    categories[11] = tr("Рыба_и_морепродукты");
    categories[12] = tr("Специи_приправы_и_соусы");
    categories[13] = tr("Фрукты_и_ягоды");
    categories[14] = tr("Хлеб_и_хлебобулочные_изделия");
    categories[15] = tr("Яйца_и_продукты_из_них");

    connect(ui->pushButtonSearch, &QAbstractButton::clicked, this, &AddDialog::search);
}

AddDialog::~AddDialog()
{
    delete ui;

    if (dbase.isOpen())
        dbase.close();
    delete model;
}

void AddDialog::accept()
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

void AddDialog::search()
{
    QString name = ui->lineEditSearch->text();
    name[0] = name[0].toUpper();

    int index = ui->comboBoxMyCategorie->currentIndex();

    if (!QDir("base").exists())
        QDir().mkdir("base");

    if (ui->radioButtonBase->isChecked()) {
        dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(QDir::currentPath() + "/base/base.sqlite");
        dbase.open();
    } else {
        dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
        dbase.open();
    }

    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM " + categories[index] + " WHERE " + tr("Наименование") + " LIKE '%" + name + "%'");
    ui->tableView->setModel(model);
}

void AddDialog::addToBaseOfMyDiet()
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

    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(QDir::currentPath() + "/base/MyDiet.sqlite");
    dbase.open();

    QSqlQuery query;
    QString str;
    QString strInsert = "INSERT INTO " + tr("Рацион") + " ("
            + tr("Наименование") + ","
            + tr("Вес") + ","
            + tr("Белки") + ","
            + tr("Жиры") + ","
            + tr("Углеводы") + ","
            + tr("Ккал") + ")"
            "VALUES ('%1', %2, %3, %4, %5, %6);";

    str = strInsert.arg(name)
            .arg(QString::number(weight))
            .arg(QString::number(protein))
            .arg(QString::number(fat))
            .arg(QString::number(carbonhydrate))
            .arg(QString::number(calorie));
    query.exec(str);

    dbase.close();

    ui->lineEditSearch->clear();
    ui->spinBoxWeight->clear();

    emit sendUpdateFlag(true);
}

void AddDialog::addToBaseOfProduct()
{    
    QString name = ui->lineEditName->text();
    double protein = ui->doubleSpinBoxProtein->value();
    double fat = ui->doubleSpinBoxFat->value();
    double carbonhydrate = ui->doubleSpinBoxCarbonhydrate->value();
    int calorie = ui->spinBoxCalorie->value();

    int index = ui->comboBoxCategorie->currentIndex();

    if (!QDir("base").exists())
        QDir().mkdir("base");

    dbase = QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName(QDir::currentPath() + "/base/MyProducts.sqlite");
    dbase.open();

    QSqlQuery query;
    QString str = "CREATE TABLE " + categories[index] + " ("
                  + tr("Наименование") + " text, "
                  + tr("Белки") + " double, "
                  + tr("Жиры") + " double, "
                  + tr("Углеводы") + " double, "
                  + tr("Ккал") + " integer"
                  ");";
    query.exec(str);

    QString strInsert = "INSERT INTO " + categories[index] + " ("
            + tr("Наименование") + ","
            + tr("Белки") + ","
            + tr("Жиры") + ","
            + tr("Углеводы") + ","
            + tr("Ккал") + ")"
            "VALUES ('%1', %2, %3, %4, %5);";

    str = strInsert.arg(name)
            .arg(QString::number(protein))
            .arg(QString::number(fat))
            .arg(QString::number(carbonhydrate))
            .arg(QString::number(calorie));
    query.exec(str);

    dbase.close();
    ui->lineEditName->clear();
    ui->doubleSpinBoxProtein->clear();
    ui->doubleSpinBoxFat->clear();
    ui->doubleSpinBoxCarbonhydrate->clear();
    ui->spinBoxCalorie->clear();
}
