#include "task3.h"
#include "ui_task3.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>


task3::task3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task3)
{
    ui->setupUi(this);
    setWindowTitle("Task3");

    std::srand(std::time(nullptr));
    for (int i = 0; i < 10; ++i) {
        list1.append(std::rand() % 100);
        list2.append(std::rand() % 100);
    }
    connect(ui->Execute, &QPushButton::clicked, this, &task3::onExecuteClicked);
}


task3::~task3()
{
    delete ui;
}

QString task3::listToStr(const QList<int>& list, const QString& sep)
{
    QStringList strList;
    for (const auto& elem : list) {
        strList.append(QString::number(elem));
    }
    return strList.join(sep);
}


void task3::updateOutput(const QString& text)
{
    ui->Output->clear();
    ui->Output->append(text);
}


void task3::onExecuteClicked()
{
    if (ui->AddEl->isChecked()) {
        int newEl = std::rand() % 100;
        list1.append(newEl);
        updateOutput("Added element: " + QString::number(newEl) + "\nList 1 after adding: " + listToStr(list1, ", "));
    } else if (ui->RemoveEl->isChecked()) {
        if (!list1.isEmpty()) {
            int remEl = list1.takeFirst();
            updateOutput("Removed element: " + QString::number(remEl) + "\nList 1 after removal: " + listToStr(list1, ", "));
        } else {
            updateOutput("List 1 is empty");
        }
    } else if (ui->ReplaceList->isChecked()) {
        list1.swap(list2);
        updateOutput("List 1 after replacement: " + listToStr(list1, ", ") + "\nList 2 after replacement: " + listToStr(list2, ", "));
    } else {
        updateOutput("Select action, please");
    }
}








