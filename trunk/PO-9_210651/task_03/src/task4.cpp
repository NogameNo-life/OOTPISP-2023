#include "task4.h"
#include "ui_task4.h"

task4::task4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task4)
{
    ui->setupUi(this);
    setWindowTitle("Task4");
    QStack<QString> *stack = new QStack<QString>;
    QStack<QString> *stack2 = new QStack<QString>;
    QQueue<QString> *queue = new QQueue<QString>;
    QQueue<QString> *queue2 = new QQueue<QString>;

    QObject::connect(ui->GenSt, &QPushButton::clicked, [=]{
        stack->clear();
        stack2->clear();
        for (int i = 0; i < 10; i++){
            int randNum = rand() % 100-70;
            stack->push(QString("%1").arg(randNum));
        }
        ui->Oldst->setText(stack->join(" "));
        for (auto el : *stack){
            if (el.toInt() > 0)
                stack2->push("1");
            else if (el.toInt() < 0)
                stack2->push("-1");
            else
                stack2->push("0");
            ui->Newst->setText(stack2->join(' '));
        }
    });

    QObject::connect(ui->GenQu, &QPushButton::clicked, [=]{
        queue->clear();
        queue2->clear();
        int max = 0;
        for (int i = 0; i < 10; i++){
            int randNum = rand() % 100-10;
            queue->push_back(QString("%1").arg(randNum));
            max = std::max(max, randNum);
        }
        for (auto el: *queue){
            queue2->push_back(QString("%1").arg(el.toInt()+max));

        }
        ui->Oldqu->setText(queue->join(' '));
        ui->Newqu->setText(queue2->join(' '));
    });



}

task4::~task4()
{
    delete ui;
}
