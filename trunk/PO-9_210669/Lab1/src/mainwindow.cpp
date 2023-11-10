#include "mainwindow.h" //210669_1
#include "./ui_mainwindow.h" //210669_1

MainWindow::MainWindow(QWidget *parent) //210669_1
    : QMainWindow(parent) //210669_1
    , ui(new Ui::MainWindow) //210669_1
{
    ui->setupUi(this); //210669_1
}

MainWindow::~MainWindow() //210669_1
{
    delete ui; //210669_1
}


