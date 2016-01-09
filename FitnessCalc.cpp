#include "FitnessCalc.h"
#include "ui_FitnessCalc.h"

FitnessCalc::FitnessCalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitnessCalc)
{
    ui->setupUi(this);
    ui->labelLogo->setPixmap(QIcon(":logo/images/logo.ico").pixmap(64,64));

    dbase.setDatabaseName(QDir::currentPath() + "/base.sqlite");
    dbase.open();

    model.setTable("Продукты");
    model.setEditStrategy(QSqlTableModel::OnFieldChange);
    model.select();

    double protein = 0, fat = 0, carbonhydrate = 0, calorie = 0;
    for (int i = 0; i < model.rowCount(); i++) {
        protein += model.record(i).value("Белки").toDouble();
        fat += model.record(i).value("Жиры").toDouble();
        carbonhydrate += model.record(i).value("Углеводы").toDouble();
        calorie += model.record(i).value("Ккал").toDouble();
    }

    /*
    QSqlRecord record = model.record();
    record.setValue(0,QVariant(tr("ИТОГ")));
    record.setValue(1,QVariant(protein));
    record.setValue(2,QVariant(fat));
    record.setValue(3,QVariant(carbohydrate));
    record.setValue(4,QVariant(calorie));

    model.insertRecord(model.rowCount(), record);
    */

    ui->tableView->setModel(&model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lblProtein_Conclusion->setText(QString::number(protein));
    ui->lblFat_Conclusion->setText(QString::number(fat));
    ui->lblCarbohydrate_Conlusion->setText(QString::number(carbonhydrate));
    ui->lblCalorie_Conclusion->setText(QString::number(calorie));
    ui->labelRecieved->setText(QString::number(calorie));

    connect(this, &FitnessCalc::sendPFC, ui->widget, &PieChart::getPFC);
    connect(ui->widget, &PieChart::sendPFC, this, &FitnessCalc::getPFC);
    emit sendPFC(protein, fat, carbonhydrate);

    QPixmap pixmap(30,15);
    pixmap.fill(QColor("#5DA5DA"));
    ui->lblDrawProtein->setPixmap(pixmap);

    pixmap.fill(QColor("#FAA43A"));
    ui->lblDrawFat->setPixmap(pixmap);

    pixmap.fill(QColor("#B276B2"));
    ui->lblDrawCarbohydrate->setPixmap(pixmap);

    readProfile();

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

void FitnessCalc::readProfile()
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_5_5);

        in >> profile;

        file.close();

        if (profile.getGender() == "male") {
            ui->radioButtonMale->setChecked(true);
            ui->labelImage->setPixmap(QPixmap(":man&woman/images/man.png"));
        }
        else {
            ui->radioButtonFemale->setChecked(true);
            ui->labelImage->setPixmap(QPixmap(":man&woman/images/woman.png"));
        }
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

        ui->labelBMI->setText(QString::number(profile.getBMI(),'g',3));
        ui->labelConformity->setText(profile.getConclusion());
        QString res = QString::number(profile.getOptimalWeightMin(),'g',3) + " - " + QString::number(profile.getOptimalWeightMax(),'g',4);
        ui->labelOptimalWeight->setText(res);
        ui->labelCalorieNorm->setText(QString::number(profile.getBMR(),'g',4));
        ui->labelWaterNorm->setText(QString::number(profile.getWater(),'g',3));
    }
}

void FitnessCalc::getPFC(double protein, double fat, double carbonhydrate)
{
    ui->lblProtein->setText(QString::number(protein, 'g', 3) + " %");
    ui->lblFat->setText(QString::number(fat, 'g', 3) + " %");
    ui->lblCarbohydrate->setText(QString::number(carbonhydrate, 'g', 3) + " %");
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

        ui->labelBMI->setText(QString::number(profile.getBMI(),'g',3));
        ui->labelConformity->setText(profile.getConclusion());
        QString res = QString::number(profile.getOptimalWeightMin(),'g',3) + " - " + QString::number(profile.getOptimalWeightMax(),'g',4);
        ui->labelOptimalWeight->setText(res);
        ui->labelCalorieNorm->setText(QString::number(profile.getBMR(),'g',4));
        ui->labelWaterNorm->setText(QString::number(profile.getWater(),'g',3));
    }
}
