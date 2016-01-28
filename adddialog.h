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

    QSqlDatabase dbase;
    QSqlQueryModel *model = nullptr;

    QString categories[16];
};

#endif // ADDDIALOG_H
