#include "mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QLineF>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent), t(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CustomWidget::animate);
    timer->start(50);
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Рисуем отрезок прямой
    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    QLineF line(0, 0, width(), height());
    painter.drawLine(line);

    // Рисуем прямоугольники
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine));
    painter.setBrush(Qt::blue);

    qreal rectSize = 50;

    qreal x1 = t * (width() - rectSize);
    qreal y1 = t * (height() - rectSize);

    qreal x2 = x1 + rectSize;
    qreal y2 = y1 + rectSize;

    // Рисуем первый прямоугольник
    painter.drawRect(x1, y1, rectSize, rectSize);

    // Рисуем второй прямоугольник
    painter.drawRect(x2, y1, rectSize, rectSize);
}

void CustomWidget::animate() {
    t += 0.02; // Изменение параметра для движения по отрезку

    if (t >= 1) {
        t = 0; // Перезапуск движения после достижения конца отрезка
    }

    update();
}
