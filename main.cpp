#include "FitnessCalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FitnessCalc w;
    w.show();

    return a.exec();
}
