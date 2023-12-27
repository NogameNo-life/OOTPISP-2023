#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QQueue>
#include <QSet>
#include <QFile>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //Задание 1
    void numbersEditEditingFinished();
    void fillWithZeroes(QStringList &list);
    //Задание 2
    void showArrayAndEvenThenOddElements();
    void showTwoDimmensionalArrayAndChangeMinAndMaxInLines();
    //Задание 3
    void listOneButMinInsteadPositive();
    void listButSmallerThanKDeleted();
    //Задание 4
    void stackButMinAndMaxSwapped();
    void queueButEvenReplacedAverage();
    //Задание 5
    void letTheFishingBegin();
    //Задание 6
    void showArrayFromFileAndEvenThenOddElementsFromOtherFiles();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
