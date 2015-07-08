#ifndef SOUNDRECOGNITION_H
#define SOUNDRECOGNITION_H

#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "qmath.h"

#include <QVector>
#include <QtEndian>

#include <infoDialog.h>

#include "qwt_plot_item.h"
#include "qwt_plot_histogram.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_symbol.h"

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

private slots:
    void open();

    void DrawHistogram();

    void on_openButton_pressed();

    void on_startButton_pressed();

    void on_infoButton_pressed();

private:
    Ui::SoundRecognition *ui;

    QwtPlotGrid *grid;

    QwtPlotZoomer *zoom;
};

#endif // SOUNDRECOGNITION_H
