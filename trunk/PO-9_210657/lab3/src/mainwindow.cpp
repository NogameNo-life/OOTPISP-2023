#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task1window.h"
#include "task2window.h"
#include "task3window.h"
#include "task4window.h"
#include "task5window.h"
#include "task6window.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_button1_clicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_button2_clicked()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(on_button3_clicked()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(on_button4_clicked()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(on_button5_clicked()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(on_button6_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button1_clicked()
{
    Task1Window *task1Window = new Task1Window(this);
    task1Window->show();
}

void MainWindow::on_button2_clicked()
{
    Task2Window *task2Window = new Task2Window(this);
    task2Window->show();
}

void MainWindow::on_button3_clicked()
{
    Task3Window *task3Window = new Task3Window(this);
    task3Window->show();
}

void MainWindow::on_button4_clicked()
{
    Task4Window *task4Window = new Task4Window(this);
    task4Window->show();
}

void MainWindow::on_button5_clicked()
{
    Task5Window *task5Window = new Task5Window(this);
    task5Window->show();
}

void MainWindow::on_button6_clicked()
{
    Task6Window *task6Window = new Task6Window(this);
    task6Window->show();
}

