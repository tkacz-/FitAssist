#ifndef SOUNDRECOGNITION_H
#define SOUNDRECOGNITION_H

#include <QMainWindow>

namespace Ui {
class SoundRecognition;
}

class SoundRecognition : public QMainWindow
{
    Q_OBJECT

public:
    explicit SoundRecognition(QWidget *parent = 0);
    ~SoundRecognition();

private:
    Ui::SoundRecognition *ui;
};

#endif // SOUNDRECOGNITION_H
