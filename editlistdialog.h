#ifndef EDITLISTDIALOG_H
#define EDITLISTDIALOG_H

#include <QDialog>
#include <QDir>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class EditListDialog;
}

class EditListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditListDialog(QWidget *parent = 0);
    ~EditListDialog();

public slots:
    void getCategorie(int index);
    void deleteRow();
    void removeAllRows();

private:
    Ui::EditListDialog *ui;

    QSqlDatabase *dbase;
    QSqlTableModel *model;
};

#endif // EDITLISTDIALOG_H
