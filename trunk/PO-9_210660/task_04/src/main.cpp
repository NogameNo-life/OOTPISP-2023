#include "mainwindow.h"

#include <QApplication>

// for codacy
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
