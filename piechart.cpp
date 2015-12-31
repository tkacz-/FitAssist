#include "piechart.h"

PieChart::PieChart(QWidget *parent) : QWidget(parent)
{
    QSizePolicy p(sizePolicy());
    p.setHeightForWidth(true);
    setSizePolicy(p);
}

void PieChart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF(0, 0, this->width(), this->height());
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    pen.setBrush(Qt::white);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    //long sum = protein + fat + carbonhydrate;

    //emit sendPFC(protein * 100 / sum, fat * 100 / sum, carbohydrate * 100 / sum);

    //Белки
    painter.setBrush(QColor("#5DA5DA"));
    painter.setPen(pen);
    painter.drawPie(size, 0, 90*16); //protein * 360 / sum

    //Жиры
    painter.setBrush(QColor("#FAA43A"));
    painter.drawPie(size, 90*16, 90*16); //fat * 360 / sum

    //Углеводы
    painter.setBrush(QColor("#B276B2"));
    painter.drawPie(size, 180*16, 180*16); //carbohydrate * 360 / sum
}

void PieChart::getPFC(int protein, int fat, int carbonhydrate)
{
    this->protein = protein;
    this->fat = fat;
    this->carbonhydrate = carbonhydrate;
}

