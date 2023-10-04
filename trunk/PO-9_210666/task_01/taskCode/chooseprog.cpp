#include "chooseprog.h"
#include "ui_chooseprog.h"

ChooseProg::ChooseProg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseProg)
{
    ui->setupUi(this);
    QWidget* widget = new QWidget(0);
    this->setCentralWidget(widget);

    QGridLayout* grid_layout = new QGridLayout;
    widget->setLayout(grid_layout);

    QPushButton* bt1 = new QPushButton;
    QPushButton* bt2 = new QPushButton;
    bt1->setText("Choose bg color");
    bt2->setText("Choose file");
    bt2->setFixedHeight(40);
    bt1->setFixedHeight(40);
    grid_layout->addWidget(bt1, 0, 0, Qt::AlignBottom);
    grid_layout->addWidget(bt2, 0, 1, Qt::AlignBottom);

    this->resize(300, 80);
    this->setWindowTitle("OOP lab1");

    connect(bt1, &QPushButton::clicked, this, &ChooseProg::openBgColor);
    connect(bt2, &QPushButton::clicked, this, &ChooseProg::openFileOpener);
}

ChooseProg::~ChooseProg()
{
    delete ui;
}

void ChooseProg::openBgColor(){
    this->close();
    mw = new MainWindow;
    mw->show();
}

void ChooseProg::openFileOpener(){
    this->close();
    of = new OpenFile;
    of->show();
}

