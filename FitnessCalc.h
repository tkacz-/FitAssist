#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include <QMainWindow>

#include <QListWidgetItem>
#include <QMessageBox>
#include <QTableView>
#include <QDateTime>

#include <QFile>
#include <QDir>
#include <QtSql>

#include "aboutDialog.h"
#include "adddialog.h"
#include "editdialog.h"
#include "editlistdialog.h"
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
    void sendModel(QSqlTableModel *model);

public slots:

    /**
     * @brief Read and write profile from UI
     */
    void setProfile();

    /**
     * @brief Get the protein, the fat and the carbonhydrate from PieChart
     * @param protein percentage of the protein
     * @param fat percentage of the fat
     * @param carbonhydrate percentage of the carbonhydrate
     */
    void getPFC(double protein, double fat, double carbonhydrate);

    void getUpdateFlag(bool update);
    void doubleClickedEdit(const QModelIndex &index);
    void deleteRowFromMyDiet();
    void removeAllRows();

    void clickedOnEditList();
    void clickedOnAboutDialog();
    void clickedOnAddDialog();

    void showAdvices();
    void maleReactToToggle(bool checked);

private:
    bool readProfile();
    void writeProfile();
    void showNorms();
    void readMyDiet();
    void showTotal();

private:
    Ui::FitnessCalc *ui;

    const QString fileName = "profile/profile.dat";

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");
    QSqlTableModel *model = new QSqlTableModel();
    Profile *profile = new Profile();
};

#endif // FITNESSCALC_H
