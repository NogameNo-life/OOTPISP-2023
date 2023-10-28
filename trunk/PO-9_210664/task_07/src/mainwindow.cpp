#include "mainwindow.h" //210664

#include "./ui_mainwindow.h" //210664
#include "customwidget.h"

MainWindow::MainWindow(QWidget *parent) //210664
    : QMainWindow(parent) //210664
    , ui(new Ui::MainWindow) //210664
{
    ui->setupUi(this); //210664

    ui->groupBox->setLayout(new QVBoxLayout(this));
    ui->groupBox->layout()->addWidget(new CustomWidget(this));
}
 //210664
MainWindow::~MainWindow() //210664
{ //210664
    delete ui; //210664
} //210664
