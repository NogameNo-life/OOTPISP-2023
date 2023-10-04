#include "chooseprog.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ChooseProg cp;
    cp.show();
    return app.exec();
}


