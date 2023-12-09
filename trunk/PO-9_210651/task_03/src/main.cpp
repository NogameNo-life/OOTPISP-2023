#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    task1 task1;
    task2 task2;
    task3 task3;
    task4 task4;
    task5 task5;
    task6 task6;

    task1.show();
    task2.show();
    task3.show();
    task4.show();
    task5.show();
    task6.show();
    return a.exec();
}
