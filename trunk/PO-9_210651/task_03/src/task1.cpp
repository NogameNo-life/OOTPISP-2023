#include "task1.h"
#include "./ui_task1.h"

task1::task1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::task1)
{
    ui->setupUi(this);

    XLEdit = new QLineEdit(this);
    YLEdit = new QLineEdit(this);
    ZLEdit = new QLineEdit(this);

    SButton = new QPushButton("Sorting",this);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(XLEdit);
    layout->addWidget(YLEdit);
    layout->addWidget(ZLEdit);
    layout->addWidget(SButton);


    connect(SButton, &QPushButton::clicked, this, &task1::Sorting);
}

task1::~task1()
{
    delete ui;
}

void task1::Sorting(){
    int x = XLEdit->text().toInt();
    int y = YLEdit->text().toInt();
    int z = ZLEdit->text().toInt();

    QVector<int>var = {x,y,z};
    std::sort(var.begin(), var.end(),std::greater<int>());

    XLEdit->setText(QString::number(var[0]));
    YLEdit->setText(QString::number(var[1]));
    ZLEdit->setText(QString::number(var[2]));
}
