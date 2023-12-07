#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include <QToolTip>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    shortcutDivisibleByTwo = new QShortcut(QKeySequence(Qt::Key_2 | Qt::ShiftModifier), this);
    shortcutDivisibleByThree = new QShortcut(QKeySequence(Qt::Key_3 | Qt::ShiftModifier), this);
    shortcutDivisibleByFour = new QShortcut(QKeySequence(Qt::Key_4 | Qt::ShiftModifier), this);
    shortcutDivisibleByFive = new QShortcut(QKeySequence(Qt::Key_5 | Qt::ShiftModifier), this);
    shortcutDivisibleBySix = new QShortcut(QKeySequence(Qt::Key_6 | Qt::ShiftModifier), this);

    connect(shortcutDivisibleByTwo, &QShortcut::activated, this, &MainWindow::on_findDivisibleByTwo);
    connect(shortcutDivisibleByThree, &QShortcut::activated, this, &MainWindow::on_findDivisibleByThree);
    connect(shortcutDivisibleByFour, &QShortcut::activated, this, &MainWindow::on_findDivisibleByFour);
    connect(shortcutDivisibleByFive, &QShortcut::activated, this, &MainWindow::on_findDivisibleByFive);
    connect(shortcutDivisibleBySix, &QShortcut::activated, this, &MainWindow::on_findDivisibleBySix);

    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &MainWindow::updateToolTip);
    connect(ui->btnDivisibleByTwo, &QPushButton::clicked, this, &MainWindow::on_findDivisibleByTwo);
    connect(ui->btnDivisibleByThree, &QPushButton::clicked, this, &MainWindow::on_findDivisibleByThree);
    connect(ui->btnDivisibleByFour, &QPushButton::clicked, this, &MainWindow::on_findDivisibleByFour);
    connect(ui->btnDivisibleByFive, &QPushButton::clicked, this, &MainWindow::on_findDivisibleByFive);
    connect(ui->btnDivisibleBySix, &QPushButton::clicked, this, &MainWindow::on_findDivisibleBySix);

    // Initialize the table with random numbers
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(QString::number(QRandomGenerator::global()->bounded(1, 101))));
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::highlightNumbersDivisibleBy(int divisor) {
    int count = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
            int number = item->text().toInt();
            if (number % divisor == 0) {
                item->setBackground(QColor(255, 255, 100));  // Yellow background for divisible numbers
                count++;
            }
            else {
                item->setBackground(QColor(255, 255, 255));
            }
        }
    }
    ui->lblResult->setText(QString("Найдено чисел: %1").arg(count));
}

void MainWindow::on_findDivisibleByTwo() {
    highlightNumbersDivisibleBy(2);
}

void MainWindow::on_findDivisibleByThree() {
    highlightNumbersDivisibleBy(3);
}

void MainWindow::on_findDivisibleByFour() {
    highlightNumbersDivisibleBy(4);
}

void MainWindow::on_findDivisibleByFive() {
    highlightNumbersDivisibleBy(5);
}

void MainWindow::on_findDivisibleBySix() {
    highlightNumbersDivisibleBy(6);
}

void MainWindow::updateToolTip(int row, int column) {
    QTableWidgetItem *item = ui->tableWidget->item(row, column);
    if (item) {
        QToolTip::showText(ui->tableWidget->mapToGlobal(QPoint(0, 0)), QString("Значение: %1").arg(item->text()));
    }
}
