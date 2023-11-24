#include <QCoreApplication>
#include <iostream>
#include <qDebug>
#include "concreteMazeFactory.h"
#include "concreteRoom.h"
#include "concreteDoor.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Room* r1 = MazeFactory::Instance()->makeRoom(5);
    r1->print();

    Room* r2 = MazeFactory::Instance()->makeRoom(3);
    r2->print();

    Door* d = MazeFactory::Instance()->makeDoor(r2, r1);
    d->print();


    return a.exec();

}
