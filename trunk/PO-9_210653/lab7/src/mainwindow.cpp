#include "mainwindow.h"
#include <QPainter>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), angle(0), posX(0), posY(0), pedestalX(width() / 2 - 25), pedestalY(height() / 2 - 25)
{
    setFixedSize(600, 400); // Устанавливаем размеры окна

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]() {
        // Закручивающаяся спираль
        qreal spiralRadius = 150 - 10 * angle; // Радиус спирали (уменьшаем для закручивания)
        posX = width() / 2 + spiralRadius * cos(angle);
        posY = height() / 2 + spiralRadius * sin(angle);

        angle += 0.075; // Угол поворота для движения по спирали

        // Обновляем позицию пьедестала
        pedestalX = posX - 25;
        pedestalY = posY - 25;

        update(); // Перерисовываем окно
    });

    angle = 0;
    posX = width() / 2;
    posY = height() / 2;

    timer->start(50); // Запускаем таймер
}

MainWindow::~MainWindow()
{
    delete timer;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    // Центр пьедестала
    qreal pedestalCenterX = pedestalX + 25;
    qreal pedestalCenterY = pedestalY + 25;

    // Рисуем пьедестал
    painter.setBrush(Qt::darkGray); // Цвет пьедестала
    painter.drawRect(pedestalX, pedestalY, 50, 80); // Пьедестал (прямоугольник)

    // Рисуем прямоугольник над пьедесталом
    qreal rectangleCenterX = pedestalCenterX; // Центр прямоугольника по X (совпадает с центром пьедестала)
    qreal rectangleCenterY = pedestalCenterY; // Центр прямоугольника по Y (на 15px выше центра пьедестала)

    // Привязываем центр прямоугольника к центру пьедестала
    qreal rectangleX = rectangleCenterX - 15; // Прямоугольник (верхняя часть)
    qreal rectangleY = rectangleCenterY; // Прямоугольник (верхняя часть)

    painter.setBrush(Qt::blue); // Цвет прямоугольника
    QRectF rectangle(rectangleX, rectangleY, 30, 40); // Прямоугольник (верхняя часть)
    painter.drawRect(rectangle);

    // Рисуем текст
    QFont font = painter.font();
    font.setBold(true); // Полужирный шрифт
    painter.setFont(font);
    painter.translate(width() - 580, height() - 85); // Устанавливаем позицию текста
    painter.rotate(-90); // Поворачиваем текст на 90 градусов против часовой стрелки
    painter.drawText(0, 0, "Графические примитивы в библиотеке QT"); // Рисуем текст
}
