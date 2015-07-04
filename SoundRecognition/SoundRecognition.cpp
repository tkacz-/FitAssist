#include "SoundRecognition.h"
#include "ui_SoundRecognition.h"

SoundRecognition::SoundRecognition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SoundRecognition)
{
    ui->setupUi(this);
}

SoundRecognition::~SoundRecognition()
{
    delete ui;
}
