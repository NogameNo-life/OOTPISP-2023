#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CustomWidget widget;
    widget.resize(800, 600);
    widget.show();

    return app.exec();
}
