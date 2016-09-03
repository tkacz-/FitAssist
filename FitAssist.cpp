#include "FitAssist.h"
#include "ui_FitAssist.h"

FitAssist::FitAssist(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FitAssist)
{
    ui->setupUi(this);

    ui->comboBoxActivity->setItemData(0, tr("Сидячий образ жизни, очень мало или отсутствие спортивных занятий"), Qt::ToolTipRole);
    ui->comboBoxActivity->setItemData(1, tr("Немного дневной активности + легкие упражнения 1-3 раза в неделю"), Qt::ToolTipRole);
    ui->comboBoxActivity->setItemData(2, tr("Тренировки 3-5 раз в неделю"), Qt::ToolTipRole);
    ui->comboBoxActivity->setItemData(3, tr("Активный образ жизни и тяжелые тренировки 6-7 раз в неделю"), Qt::ToolTipRole);
    ui->comboBoxActivity->setItemData(4, tr("Спортивный образ жизни, физический труд, ежедневные тренировки"), Qt::ToolTipRole);

    if (!readProfile())
        ui->labelImage->setPixmap(QPixmap(":man&woman/images/man.png"));

    readMyDiet();

    // Drawing the color rectangles on the labels
    QPixmap *pixmap = new QPixmap(30,15);
    pixmap->fill(QColor("#5DA5DA"));
    ui->lblDrawProtein->setPixmap(*pixmap);

    pixmap->fill(QColor("#FAA43A"));
    ui->lblDrawFat->setPixmap(*pixmap);

    pixmap->fill(QColor("#B276B2"));
    ui->lblDrawCarbohydrate->setPixmap(*pixmap);
    delete pixmap;

    // Click on the listWidgetMenu
    connect(ui->listWidgetMenu, &QListWidget::currentRowChanged,  ui->stackedWidget,  &QStackedWidget::setCurrentIndex);

    // Click on the commandLinkButtonAbout
    connect(ui->commandLinkButtonAbout, &QCommandLinkButton::clicked, this, &FitAssist::clickedOnAboutDialog);

    // Click on the pushButtonApply
    connect(ui->pushButtonApply, &QPushButton::clicked, this, &FitAssist::setProfile);

    // Click on the radioButtonMale && radioButtonFemale
    connect(ui->radioButtonMale, &QRadioButton::toggled, this, &FitAssist::maleReactToToggle);

    // Click on the pushButtonAdd
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &FitAssist::clickedOnAddDialog);

    // Double click on the item of tableView
    connect(ui->tableView, &QTableView::doubleClicked, this, &FitAssist::doubleClickedEdit);

    // Click on the pushButtonEdit
    connect(ui->pushButtonEdit, &QPushButton::clicked, this, &FitAssist::clickedOnEditList);

    // Click on the pushButtonDel
    connect(ui->pushButtonDel, &QPushButton::clicked, this, &FitAssist::deleteRowFromMyDiet);

    // Сlick on the pushButtonClean
    connect(ui->pushButtonClean, &QPushButton::clicked, this, &FitAssist::removeAllRows);
}

FitAssist::~FitAssist()
{
    delete ui;

    if (dbase.isOpen())
        dbase.close();
    delete model;
    delete profile;
}

void FitAssist::setProfile()
{
    float weight = ui->doubleSpinBoxWeight->value();
    short height = ui->spinBoxHeight->value();
    short age = ui->spinBoxAge->value();
    float activity;
    switch (ui->comboBoxActivity->currentIndex()) {
    case 0:
        activity = 1.2;
        break;
    case 1:
        activity = 1.375;
        break;
    case 2:
        activity = 1.55;
        break;
    case 3:
        activity = 1.725;
        break;
    case 4:
        activity = 1.9;
        break;
    }
    QString gender;
    if (ui->radioButtonMale->isChecked())
        gender = "male";
    else
        gender = "female";
    int targetCalorie = ui->spinBoxTarget->value();

    profile->setWeigth(weight);
    profile->setHeigth(height);
    profile->setAge(age);
    profile->setGender(gender);
    profile->setActivity(activity);
    profile->setCalorie(targetCalorie);
    profile->calculateNorms();

    writeProfile();
    showNorms();
}

void FitAssist::getPFC(double protein, double fat, double carbohydrate)
{
    if (protein == protein && fat == fat && carbohydrate == carbohydrate) {
        ui->lblProtein->setText(QString::number(protein, 'g', 3) + " %");
        ui->lblFat->setText(QString::number(fat, 'g', 3) + " %");
        ui->lblCarbohydrate->setText(QString::number(carbohydrate, 'g', 3) + " %");
    } else {
        ui->lblProtein->clear();
        ui->lblFat->clear();
        ui->lblCarbohydrate->clear();
    }
}

void FitAssist::setUpdateFlag(bool update)
{
    if (update) {
        dbase = QSqlDatabase::addDatabase("QSQLITE");
        dbase.setDatabaseName(QDir::currentPath() + "/base/MyDiet.sqlite");
        dbase.open();

        model->select();
        showTotal();
    }
}

void FitAssist::doubleClickedEdit(const QModelIndex &index)
{
    EditDialog *edit = new EditDialog(this);
    edit->setAttribute(Qt::WA_DeleteOnClose, true);

    connect(this, &FitAssist::sendModel, edit, &EditDialog::getModel);
    connect(edit, &EditDialog::sendUpdateFlag, this, &FitAssist::setUpdateFlag);

    emit sendModel(model);

    edit->showEdit(index);
}

void FitAssist::deleteRowFromMyDiet()
{
    model->removeRow(ui->tableView->currentIndex().row());
    setUpdateFlag(true);
}

void FitAssist::removeAllRows()
{
    for (int i = 0; i < model->rowCount(); i++)
        model->removeRow(i);
    setUpdateFlag(true);
}

void FitAssist::clickedOnEditList()
{
    EditListDialog *editList = new EditListDialog(this);
    editList->setAttribute(Qt::WA_DeleteOnClose, true);
    editList->show();
}

void FitAssist::clickedOnAboutDialog()
{
    AboutDialog *about = new AboutDialog(this);
    about->setAttribute(Qt::WA_DeleteOnClose, true);
    about->show();
}

void FitAssist::clickedOnAddDialog()
{
    AddDialog *add = new AddDialog(this);
    add->setAttribute(Qt::WA_DeleteOnClose, true);

    // Update the model when the signal come
    connect(add, &AddDialog::sendUpdateFlag, this, &FitAssist::setUpdateFlag);

    add->show();
}

void FitAssist::showAdvices()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void FitAssist::maleReactToToggle(bool checked)
{
    if (checked)
        ui->labelImage->setPixmap(QPixmap(":man&woman/images/man.png"));
    else
        ui->labelImage->setPixmap(QPixmap(":man&woman/images/woman.png"));
}

bool FitAssist::readProfile()
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    } else {
        QDataStream in(&file);


        in >> *profile;

        file.close();

        if (profile->getGender() == "male") {
            ui->radioButtonMale->setChecked(true);
            ui->labelImage->setPixmap(QPixmap(":man&woman/images/man.png"));
        }
        else {
            ui->radioButtonFemale->setChecked(true);
            ui->labelImage->setPixmap(QPixmap(":man&woman/images/woman.png"));
        }
        ui->doubleSpinBoxWeight->setValue(profile->getWeigth());
        ui->spinBoxHeight->setValue(profile->getHeigth());
        ui->spinBoxAge->setValue(profile->getAge());
        float activity = profile->getActivity() * 1000;
        ui->spinBoxTarget->setValue(profile->getCalorie());

        if (activity == 1200)
            ui->comboBoxActivity->setCurrentIndex(0);
        else if (activity == 1375)
            ui->comboBoxActivity->setCurrentIndex(1);
        else if (activity == 1550)
            ui->comboBoxActivity->setCurrentIndex(2);
        else if (activity == 1725)
            ui->comboBoxActivity->setCurrentIndex(3);
        else
            ui->comboBoxActivity->setCurrentIndex(4);

        showNorms();
        return true;
    }
}

void FitAssist::writeProfile()
{
    if (!QDir("profile").exists())
        QDir().mkdir("profile");

    QFile file(fileName);
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_5);

    if(file.open(QIODevice::WriteOnly))
        out << *profile;

    file.close();
}

void FitAssist::showNorms()
{
    ui->labelTarget->setText(QString::number(profile->getCalorie()));
    ui->labelTargetCcal->setText(" " + tr("Ккал"));
    ui->labelBMI->setText(QString::number(profile->getBMI(),'g',3));
    ui->labelConformity->setText(profile->getConclusion());
    QString res = QString::number(profile->getOptimalWeightMin(),'g',3) + " - " + QString::number(profile->getOptimalWeightMax(),'g',4);
    ui->labelOptimalWeight->setText(res);
    ui->labelCalorieNorm->setText(QString::number(profile->getBMR(),'g',4));
    ui->labelWaterNorm->setText(QString::number(profile->getWater(),'g',3));
}

void FitAssist::readMyDiet()
{
    dbase.setDatabaseName(QDir::currentPath() + "/base/MyDiet.sqlite");
    dbase.open();

    QSqlQuery query;
    QString str = "CREATE TABLE " + tr("Рацион") + " ("
                  + tr("Наименование") + " text, "
                  + tr("Вес") + " double, "
                  + tr("Белки") + " double, "
                  + tr("Жиры") + " double, "
                  + tr("Углеводы") + " double, "
                  + tr("Ккал") + " integer"
                  ");";
    query.exec(str);

    model->setTable(tr("Рацион"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Update the total PFC and redraw the pie chart
    connect(this, &FitAssist::sendPFC, ui->widget, &PieChart::getPFC);
    connect(ui->widget, &PieChart::sendPFC, this, &FitAssist::getPFC);

    showTotal();
}

void FitAssist::showTotal()
{
    int weight = 0;
    int calorie = 0;
    double protein = 0;
    double fat = 0;
    double carbohydrate = 0;

    for (int i = 0; i < model->rowCount(); i++) {
        weight += model->record(i).value(tr("Вес")).toInt();
        protein += model->record(i).value(tr("Белки")).toDouble();
        fat += model->record(i).value(tr("Жиры")).toDouble();
        carbohydrate += model->record(i).value(tr("Углеводы")).toDouble();
        calorie += model->record(i).value(tr("Ккал")).toInt();
    }

    ui->lblWeight->setText(QString::number(weight));
    ui->lblProtein_Conclusion->setText(QString::number(protein));
    ui->lblFat_Conclusion->setText(QString::number(fat));
    ui->lblCarbohydrate_Conlusion->setText(QString::number(carbohydrate));
    ui->lblCalorie_Conclusion->setText(QString::number(calorie));
    ui->labelRecieved->setText(QString::number(calorie));
    ui->labelRecievedCcal->setText(" " + tr("Ккал"));

    int targetCalorie = ui->labelTarget->text().toInt();
    if (calorie > 0 && targetCalorie != 0) {
        ui->labelLefted->setText(QString::number(targetCalorie - calorie));
        ui->labelLeftedCcal->setText(" " + tr("Ккал"));
    } else {
        ui->labelLefted->setText("0");
        ui->labelLeftedCcal->setText(" " + tr("Ккал"));
    }

    emit sendPFC(protein, fat, carbohydrate);
}
