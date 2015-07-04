#include "SoundRecognition.h"
#include "ui_SoundRecognition.h"

SoundRecognition::SoundRecognition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SoundRecognition)
{
    ui->setupUi(this);

    ui->qwtPlot->setTitle(QString("Histogram"));

    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajorPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->qwtPlot);

    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString("t"));
    ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,10);
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("U"));
    ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,1);

    zoom = new QwtPlotZoomer(ui->qwtPlot->canvas());
    zoom->setRubberBandPen(QPen(Qt::white));
}

SoundRecognition::~SoundRecognition()
{
    delete grid;
    delete zoom;
    delete ui;
}

QString fileName;

void SoundRecognition::on_openButton_pressed()
{
    connect(ui->openButton, &QAbstractButton::pressed, this, &SoundRecognition::open);
}

void SoundRecognition::open()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Files Wave (*.wav)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file!"));
            return;
        }
    file.close();
    }
}

void SoundRecognition::on_startButton_pressed()
{
    connect(ui->startButton, &QAbstractButton::pressed, this, &SoundRecognition::DrawHistogram);
}

void SoundRecognition::DrawHistogram()
{
    QwtPlotHistogram *hystogram = new QwtPlotHistogram;
    QVector<QwtIntervalSample> *intervals = new QVector<QwtIntervalSample>;
    float di = 0.1;
    for (float i=0; i<=10; i+=di)
        intervals->append(QwtIntervalSample(qAbs(qSin(i)), i, i+di));
    hystogram->setSamples(*intervals);
    hystogram->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    hystogram->setPen(QPen(Qt::black));
    hystogram->setBrush(QBrush(Qt::gray));
}
