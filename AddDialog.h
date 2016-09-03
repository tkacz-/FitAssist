#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();

signals:
    void sendUpdateFlag(bool update);

public slots:
    void accept();
    void search();

private:
    void addToBaseOfMyDiet();
    void addToBaseOfProduct();

private:
    Ui::AddDialog *ui;

    QSqlDatabase dbase;
    QSqlQueryModel *model = nullptr;

    QString categories[16];
};

#endif // ADDDIALOG_H
