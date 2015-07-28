#ifndef SOUNDRECOGNITION_H
#define SOUNDRECOGNITION_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QtEndian>
#include <QDateTime>
#include "qmath.h"
#include "infoDialog.h"

#include <QVector>
#include <QtEndian>

#include <infoDialog.h>

#include "qwt_plot_item.h"
#include "qwt_plot_histogram.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_symbol.h"

<<<<<<< HEAD
//Wav Header
struct wav_header_t
{
    char chunkId[4]; //"RIFF" = 0x46464952
    quint32 chunkSize; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
    char format[4]; //"WAVE" = 0x45564157
    char subchunk1ID[4]; //"fmt " = 0x20746D66
    quint32 subchunk1Size; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
    quint16 audioFormat;
    quint16 numChannels;
    quint32 sampleRate;
    quint32 byteRate;
    quint16 blockAlign;
    quint16 bitsPerSample;
=======
struct wav_header_t
{
    char chunkId[4]; //"RIFF" = 0x46464952
    qint32 chunkSize; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
    char format[4]; //"WAVE" = 0x45564157
    char subchunk1ID[4]; //"fmt " = 0x20746D66
    qint32 subchunk1Size; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
    unsigned short audioFormat;
    unsigned short numChannels;
    qint32 sampleRate;
    qint32 byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
>>>>>>> origin/master
    //[WORD wExtraFormatBytes;]
    //[Extra format bytes]
};

namespace Ui {
class SoundRecognition;
}

class SoundRecognition : public QMainWindow
{
    Q_OBJECT

public:
    explicit SoundRecognition(QWidget *parent = 0);
    ~SoundRecognition();

signals:
    void sendData(QVector <QString> v);

private slots:
    void open();

    void DrawHistogram();

    void writeInfo();

    QString fileSize(qint64 nSize);

    void vecAbs(QVector <qint16> &v, quint32 n);

    quint32 sum(QVector <qint16> v, quint32 n);

    double mx(quint32 s, quint32 n);

    void delta(QVector <qint16> &v, quint32 n, double mx);

    double sigma(quint32 s, quint32 n);

    double asimetria(quint32 s, quint32 n, double sig);

    double ex(quint32 s, quint32 n, double sig);

    void calculate();

    void on_openButton_pressed();

    void on_startButton_pressed();

    void on_infoButton_pressed();

<<<<<<< HEAD
    void on_calculateButton_pressed();

=======
>>>>>>> origin/master
private:
    Ui::SoundRecognition *ui;

    infoDialog* info;

    QwtPlotGrid *grid;

    QwtPlotZoomer *zoom;
};

#endif // SOUNDRECOGNITION_H
