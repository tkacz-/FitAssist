#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QtSql>
#include <QTableView>

#include "aboutDialog.h"
#include "profile.h"

namespace Ui {
class FitnessCalc;
}

class FitnessCalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit FitnessCalc(QWidget *parent = 0);
    ~FitnessCalc();

signals:
    void sendPFC(double protein, double fat, double carbonhydrate);

public slots:
    void readProfile();
    void showAdvices();
    void setProfile();

    void getPFC(double protein, double fat, double carbonhydrate);

private:
    Ui::FitnessCalc *ui;
    const QString fileName = "profile/profile.dat";

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel model;
    Profile profile;
};

#endif // FITNESSCALC_H
