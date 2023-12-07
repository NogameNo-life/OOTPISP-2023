#include "task3window.h"
#include "ui_task3window.h"
#include <QCheckBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>  // Add this for std::sort

Task3Window::Task3Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task3Window)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(on_pushButtonAdd_clicked()));
    // Initialize lists with random elements
    fillRandomList(list1, 10);
    fillRandomList(list2, 10);

    // Update list widgets
    updateListWidgets();
}

Task3Window::~Task3Window()
{
    delete ui;
}

void Task3Window::on_pushButtonAdd_clicked()
{
    bool addToFirstList = ui->checkBoxList1->isChecked();
    bool addToSecondList = ui->checkBoxList2->isChecked();

    QString inputText = ui->lineEdit->text();
    bool conversionOk;
    int inputValue = inputText.toInt(&conversionOk);

    if (!conversionOk)
    {
        QMessageBox::warning(this, "Error", "Invalid input. Please enter a valid integer.");
        return;
    }

    if (addToFirstList && !list1.contains(inputValue)) {
        list1.append(inputValue);
    }

    if (addToSecondList && !list2.contains(inputValue)) {
        list2.append(inputValue);
    }

    updateListWidgets();
}


void Task3Window::fillRandomList(QList<int> &list, int size)
{
    list.clear();
    for (int i = 0; i < size; ++i)
    {
        list.append(QRandomGenerator::global()->bounded(100)); // Generate random numbers between 0 and 100
    }
}

void Task3Window::updateListWidgets()
{
    // Update list widgets with the contents of the lists
    ui->listWidget1->clear();
    ui->listWidget2->clear();

    QStringList list1Strings;
    for (int value : list1) {
        list1Strings.append(QString::number(value));
    }

    QStringList list2Strings;
    for (int value : list2) {
        list2Strings.append(QString::number(value));
    }

    ui->listWidget1->addItems(list1Strings);
    ui->listWidget2->addItems(list2Strings);

    // Update text edits with the contents of the lists
    ui->textEditBeforeSort->clear();
    ui->textEditAfterSort->clear();

    ui->textEditBeforeSort->setText("List:\n" + list1Strings.join("\n"));

    QList<int> sortedList1 = list1;
    std::sort(sortedList1.begin(), sortedList1.end());

    QStringList sortedList1Strings;
    for (int value : sortedList1) {
        sortedList1Strings.append(QString::number(value));
    }

    ui->textEditAfterSort->setText("Sorted List:\n" + sortedList1Strings.join("\n"));
}
