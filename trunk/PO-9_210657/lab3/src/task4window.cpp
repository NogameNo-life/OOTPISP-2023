#include "task4window.h"
#include "ui_task4window.h"
#include <QRandomGenerator>

Task4Window::Task4Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task4Window)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->pushButtonGenerateStack, &QPushButton::clicked, this, &Task4Window::on_pushButtonGenerateStack_clicked);
    connect(ui->pushButtonGenerateQueue, &QPushButton::clicked, this, &Task4Window::on_pushButtonGenerateQueue_clicked);
}

Task4Window::~Task4Window()
{
    delete ui;
}

void Task4Window::on_pushButtonGenerateStack_clicked()
{
    fillStack();
    updateTextEdits();
}

void Task4Window::on_pushButtonGenerateQueue_clicked()
{
    fillQueue();
    updateTextEdits();
}

void Task4Window::fillStack()
{
    stack.clear();
    QStringList originalStackStrings;

    for (int i = 0; i < 10; ++i)
    {
        int randomValue = QRandomGenerator::global()->bounded(-10, 81);
        stack.push(randomValue % (i + 1));
        originalStackStrings.append(QString::number(randomValue));
    }

    ui->labelStack->setText("Original Stack: " + originalStackStrings.join(", "));
}

void Task4Window::fillQueue()
{
    queue.clear();
    QStringList originalQueueStrings;

    for (int i = 0; i < 8; ++i)
    {
        int randomValue = QRandomGenerator::global()->bounded(-10, 81);
        queue.enqueue(randomValue);
        originalQueueStrings.append(QString::number(randomValue));
    }

    ui->labelQueue->setText("Original Queue: " + originalQueueStrings.join(", "));

    // Create a temporary queue to store modified values
    QQueue<int> modifiedQueue;

    // Add sums according to the specified pattern
    modifiedQueue.enqueue(queue.at(0) + queue.at(7));
    modifiedQueue.enqueue(queue.at(1) + queue.at(6));
    modifiedQueue.enqueue(queue.at(2) + queue.at(5));
    modifiedQueue.enqueue(queue.at(3) + queue.at(4));
    modifiedQueue.enqueue(queue.at(4) + queue.at(3));
    modifiedQueue.enqueue(queue.at(5) + queue.at(2));
    modifiedQueue.enqueue(queue.at(6) + queue.at(1));
    modifiedQueue.enqueue(queue.at(7) + queue.at(0));

    // Display the temporary queue in textEditQueue
    QStringList modifiedQueueStrings;
    for (int value : modifiedQueue) {
        modifiedQueueStrings.append(QString::number(value));
    }

    ui->textEditQueue->clear();
    ui->textEditQueue->setText("Modified Queue: " + modifiedQueueStrings.join(", "));

    queue = modifiedQueue;
}



void Task4Window::updateTextEdits()
{
    // Update text edits with the contents of the stack and queue
    ui->textEditStack->clear();
    ui->textEditQueue->clear();

    QStringList stackStrings;
    for (int value : stack) {
        stackStrings.append(QString::number(value));
    }

    QStringList queueStrings;
    for (int value : queue) {
        queueStrings.append(QString::number(value));
    }

    ui->textEditStack->setText("Stack: " + stackStrings.join(", "));
    ui->textEditQueue->setText("Queue: " + queueStrings.join(", "));
}
