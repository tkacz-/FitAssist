#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class infoDialog;
}

class infoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit infoDialog(QWidget *parent = 0);
    ~infoDialog();

public slots:
    void receiveData(QVector <QString> v);

private:
    Ui::infoDialog *ui;
};

#endif // INFODIALOG_H
