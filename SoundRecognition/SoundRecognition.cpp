#include "SoundRecognition.h"
#include "ui_SoundRecognition.h"


SoundRecognition::SoundRecognition(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SoundRecognition)
{
    ui->setupUi(this);

    //ui->qwtPlot->setTitle(QString("Histogram"));

    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajorPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->qwtPlot);

<<<<<<< HEAD
    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajorPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->qwtPlot);
    grid->attach(ui->qwtPlot_2);

    //ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString("t"));
    //ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,10);
    //ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("U"));
=======
    ui->qwtPlot->setAxisTitle(QwtPlot::xBottom,QString("t"));
    //ui->qwtPlot->setAxisScale(QwtPlot::xBottom,0,10);
    ui->qwtPlot->setAxisTitle(QwtPlot::yLeft,QString("U"));
>>>>>>> origin/master
    //ui->qwtPlot->setAxisScale(QwtPlot::yLeft,0,1);

    zoom = new QwtPlotZoomer(ui->qwtPlot->canvas());
    zoom->setRubberBandPen(QPen(Qt::white));
    zoom = new QwtPlotZoomer(ui->qwtPlot_2->canvas());
    zoom->setRubberBandPen(QPen(Qt::white));
    info = new infoDialog();
}

SoundRecognition::~SoundRecognition()
{
    delete grid;
    delete zoom;
    delete ui;
}

QString fileName;
<<<<<<< HEAD
QVector <qint16> v1(0);
QVector <qint16> v2(0);
wav_header_t wavHeader;
=======
QVector<qint16> v1(0);
QVector<qint16> v2(0);
>>>>>>> origin/master

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
<<<<<<< HEAD

        //Read WAV header
        QDataStream analyzeHeader (&wavFile);
        analyzeHeader.setByteOrder(QDataStream::LittleEndian);
        analyzeHeader.readRawData(wavHeader.chunkId, 4); // "RIFF"
        analyzeHeader >> wavHeader.chunkSize; // File Size
        analyzeHeader.readRawData(wavHeader.format,4); // "WAVE"
        analyzeHeader.readRawData(wavHeader.subchunk1ID,4); // "fmt"
        analyzeHeader >> wavHeader.subchunk1Size; // Format length
        analyzeHeader >> wavHeader.audioFormat; // Format type
        analyzeHeader >> wavHeader.numChannels; // Number of channels
        analyzeHeader >> wavHeader.sampleRate; // Sample rate
        analyzeHeader >> wavHeader.byteRate; // (Sample Rate * BitsPerSample * Channels) / 8
        analyzeHeader >> wavHeader.blockAlign; // (BitsPerSample * Channels) / 8.1
        analyzeHeader >> wavHeader.bitsPerSample; // Bits per sample

=======
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
>>>>>>> origin/master
        quint32 chunkDataSize = 0;
        QByteArray temp_buff;
        char buff[0x04];
        while (true)
        {
<<<<<<< HEAD
            QByteArray tmp = wavFile.read(0x04);
=======
            QByteArray tmp = wavFile1.read(0x04);
>>>>>>> origin/master
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
<<<<<<< HEAD
                    int read = wavFile.read(buff + lenOfData, bytesToRead);
=======
                    int read = wavFile1.read(buff + lenOfData, bytesToRead);
>>>>>>> origin/master
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
<<<<<<< HEAD
        while (wavFile.read(buff, 0x04) > 0)
=======
        QString fileToSave = "list.dat";
        QFile saveFile(fileToSave);
        saveFile.open(QIODevice::WriteOnly);
        if (wavHeader.numChannels == 2)
            saveFile.write("1\t 2\r\n");
        while (wavFile1.read(buff, 0x04) > 0)
>>>>>>> origin/master
        {
            chunkDataSize -= 4;
            ++samples;
            qint16 sampleCannel1 = qFromLittleEndian<qint16>((const uchar*)buff);
            qint16 sampleCannel2 = qFromLittleEndian<qint16>((const uchar*)(buff + 2));
            switch (wavHeader.numChannels) {
            case 1:
<<<<<<< HEAD
                v1.append(sampleCannel1);
                v1.append(sampleCannel2);
                break;
            case 2:
                v1.append(sampleCannel1);
                v2.append(sampleCannel2);
                break;
            }
=======
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

>>>>>>> origin/master
            // check the end of the file
            if (chunkDataSize == 0 || chunkDataSize & 0x80000000)
            {
                break;
            }
        }
<<<<<<< HEAD
        QMessageBox::information(this, "Reading complete","Readed " + QString::number(samples) + " samples...");
        wavFile.close();
=======
        QMessageBox::information(this, "Reading complete", "Readed " + QString::number(samples) + " samples...");
        wavFile1.close();
        if (saveFile.isOpen())
        {
            saveFile.close();
        }
>>>>>>> origin/master
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
<<<<<<< HEAD
    qint16* data = v1.data();
    int di = 1;
    for (qint32 i=0; i <= v1.size(); i += di)
=======
    qint16 *data = v1.data();
    quint16 di = 1;
    for (quint32 i = 0; i <= v1.size(); i += di)
>>>>>>> origin/master
        intervals->append(QwtIntervalSample(qAbs(data[i]), i, i + di));
    hystogram->setSamples(*intervals);
    hystogram->attach(ui->qwtPlot);
    ui->qwtPlot->replot();
    hystogram->setPen(QPen(Qt::black));
    hystogram->setBrush(QBrush(Qt::gray));
    if(wavHeader.numChannels == 2) {
        QwtPlotHistogram *hystogram2 = new QwtPlotHistogram;
        QVector<QwtIntervalSample> *intervals2 = new QVector<QwtIntervalSample>;
        qint16* data2 = v2.data();
        int di2 = 1;
        for (qint32 i=0; i <= v2.size(); i += di)
            intervals2->append(QwtIntervalSample(qAbs(data2[i]), i, i + di2));
        hystogram2->setSamples(*intervals2);
        hystogram2->attach(ui->qwtPlot_2);
        ui->qwtPlot_2->replot();
        hystogram2->setPen(QPen(Qt::black));
        hystogram2->setBrush(QBrush(Qt::gray));
    }
}

void SoundRecognition::on_infoButton_pressed()
{
    connect(ui->infoButton, &QAbstractButton::pressed, this, &SoundRecognition::writeInfo);
}

void SoundRecognition::writeInfo()
{
    connect(this, SIGNAL(sendData(QVector <QString>)), info, SLOT(receiveData(QVector <QString>)));
    QVector <QString> data(0);
    data.append(wavHeader.chunkId);
    data.append(QString::number(wavHeader.chunkSize));
    data.append(wavHeader.format);
    data.append(wavHeader.subchunk1ID);
    data.append(QString::number(wavHeader.subchunk1Size));
    data.append(QString::number(wavHeader.audioFormat));
    data.append(QString::number(wavHeader.numChannels));
    data.append(QString::number(wavHeader.sampleRate));
    data.append(QString::number(wavHeader.byteRate));
    data.append(QString::number(wavHeader.blockAlign));
    data.append(QString::number(wavHeader.bitsPerSample));
    QFileInfo f(fileName);
    data.append(f.created().toString("MM/dd/yyyy hh:mm:ss"));
    data.append(f.lastModified().toString("MM/dd/yyyy hh:mm:ss"));
    data.append(QString::number(f.size()) + " B");
    emit sendData(data);
    info->show();
}

QString SoundRecognition::fileSize(qint64 nSize)
{
    qint64 i = 0;
    for (; nSize > 1023; nSize /= 1024, ++i) {}
    return QString().setNum(nSize) + " " + "BKMGT"[i];
}

void SoundRecognition::vecAbs(QVector <qint16> &v, quint32 n)
{
    qint16* data = v.data();
    for (quint32 i = 0; i < n; i++)
    {
        data[i] = qAbs(data[i]);
    }
}

quint32 SoundRecognition::sum(QVector <qint16> v, quint32 n)
{
    qint16* data = v.data();
    quint32 s = 0;
    for (quint32 i = 0; i < n; i++)
        s += data[i];
    return s;
}

double SoundRecognition::mx(quint32 s, quint32 n)
{
    double m = s / n;
    return m;
}

void SoundRecognition::delta(QVector <qint16> &v, quint32 n, double mx)
{
    qint16* data = v.data();
    for (quint32 i = 0; i < n; i++)
    {
        data[i] -= mx;
    }
}

double SoundRecognition::sigma(quint32 s, quint32 n)
{
    double res = qSqrt(s / (n - 1));
    return res;
}

double SoundRecognition::asimetria(quint32 s, quint32 n, double sig)
{
    double res = s / (n * qPow(sig,3));
    return res;
}

double SoundRecognition::ex(quint32 s, quint32 n, double sig)
{
    double res = s / (n * qPow(sig,4)) - 3;
    return res;
}

void SoundRecognition::on_calculateButton_pressed()
{
    connect(ui->calculateButton, QAbstractButton::pressed, this, &SoundRecognition::calculate);
}

void SoundRecognition::calculate()
{
    quint32 size = v1.size();
    SoundRecognition::vecAbs(v1, size);
    quint32 s = sum(v1, size);
    quint32 m = mx(s, size);
    delta(v1, size, m);
    delta(v1, size, m);
    quint32 s1 = sum(v1, size);
    double sig = sigma(s1, size);
    delta(v1, size, m);
    quint32 s2 = sum(v1, size);
    double as1 = asimetria(s2, size, sig);
    ui->asum->setText(QString::number(as1));
    delta(v1, size, m);
    quint32 s3 = sum(v1, size);
    double ex1 = ex(s3, size, sig);
    ui->exec->setText(QString::number(ex1));
}

void SoundRecognition::on_infoButton_pressed()
{
    connect(ui->startButton, &QAbstractButton::pressed, this, &SoundRecognition::DrawHistogram);
    infoDialog *frm = new infoDialog;
    frm->show();
}
