#ifndef PIECHART_H
#define PIECHART_H

#include <QWidget>
#include <QPainter>
#include <QPen>

class PieChart : public QWidget
{
    Q_OBJECT

public:
    explicit PieChart(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *);
    void paintEvent(QPaintEvent *);

signals:
    void sendPFC(double protein, double fat, double carbohydrate);

public slots:
    void getPFC(double protein, double fat, double carbohydrate);

private:
    double protein;
    double fat;
    double carbohydrate;
};

#endif // PIECHART_H
