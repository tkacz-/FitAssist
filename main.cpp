#include "FitAssist.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    translator.load(":translations/translations/ru.qm");
    a.installTranslator(&translator);

    int screenWidth;
    int screenHeight;

    int x, y;

    FitAssist w;

    QDesktopWidget *desktop = QApplication::desktop();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - w.width()) / 2;
    y = (screenHeight - w.height()) / 2;

    w.move(x, y);
    w.show();

    return a.exec();
}
