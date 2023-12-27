#include "mainwindow.h"
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <cmath>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent), t(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CustomWidget::animate);
    timer->start(50);
}

void CustomWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.save();
    painter.translate(20, height() / 3); // Начальные координаты текста
    painter.rotate(90); // Поворачиваем текст на 90 градусов
    QFont font("Gothic", 12);
    painter.setFont(font);
    painter.drawText(0, 0, "Графические примитивы в библиотеке QT");
    painter.restore();

    painter.save();
    painter.translate(treeX, treeY);


    // Устанавливаем цвет для ствола ёлки
    painter.setPen(Qt::black);

    // Рисуем ствол ёлки (прямоугольник)
    painter.drawRect(-10, 0, 20, 100);

    // Устанавливаем цвет для зелёной части ёлки
    painter.setBrush(Qt::green);

    // Определяем координаты для треугольников
    QPolygonF triangle1;
    triangle1 << QPointF(0, 0) << QPointF(-50, 100) << QPointF(50, 100);

    QPolygonF triangle2;
    triangle2 << QPointF(0, -50) << QPointF(-40, 50) << QPointF(40, 50);

    // Рисуем два треугольника
    painter.drawPolygon(triangle1);
    painter.drawPolygon(triangle2);

    painter.restore();
}

void CustomWidget::animate() {
    t += 0.02;

    qreal a = -100; // Пример отрицательного значения 'a'
    qreal x = t * width();
    qreal xSquared = x * x;

    // Изменяем положение ёлки по траектории Варзьера Аньези
    qreal y = (8 * a * a) / (xSquared + 4 * a * a);

    // Масштабируем координаты для отображения на виджете
    treeX = x;
    treeY = height() - (y * height() / 2); // Масштабируем 'y' для соответствия высоте виджета

    if(t >= 1){
        t=0;
    }
    update();
}
