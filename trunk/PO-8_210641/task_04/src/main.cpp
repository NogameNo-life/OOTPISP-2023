#include "matrixdeterminant.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MatrixDeterminant w;
    w.show();
    return a.exec();
}
