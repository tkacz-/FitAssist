#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = 0);
    ~EditDialog();

signals:
    void sendUpdateFlag(bool update);

public slots:
    void showEdit(const QModelIndex &index);
    void getModel(QSqlTableModel *model);
    void weightChanged(int value);
    void accept();

private:
    Ui::EditDialog *ui;

    QSqlTableModel *model;
    QModelIndex index;
    int weight;
    double protein;
    double fat;
    double carbonhydrate;
    double calorie;
};

#endif // EDITDIALOG_H
