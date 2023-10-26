#include "t1.h"
#include "t2.h"
#include "t3.h"
#include "t4.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    t1 t1;
    //t1.show();
    t2 t2;
    //t2.show();
    t3 t3;
    //t3.show();
    t4 t4;
    t4.show();

    return a.exec();
}
