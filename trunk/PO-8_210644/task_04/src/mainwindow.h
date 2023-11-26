#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTableWidget *table;
    QGridLayout* l;
    QPushButton* generateTableButton;
    QPushButton* sumButton;
    QPushButton* avgButton;
    QPushButton* minButton;
    QPushButton* maxButton;
    QLabel* matrixSum;
    QLabel* matrixavg;
    int size = 7;
private:
    Ui::MainWindow *ui;
private slots:
    void generateTable();
    void countSum();
    void countavg();
    void findMin();
    void findMax();
};
#endif // MAINWINDOW_H
