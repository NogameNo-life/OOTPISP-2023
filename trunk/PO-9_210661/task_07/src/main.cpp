#include "l7.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    l7 w;
    w.show();
    return a.exec();
}
