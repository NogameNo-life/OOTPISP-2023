#include "weatherform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WeatherForm w;
    w.show();
    return a.exec();
}
