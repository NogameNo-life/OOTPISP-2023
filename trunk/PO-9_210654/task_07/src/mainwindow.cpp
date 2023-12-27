#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->objWidth = rand()%100 + 100;
    this->objHeight = rand()%100 + 100;
    this->offSetX = 0;
    this->offSetY = height() / 2;
    this->dx = 0.5;
    this->dy = 0.05;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePosition);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.rotate(-90);
    painter.setFont(QFont("Book antiqua", 14));
    painter.drawText(QRect(-height(), 0, width(), 20), "Графические примитивы в библиотеке Qt");
    painter.rotate(90);
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
    QRect rectangle(this->offSetX, this->offSetY, this->objWidth, this->objHeight);
    painter.drawRect(rectangle);
    painter.drawEllipse(rectangle);
    painter.end();
}

void MainWindow::updatePosition()
{
    this->offSetX += this->dx*5;
    this->offSetY += -7 * sin(this->dy);
    this->dy += this->dx/10;
    update();
    if (this->offSetX > width()) {
        this->offSetX = -this->objWidth;
    }
}
