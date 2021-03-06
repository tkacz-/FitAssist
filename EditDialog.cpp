#include "EditDialog.h"
#include "ui_EditDialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::showEdit(const QModelIndex &index)
{
    this->index = index;
    int row = index.row();
    QModelIndex myIndex = model->index(row, 0, QModelIndex());
    QVariant myData = model->data(myIndex, Qt::DisplayRole);

    ui->labelName->setText(myData.toString());

    myIndex = model->index(row, 1, QModelIndex());
    myData = model->data(myIndex, Qt::DisplayRole);
    ui->spinBoxWeight->setValue(myData.toInt());
    this->weight = myData.toInt();

    double res;
    myIndex = model->index(row, 2, QModelIndex());
    myData = model->data(myIndex, Qt::DisplayRole);
    res = std::floor(myData.toDouble() * 1000 + 0.5) / 1000;
    ui->labelProtein->setText(QString::number(res));
    this->protein = myData.toDouble();

    myIndex = model->index(row, 3, QModelIndex());
    myData = model->data(myIndex, Qt::DisplayRole);
    res = std::floor(myData.toDouble() * 1000 + 0.5) / 1000;
    ui->labelFat->setText(QString::number(res));
    this->fat = myData.toDouble();

    myIndex = model->index(row, 4, QModelIndex());
    myData = model->data(myIndex, Qt::DisplayRole);
    res = std::floor(myData.toDouble() * 1000 + 0.5) / 1000;
    ui->labelCarbonhydrate->setText(QString::number(res));
    this->carbohydrate = myData.toDouble();

    myIndex = model->index(row, 5, QModelIndex());
    myData = model->data(myIndex, Qt::DisplayRole);
    ui->labelCalorie->setText(myData.toString());
    this->calorie = myData.toDouble();

    show();

    connect(ui->spinBoxWeight, SIGNAL(valueChanged(int)), this, SLOT(weightChanged(int)));
}

void EditDialog::getModel(QSqlTableModel *model)
{
    this->model = model;
}

void EditDialog::weightChanged(int value)
{
    double protein = value * this->protein / this->weight;
    double fat = value * this->fat / this->weight;
    double carbohydrate = value * this->carbohydrate / this->weight;
    int calorie = value* this->calorie / this->weight;

    ui->labelProtein->setText(QString::number(protein));
    ui->labelFat->setText(QString::number(fat));
    ui->labelCarbonhydrate->setText(QString::number(carbohydrate));
    ui->labelCalorie->setText(QString::number(calorie));
}

void EditDialog::accept()
{
    QString name = ui->labelName->text();
    int weight = ui->spinBoxWeight->value();
    double protein = ui->labelProtein->text().toDouble();
    double fat = ui->labelFat->text().toDouble();
    double carbohydrate = ui->labelCarbonhydrate->text().toDouble();
    int calorie = ui->labelCalorie->text().toInt();

    QSqlRecord record = model->record(index.row());
    record.setValue(tr("Наименование"), name);
    record.setValue(tr("Вес"), weight);
    record.setValue(tr("Белки"), protein);
    record.setValue(tr("Жиры"), fat);
    record.setValue(tr("Углеводы"), carbohydrate);
    record.setValue(tr("Ккал"), calorie);

    model->setRecord(index.row(), record);

    emit sendUpdateFlag(true);
    close();
}
