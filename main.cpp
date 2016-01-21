#include "FitnessCalc.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int screenWidth;
    int screenHeight;

    int x, y;

    FitnessCalc w;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - w.width()) / 2;
    y = (screenHeight - w.height()) / 2;

    w.move(x, y);
    w.show();

    return a.exec();
}
