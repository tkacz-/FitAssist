#include "FitnessCalc.h"
#include "ui_FitnessCalc.h"

FitnessCalc::FitnessCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitnessCalc)
{
    ui->setupUi(this);
    ui->labelLogo->setPixmap(QIcon(":logo/images/logo.ico").pixmap(64,64));

    QPixmap pixmap(30,15);
    pixmap.fill(QColor("#5DA5DA"));
    ui->lblDrawProtein->setPixmap(pixmap);

    pixmap.fill(QColor("#FAA43A"));
    ui->lblDrawFat->setPixmap(pixmap);

    pixmap.fill(QColor("#B276B2"));
    ui->lblDrawCarbohydrate->setPixmap(pixmap);

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_5);

        in >> profile;

        file.close();

        if (profile.getGender() == "male")
            ui->radioButtonMale->setChecked(true);
        else
            ui->radioButtonFemale->setChecked(true);
        ui->doubleSpinBoxWeight->setValue(profile.getWeigth());
        ui->spinBoxHeight->setValue(profile.getHeigth());
        ui->spinBoxAge->setValue(profile.getAge());
        float activity = profile.getActivity();
        if (activity == 1.1)
            ui->comboBoxActivity->setCurrentIndex(4);
        else if (activity == 1.2)
            ui->comboBoxActivity->setCurrentIndex(3);
        else if (activity == 1.3)
            ui->comboBoxActivity->setCurrentIndex(2);
        else if (activity == 1.4)
            ui->comboBoxActivity->setCurrentIndex(1);
        else
            ui->comboBoxActivity->setCurrentIndex(0);

        ui->labelBMI->setText(QString::number(profile.getBMI(),'g',5));
        ui->labelConformity->setText(profile.getConclusion());
        QString res = QString::number(profile.getOptimalWeightMin(),'g',5) + " - " + QString::number(profile.getOptimalWeightMax(),'g',5);
        ui->labelOptimalWeight->setText(res);
        ui->labelCalorieNorm->setText(QString::number(profile.getBMR(),'g',5));
        ui->labelWaterNorm->setText(QString::number(profile.getWater(),'g',5));
    }

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
                activity = 1.5;
                break;
            case 1:
                activity = 1.4;
                break;
            case 2:
                activity = 1.3;
                break;
            case 3:
                activity = 1.2;
                break;
            case 4:
                activity = 1.1;
                break;
        }
        QString gender;
        if (ui->radioButtonMale->isChecked())
            gender = "male";
        else
            gender = "female";

        profile.setWeigth(weight);
        profile.setHeigth(height);
        profile.setAge(age);
        profile.setGender(gender);
        profile.setActivity(activity);
        profile.calculateNorms();

        if (!QDir("profile").exists())
            QDir().mkdir("profile");

        QFile file(fileName);
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_5_5);

        if(file.open(QIODevice::WriteOnly))
            out << profile;

        file.flush();
        file.close();

        ui->labelBMI->setText(QString::number(profile.getBMI(),'g',5));
        ui->labelConformity->setText(profile.getConclusion());
        QString res = QString::number(profile.getOptimalWeightMin(),'g',5) + " - " + QString::number(profile.getOptimalWeightMax(),'g',5);
        ui->labelOptimalWeight->setText(res);
        ui->labelCalorieNorm->setText(QString::number(profile.getBMR(),'g',5));
        ui->labelWaterNorm->setText(QString::number(profile.getWater(),'g',5));
    }
}
