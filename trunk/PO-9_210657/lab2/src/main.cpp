#include "texteditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEditor w;
    a.setApplicationName("Text Editor");
    a.setApplicationVersion("0.1");


    a.setOrganizationName("ExampleSoft");
    a.setOrganizationDomain("example.com");
    QApplication::setWindowIcon(QIcon(":/icons/new.png"));

    w.show();
    return a.exec();
}
