#ifndef SOUNDRECOGNITION_H
#define SOUNDRECOGNITION_H

#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QtEndian>
#include <QVector>
#include "qmath.h"
#include <infoDialog.h>

#include "qwt_plot_item.h"
#include "qwt_plot_histogram.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_symbol.h"

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
