#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->RedValue, &QSpinBox::valueChanged, this, &MainWindow::redValueChanged);
    connect(ui->RedSlider, &QSlider::valueChanged, this, &MainWindow::redValueChanged);
    connect(ui->GreenValue, &QSpinBox::valueChanged, this, &MainWindow::greenValueChanged);
    connect(ui->GreenSlider, &QSlider::valueChanged, this, &MainWindow::greenValueChanged);
    connect(ui->BlueValue, &QSpinBox::valueChanged, this, &MainWindow::blueValueChanged);
    connect(ui->BlueSlider, &QSlider::valueChanged, this, &MainWindow::blueValueChanged);
    connect(ui->enterFile, &QPushButton::clicked, this, &MainWindow::openFile); 
    color = {0, 0, 0};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::redValueChanged(int value)
{
    color.red = value;
    ui->RedValue->setValue(color.red);
    ui->RedSlider->setValue(color.red);
    setColor();

}

void MainWindow::greenValueChanged(int value)
{
    color.green = value;
    ui->GreenValue->setValue(color.green);
    ui->GreenSlider->setValue(color.green);
    setColor();

}

void MainWindow::blueValueChanged(int value)
{
    color.blue = value;
    ui->BlueValue->setValue(color.blue);
    ui->BlueSlider->setValue(color.blue);
    setColor();
}

void MainWindow::setColor()
{
    QString line = QString("background: rgb(%1, %2, %3)").arg(color.red).arg(color.green).arg(color.blue);
    ui->RectangleToColor->setStyleSheet(line);
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(0, "open file", "", "All files(*.*)");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream fileContent(&file);
    ui->fileContent->clear();
    ui->fileContent->insertPlainText(fileContent.readAll());
    file.close();
}
