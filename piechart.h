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

    void paintEvent(QPaintEvent *);

protected:
    void resizeEvent(QResizeEvent *);

signals:
    void sendPFC(int protein, int fat, int carbonhydrate);

public slots:
    void getPFC(int protein, int fat, int carbonhydrate);

private:
    int protein;
    int fat;
    int carbonhydrate;
};

#endif // PIECHART_H
