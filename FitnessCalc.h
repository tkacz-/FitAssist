#ifndef FITNESSCALC_H
#define FITNESSCALC_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QMessageBox>

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

public slots:
    void showAdvices();

    void setProfile();

private:
    Ui::FitnessCalc *ui;
};

#endif // FITNESSCALC_H
