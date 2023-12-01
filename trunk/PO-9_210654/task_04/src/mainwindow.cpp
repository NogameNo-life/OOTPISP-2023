#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearLabels();
    connect(ui->generateMatrix, &QPushButton::clicked, this, &MainWindow::calculateDeterminant);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateDeterminant()
{
    clearLabels();
    QVector<QVector<int>> matrix(3, QVector<int>(3));
    QVector<int> triplets(6, 1);
    QVector<QVector<QString>> matrixString(3, QVector<QString>(3));
    QVector<QPair<int, int>> matrixIndexes(18);
    QString result;
    int delayInMS = 500, leftHalfDeterminant = 0, rightHalfDeterminant = 0,
        determinant = 0, step = 1;
    ui->matrix->setRowCount(matrix.size());
    ui->matrix->setColumnCount(matrix[0].size());
    ui->matrix->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < matrix.size(); ++i) {//Запись изначального массива
        for(int j = 0; j < matrix[i].size(); ++j) {
            matrix[i][j] = rand() % 100 + 1;
            matrixString[i][j] = QString::number(matrix[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(matrix[i][j]));
            ui->matrix->setItem(i, j, item);
            ui->matrix->resizeRowToContents(i);
            ui->matrix->resizeColumnToContents(j);
        }
    }
    matrixIndexes[0] = QPair(0, 0); matrixIndexes[1] = QPair(1, 1); matrixIndexes[2] = QPair(2, 2);
    matrixIndexes[3] = QPair(0, 1); matrixIndexes[4] = QPair(1, 2); matrixIndexes[5] = QPair(2, 0);
    matrixIndexes[6] = QPair(0, 2); matrixIndexes[7] = QPair(1, 0); matrixIndexes[8] = QPair(2, 1);
    matrixIndexes[9] = QPair(0, 2); matrixIndexes[10] = QPair(1, 1); matrixIndexes[11] = QPair(2, 0);
    matrixIndexes[12] = QPair(0, 1); matrixIndexes[13] = QPair(1, 0); matrixIndexes[14] = QPair(2, 2);
    matrixIndexes[15] = QPair(0, 0); matrixIndexes[16] = QPair(1, 2); matrixIndexes[17] = QPair(2, 1);
    result = "Шаг 1: ";
    for (int i = 0; i < matrixIndexes.size() / 2; ++i) {//Выделить положительные части определитея
        int x = matrixIndexes[i].first, y = matrixIndexes[i].second;
        changeTableBackground(i, x, y);
        enterNumberInText(i, x, y, '+', result, matrixIndexes, matrixString);
        printWithDelayAfter(result, delayInMS, step);
    }
    for (int i = matrixIndexes.size() / 2; i < matrixIndexes.size(); ++i) {//Выделить отрицательные части определителя
        int x = matrixIndexes[i].first, y = matrixIndexes[i].second;
        changeTableBackground(i, x, y);
        enterNumberInText(i, x, y, '-', result, matrixIndexes, matrixString);
        printWithDelayAfter(result, delayInMS, step);
    }
    result = "Шаг 2: ";
    step = 2;
    for(int i = 0; i < triplets.size(); ++i) {//Расчитываем произведение троек
        for(int j = 0; j < 3; ++j) {
            int x = matrixIndexes[i * 3 + j].first, y = matrixIndexes[i * 3 + j].second;
            triplets[i] *= matrix[x][y];
            changeTableBackground(j, x, y);
        }
        QString triplet = QString::number(triplets[i]);
        if(i < triplets.size() / 2 - 1) { result += triplet + " + "; }
        else if ( i < triplets.size() - 1) { result += triplet + " - "; }
        else { result += triplet; }
        printWithDelayAfter(result, delayInMS, step);
    }
    result = "Шаг 3: ";
    step = 3;
    for(int i = 0; i < triplets.size(); ++i) {
        //Расчёт левой и правой части определителя
        if (i < triplets.size() / 2) { leftHalfDeterminant += triplets[i]; }
        else { rightHalfDeterminant -= triplets[i]; }
        //Запись левой и правой части определителя в формате a - b
        if ( i == triplets.size() / 2) { result += QString::number(leftHalfDeterminant); }
        else if (i == triplets.size() - 1) {//модуль на случай отрицательности числа
            result +=  " - " + QString::number(abs(rightHalfDeterminant));
        }
    }
    printWithDelayAfter(result, delayInMS, step);
    determinant = leftHalfDeterminant + rightHalfDeterminant;
    result = "Шаг 4: " + QString::number(determinant);
    step = 4;
    printWithDelayAfter(result, delayInMS, step);
}

void MainWindow::changeTableBackground(int i, int x, int y)
{
    if (i % 3 == 0) {//Очистить подсвеченные элементы матрицы, подсветив следующий элемент
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                ui->matrix->item(j, k)->setBackground(QColor(255, 255, 255));
            }
        }
        ui->matrix->item(x, y)->setBackground(QColor(0, 255, 0));
    }
    else {
        ui->matrix->item(x, y)->setBackground(QColor(0, 255, 0));//Подсветить следующий элемент
    }
}

void MainWindow::enterNumberInText(int i, int x, int y, char ch, QString &result,
                                   QVector<QPair<int, int>> matrixIndexes, QVector<QVector<QString>> matrixString)
{
    switch(ch) {
    case '+':{
        if ((i + 1) % 3 == 0) {//Запись в формате: a*b*c + d*e*f + g*h*i -
            if (i != matrixIndexes.size() / 2 - 1) { result += matrixString[x][y] + " + "; }
            else { result += matrixString[x][y] + " - "; }
        }
        else {
            result += matrixString[x][y] + " * ";
        }
        break;
    }
    case '-': {
        if ((i + 1) % 3 == 0) {//Запись в формате: a*b*c - d*e*f - g*h*i
            if (i != matrixIndexes.size() - 1) { result += matrixString[x][y] + " - "; }
            else { result += matrixString[x][y]; }
        }
        else { result += matrixString[x][y] + " * "; }
        break;
    }
    }
}

void MainWindow::printWithDelayAfter(QString result, int delayInMS, int step)
{
    switch(step) {
    case 1: ui->calculationProcessOne->setText(result); break;
    case 2: ui->calculationProcessTwo->setText(result); break;
    case 3: ui->calculationProcessThree->setText(result); break;
    case 4: ui->calculationProcessFour->setText(result); break;
    }
    QCoreApplication::processEvents();
    QThread::msleep(delayInMS);
}

void MainWindow::clearLabels()
{
    ui->calculationProcessOne->setText("");
    ui->calculationProcessTwo->setText("");
    ui->calculationProcessThree->setText("");
    ui->calculationProcessFour->setText("");
}


