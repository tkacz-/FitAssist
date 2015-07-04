#ifndef SOUNDRECOGNITION_H
#define SOUNDRECOGNITION_H

#include <QMainWindow>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "qmath.h"

#include "qwt_plot_item.h"
#include "qwt_plot_histogram.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_zoomer.h"
#include "qwt_symbol.h"

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

private:
    Ui::SoundRecognition *ui;

    QwtPlotGrid *grid;

    QwtPlotZoomer *zoom;
};

#endif // SOUNDRECOGNITION_H
