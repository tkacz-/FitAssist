#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = 0);
    ~addDialog();

signals:
    void sendUpdateFlag(bool update);

public slots:
    void accept();
    void search();

private:
    void addToBaseOfMyDiet();
    void addToBaseOfProduct();

private:
    Ui::addDialog *ui;

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
};

#endif // ADDDIALOG_H
