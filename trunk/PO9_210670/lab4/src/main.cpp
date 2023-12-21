#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) //210670
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
