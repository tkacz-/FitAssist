#include "FitnessCalc.h"
#include "ui_FitnessCalc.h"

FitnessCalc::FitnessCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitnessCalc)
{
    ui->setupUi(this);
    ui->labelLogo->setPixmap(QIcon(":logo/images/logo.ico").pixmap(64,64));

    //Click on menu
    connect(ui->listWidgetMenu, &QListWidget::currentRowChanged,  ui->stackedWidget,  &QStackedWidget::setCurrentIndex);

    //Click on advice button
    connect(ui->commandLinkButton, &QCommandLinkButton::clicked, this, &FitnessCalc::showAdvices);

    //Click on about button
    aboutDialog* about = new aboutDialog();
    connect(ui->commandLinkButton_2, &QCommandLinkButton::clicked, about, &QDialog::show);

    //Click on apply button
    connect(ui->pushButtonApply, &QPushButton::clicked, this, &FitnessCalc::setProfile);
}

FitnessCalc::~FitnessCalc()
{
    delete ui;
}

void FitnessCalc::showAdvices()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void FitnessCalc::setProfile()
{
    if (!ui->radioButtonMale->isChecked() && !ui->radioButtonFemale->isChecked())
        QMessageBox::critical(this, tr("Ошибка"), tr("Пожалуйста, выберите Ваш пол."));
    else
    {
        float weight = ui->doubleSpinBoxWeight->value();
        short height = ui->spinBoxHeight->value();
        short age = ui->spinBoxAge->value();
        float activity;
        switch (ui->comboBoxActivity->currentIndex()) {
        case 0:
            activity = 1.1;
            break;
        case 1:
            activity = 1.2;
            break;
        case 2:
            activity = 1.3;
            break;
        case 3:
            activity = 1.4;
            break;
        case 4:
            activity = 1.5;
            break;
        }
        QString gender;
        if (ui->radioButtonMale->isChecked())
            gender = "male";
        else
            gender = "female";
        Profile profile(weight, height, age, gender, activity);
        profile.calculateNorms();
        ui->labelBMI->setText(QString::number(profile.getBMI()));
        ui->labelConformity->setText(profile.getConclusion());
        QString res = QString::number(profile.getOptimalWeightMin()) + " - " + QString::number(profile.getOptimalWeightMax());
        ui->labelOptimalWeight->setText(res);
        ui->labelCalorieNorm->setText(QString::number(profile.getBMR()));
        ui->labelWaterNorm->setText(QString::number(profile.getWater()));
    }
}
