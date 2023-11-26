#include "texteditor.h"//210663_main.cpp

#include <QApplication>//210663_main.cpp

int main(int argc, char *argv[])//210663_main.cpp
{
    QApplication a(argc, argv); //210663_main.cpp
    TextEditor w;//210663_main.cpp
    a.setApplicationName("Text Editor");//210663_main.cpp
    a.setApplicationVersion("0.1");//210663_main.cpp
    a.setWindowIcon(QIcon(":/tables/t1_1.png"));//210663_main.cpp
    a.setApplicationVersion("0.1");//210663_main.cpp
    a.setOrganizationName("ExampleSoft");//210663_main.cpp
    a.setOrganizationDomain("example.com");//210663_main.cpp
    w.show();//210663_main.cpp
    return a.exec();//210663_main.cpp
}
