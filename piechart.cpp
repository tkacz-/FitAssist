#include "piechart.h"

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
    pen.setWidth(1);
    pen.setBrush(Qt::white);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    double sum = protein + fat + carbonhydrate;

    if (protein == protein && fat == fat && carbonhydrate == carbonhydrate) {
        emit sendPFC(protein * 100 / sum, fat * 100 / sum, carbonhydrate * 100 / sum);

        //Белки
        painter.setBrush(QColor("#5DA5DA"));
        painter.setPen(pen);
        painter.drawPie(size, 0, protein * 360 * 16 / sum);

        //Жиры
        painter.setBrush(QColor("#FAA43A"));
        painter.drawPie(size, protein * 360 * 16 / sum, fat * 360 * 16 / sum);

        //Углеводы
        painter.setBrush(QColor("#B276B2"));
        painter.drawPie(size, protein * 360 * 16 / sum + fat * 360 * 16 / sum, carbonhydrate * 360 * 16 / sum);
    }
}

void PieChart::getPFC(double protein, double fat, double carbonhydrate)
{
    this->protein = protein;
    this->fat = fat;
    this->carbonhydrate = carbonhydrate;
}

