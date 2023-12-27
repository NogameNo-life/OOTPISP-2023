#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QTableWidget;
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void generateRandomNumbers();
    void calculateSum();
    void calculateDifference();
    void calculateProduct();

private:
    void setupUi();
    void resetResultTable();
    void calculateResultMatrix(const QString &operation);

    QTableWidget *table1;
    QTableWidget *table2;
    QTableWidget *resultTable;
    QPushButton *generateButton;
    QPushButton *sumButton;
    QPushButton *differenceButton;
    QPushButton *productButton;
};

#endif // MAINWINDOW_H
