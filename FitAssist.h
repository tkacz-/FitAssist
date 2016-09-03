#ifndef FITASSIST_H
#define FITASSIST_H

#include <QMainWindow>

#include <QListWidgetItem>
#include <QMessageBox>
#include <QTableView>
#include <QDateTime>

#include <QFile>
#include <QDir>
#include <QtSql>

#include "AboutDialog.h"
#include "AddDialog.h"
#include "EditDialog.h"
#include "EditListDialog.h"
#include "Profile.h"

namespace Ui {
class FitAssist;
}

/*!
 * \brief Class for main window of app.
 *
 * This class manages the all features of app.
 * A list of features:
 *  -
 *
 * \author tkaczenko (Andrii Tkachenko)
 * \warning Need to refector
 */
class FitAssist : public QMainWindow
{
    Q_OBJECT

public:
    /// Create an FitnessCalc extends QMainWindow
    explicit FitAssist(QWidget *parent = 0);
    ~FitAssist();

signals:
    /*!
     * \brief Send info about the eaten number of proteins, fats and carbohydrates
     * \param[in] protein       Number of eaten proteins
     * \param[in] fat           Number of eaten fats
     * \param[in] carbohydrate  Number of carbohydrate
     */
    void sendPFC(double protein, double fat, double carbohydrate);

    /*!
     * \brief Send pointer to model for changing data.
     * \param[in] model QSqlTableModel of the current data table of data source
     */
    void sendModel(QSqlTableModel *model);

public slots:
    /*!
     * \brief Read Profile from UI and write serialized Profile into a file
     * \see Profile
     */
    void setProfile();

    /*!
     * \brief Get the percentages of the eaten proteins, fats, carbohydrates from PieChart
     * \param[in] protein       percentage of the eaten proteins
     * \param[in] fat           percentage of the eaten fats
     * \param[in] carbonhydrate percentage of the eaten carbohydrates
     * \see PieChart
     */
    void getPFC(double protein, double fat, double carbonhydrate);

    /*!
     * \brief Update QSqlTableModel
     * \param[in] update    \code{.cpp} true \endcode - if you want to update the \a model,
     *                  \code{.cpp} false \endcode - if you don't want to update the \a model
     */
    void setUpdateFlag(bool update);

    /*!
     * \brief Edit data of the eaten product from \a model
     * \param[in,out] index Index of the clicked row of the table model
     */
    void doubleClickedEdit(const QModelIndex &index);

    void deleteRowFromMyDiet();
    void removeAllRows();

    /*!
     * \brief Show the personal list of products
     */
    void clickedOnEditList();

    void clickedOnAboutDialog();

    /*!
     * \brief Show the AddDialog to add the product to MyDiet
     */
    void clickedOnAddDialog();

    void showAdvices();
    void maleReactToToggle(bool checked);

private:
    /// Read Profile from file
    bool readProfile();
    /// Write Profile into file
    void writeProfile();
    /// Show the all norms in UI
    void showNorms();
    /// Read \a model from \a dbase
    void readMyDiet();
    /// Show the all eaten proteins, fats and carbohydrates
    void showTotal();

private:
    Ui::FitAssist *ui;                                          /*!< Pointer to UI */

    const QString fileName = "profile/profile.dat";             /*!< Path to save Profile */

    QSqlDatabase dbase = QSqlDatabase::addDatabase("QSQLITE");  /*!< Init driver for the database */
    QSqlTableModel *model = new QSqlTableModel();               /*!< Model of data table from database */
    Profile *profile = new Profile();                           /*!< User's Profile */
};

#endif // FITASSIST_H
