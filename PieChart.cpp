#include "PieChart.h"

PieChart::PieChart(QWidget *parent) : QWidget(parent)
{

}

void PieChart::resizeEvent(QResizeEvent *)
{
    setGeometry(x(), y(), qMin(width(), height()), qMin(width(), height()));
}

void PieChart::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QRectF size = QRectF(0, 0, this->width(), this->height());
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    pen.setBrush(Qt::white);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    double sum = protein + fat + carbohydrate;

    if (protein == protein && fat == fat && carbohydrate == carbohydrate) {
        emit sendPFC(protein * 100 / sum, fat * 100 / sum, carbohydrate * 100 / sum);

        //Proteins
        painter.setBrush(QColor("#5DA5DA"));
        painter.setPen(pen);
        painter.drawPie(size, 0, protein * 360 * 16 / sum);

        //Fats
        painter.setBrush(QColor("#FAA43A"));
        painter.drawPie(size, protein * 360 * 16 / sum, fat * 360 * 16 / sum);

        //Carbohydrates
        painter.setBrush(QColor("#B276B2"));
        painter.drawPie(size, protein * 360 * 16 / sum + fat * 360 * 16 / sum, carbohydrate * 360 * 16 / sum);
    }
}

void PieChart::getPFC(double protein, double fat, double carbohydrate)
{
    this->protein = protein;
    this->fat = fat;
    this->carbohydrate = carbohydrate;
}

