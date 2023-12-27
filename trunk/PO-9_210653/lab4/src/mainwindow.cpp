#include "mainwindow.h"
#include <QGridLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QRandomGenerator>
#include <QHeaderView>
#include <QColor>

const int MATRIX_SIZE = 3;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setupUi();
}

void MainWindow::generateRandomNumbers()
{
    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            int randomNum1 = QRandomGenerator::global()->bounded(100);
            table1->setItem(row, col, new QTableWidgetItem(QString::number(randomNum1)));
            int randomNum2 = QRandomGenerator::global()->bounded(100);
            table2->setItem(row, col, new QTableWidgetItem(QString::number(randomNum2)));
        }
    }
}

void MainWindow::calculateSum()
{
    calculateResultMatrix("+");
}

void MainWindow::calculateDifference()
{
    calculateResultMatrix("-");
}

void MainWindow::calculateProduct()
{
    calculateResultMatrix("*");
}

void MainWindow::setupUi()
{
    QGridLayout *layout = new QGridLayout(this);

    table1 = new QTableWidget(this);
    table1->setRowCount(MATRIX_SIZE);
    table1->setColumnCount(MATRIX_SIZE);
    table1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    table2 = new QTableWidget(this);
    table2->setRowCount(MATRIX_SIZE);
    table2->setColumnCount(MATRIX_SIZE);
    table2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    resultTable = new QTableWidget(this);
    resultTable->setRowCount(MATRIX_SIZE);
    resultTable->setColumnCount(MATRIX_SIZE);
    resultTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    generateButton = new QPushButton("Generate", this);
    sumButton = new QPushButton("Sum", this);
    differenceButton = new QPushButton("Difference", this);
    productButton = new QPushButton("Product", this);

    layout->addWidget(table1, 0, 0);
    layout->addWidget(table2, 0, 1);
    layout->addWidget(resultTable, 0, 2);
    layout->addWidget(generateButton, 1, 0);
    layout->addWidget(sumButton, 1, 1);
    layout->addWidget(differenceButton, 1, 2);
    layout->addWidget(productButton, 1, 3);

    setLayout(layout);

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::generateRandomNumbers);
    connect(sumButton, &QPushButton::clicked, this, &MainWindow::calculateSum);
    connect(differenceButton, &QPushButton::clicked, this, &MainWindow::calculateDifference);
    connect(productButton, &QPushButton::clicked, this, &MainWindow::calculateProduct);
}

void MainWindow::resetResultTable()
{
    resultTable->clear();
}

void MainWindow::calculateResultMatrix(const QString &operation)
{
    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            int value1 = table1->item(row, col)->text().toInt();
            int value2 = table2->item(row, col)->text().toInt();
            int result;

            if (operation == "+")
                result = value1 + value2;
            else if (operation == "-")
                result = value1 - value2;
            else if (operation == "*")
                result = value1 * value2;
            else
                result = 0;

            QTableWidgetItem *item = new QTableWidgetItem(QString::number(result));
            resultTable->setItem(row, col, item);
        }
    }

    int minValue = std::numeric_limits<int>::max();
    int maxValue = std::numeric_limits<int>::min();

    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            int value = resultTable->item(row, col)->text().toInt();
            minValue = qMin(minValue, value);
            maxValue = qMax(maxValue, value);
        }
    }

    for (int row = 0; row < MATRIX_SIZE; ++row) {
        for (int col = 0; col < MATRIX_SIZE; ++col) {
            int value = resultTable->item(row, col)->text().toInt();
            if (value == minValue || value == maxValue) {
                resultTable->item(row, col)->setBackground(QColor(Qt::yellow));
            } else {
                resultTable->item(row, col)->setBackground(QColor(Qt::white));
            }
        }
    }
}
