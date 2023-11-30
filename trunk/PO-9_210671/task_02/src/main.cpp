#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Создание объекта приложения
    QApplication a(argc, argv);

    // Установка свойств приложения66вывывывы
    a.setApplicationName("Text Editor");
    a.setApplicationVersion("0.1");
    a.setOrganizationName("ExampleSoft");
    a.setOrganizationDomain("example.com");
    a.setWindowIcon(QIcon(":/icons/resources/tables/t1_1.png"));

    // Создание главного окна
    MainWindow w;

    // Отображение главного окна
    w.show();

    // Запуск главного цикла приложения
    return a.exec();
}
