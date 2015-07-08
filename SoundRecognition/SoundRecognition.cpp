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
    //ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,10);
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("U"));
    //ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,1);

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
QVector<qint16> v1(0);
QVector<qint16> v2(0);

void SoundRecognition::on_openButton_pressed()
{
    connect(ui->openButton, &QAbstractButton::pressed, this, &SoundRecognition::open);
}

void SoundRecognition::open()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Files Wave (*.wav)"));
    if (fileName != "") {
        QFile wavFile(fileName);
        if (!wavFile.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file!"));
            return;
        }
        QByteArray wavFileContent = wavFile.readAll();

        QDataStream analyzeHeaderDS(&wavFileContent,QIODevice::ReadOnly);
        analyzeHeaderDS.setByteOrder(QDataStream::LittleEndian);

        // Now pop off the appropriate data into each header field defined above
        wav_header_t wavHeader;
        analyzeHeaderDS.readRawData(wavHeader.chunkId, 4); // "RIFF"
        analyzeHeaderDS >> wavHeader.chunkSize; // File Size
        analyzeHeaderDS.readRawData(wavHeader.format,4); // "WAVE"
        analyzeHeaderDS.readRawData(wavHeader.subchunk1ID,4); // "fmt"
        analyzeHeaderDS >> wavHeader.subchunk1Size; // Format length
        analyzeHeaderDS >> wavHeader.audioFormat; // Format type
        analyzeHeaderDS >> wavHeader.numChannels; // Number of channels
        analyzeHeaderDS >> wavHeader.sampleRate; // Sample rate
        analyzeHeaderDS >> wavHeader.byteRate; // (Sample Rate * BitsPerSample * Channels) / 8
        analyzeHeaderDS >> wavHeader.blockAlign; // (BitsPerSample * Channels) / 8.1
        analyzeHeaderDS >> wavHeader.bitsPerSample; // Bits per sample
        wavFile.close();
        QFile wavFile1(fileName);
        wavFile1.open(QFile::ReadOnly);
        quint32 chunkDataSize = 0;
        QByteArray temp_buff;
        char buff[0x04];
        while (true)
        {
            QByteArray tmp = wavFile1.read(0x04);
            temp_buff.append(tmp);
            int idx = temp_buff.indexOf("data");
            if (idx >= 0)
            {
                int lenOfData = temp_buff.length() - (idx + 4);
                memcpy(buff, temp_buff.constData() + idx + 4, lenOfData);
                int bytesToRead = 4 - lenOfData;
                // finish readind size of chunk
                if (bytesToRead > 0)
                {
                    int read = wavFile1.read(buff + lenOfData, bytesToRead);
                    if (bytesToRead != read)
                    {
                        QMessageBox::critical(this, tr("Error"), tr("Something awful happens!"));
                        return;
                    }
                }
                chunkDataSize = qFromLittleEndian<quint32>((const uchar*)buff);
                break;
            }
            if (temp_buff.length() >= 8)
            {
                temp_buff.remove(0, 0x04);
            }
        }
        if (!chunkDataSize)
        {
            QMessageBox::critical(this, tr("Error"), tr("Chunk data not found!"));
            return;
        }
        int samples = 0;
        QString fileToSave = "list.dat";
        QFile saveFile(fileToSave);
        saveFile.open(QIODevice::WriteOnly);
        if (wavHeader.numChannels == 2)
            saveFile.write("1\t 2\r\n");
        while (wavFile1.read(buff, 0x04) > 0)
        {
            chunkDataSize -= 4;
            ++samples;
            qint16 sampleCannel1 = qFromLittleEndian<qint16>((const uchar*)buff);
            qint16 sampleCannel2 = qFromLittleEndian<qint16>((const uchar*)(buff + 2));
            switch (wavHeader.numChannels) {
            case 1:
                if (saveFile.isOpen())
                {
                    v1.append(sampleCannel1);
                    v1.append(sampleCannel2);
                    saveFile.write(QString("%1\r\n %2\r\n").arg(sampleCannel1).arg(sampleCannel2).toUtf8());
                }
                break;
            case 2:
                if (saveFile.isOpen())
                {
                    v1.append(sampleCannel1);
                    v2.append(sampleCannel2);
                    saveFile.write(QString("%1\t %2\r\n").arg(sampleCannel1).arg(sampleCannel2).toUtf8());
                }
                break;
            }

            // check the end of the file
            if (chunkDataSize == 0 || chunkDataSize & 0x80000000)
            {
                break;
            }
        }
        QMessageBox::information(this, "Reading complete", "Readed " + QString::number(samples) + " samples...");
        wavFile1.close();
        if (saveFile.isOpen())
        {
            saveFile.close();
        }
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
    qint16 *data = v1.data();
    quint16 di = 1;
    for (quint32 i = 0; i <= v1.size(); i += di)
        intervals->append(QwtIntervalSample(qAbs(data[i]), i, i + di));
    hystogram->setSamples(*intervals);
    hystogram->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    hystogram->setPen(QPen(Qt::black));
    hystogram->setBrush(QBrush(Qt::gray));
}

void SoundRecognition::on_infoButton_pressed()
{
    connect(ui->startButton, &QAbstractButton::pressed, this, &SoundRecognition::DrawHistogram);
    infoDialog *frm = new infoDialog;
    frm->show();
}
