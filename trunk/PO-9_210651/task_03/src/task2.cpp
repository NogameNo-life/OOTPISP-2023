#include "task2.h"
#include "ui_task2.h"
#include <QDebug>

task2::task2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task2)
{
    ui->setupUi(this);
    setWindowTitle("Task2");
    ui->option_oe->addItem("Even");
    ui->option_oe->addItem("Odd");

    connect(ui->funcArr, &QPushButton::clicked, this, &task2::on_funcArr_clicked);
    connect(ui->funcMat, &QPushButton::clicked, this, &task2::on_funcMat_clicked);
}


task2::~task2()
{
    delete ui;
}

void task2::on_funcArr_clicked()
{
    QString arrStr = ui->array->text();
    QStringList arrStrList = arrStr.split(" ", Qt::SkipEmptyParts);
    QVector<int> arr;
    for (const QString& num : arrStrList) {
        arr.append(num.toInt());
    }
    processArr(arr);
}

void task2::on_funcMat_clicked()
{
    QString matStr = ui->matrix->toPlainText();
    QStringList rowStr = matStr.split("\n", Qt::SkipEmptyParts);
    QVector<QVector<int>> mat;
    for (const QString& rowStr : rowStr) {
        QStringList colStr = rowStr.split(" ", Qt::SkipEmptyParts);
        QVector<int> row;
        for (const QString& num : colStr) {
            row.append(num.toInt());
        }
        mat.append(row);
    }
    processMat(mat);
}

void task2::processArr(const QVector<int>& arr)
{
    bool procECols = ui->option_oe->currentIndex() == 0;

    QVector<int> procElems;
    for (int i = 0; i < arr.size(); ++i) {
        if ((i % 2 == 0 && procECols) || (i % 2 != 0 && !procECols)) {
            procElems.append(arr[i]);
        }
    }
    QString resText = (procECols ? "Even" : "Odd") + QString(" : ") + QString::number(procElems[0]);
    for (int i = 1; i < procElems.size(); ++i) {
        resText += ", " + QString::number(procElems[i]);
    }

    ui->output->clear();
    ui->output->appendPlainText(resText);
}


void task2::processMat(const QVector<QVector<int>>& mat)
{
    bool procECols = ui->option_oe->currentIndex() == 0;
    QVector<int> colSums(mat[0].size(), 0);

    for (int j = 0; j < mat[0].size(); ++j) {
        for (int i = 0; i < mat.size(); ++i) {
            if ((j % 2 == 0 && procECols) || (j % 2 != 0 && !procECols)) {
                colSums[j] += mat[i][j];
            }
        }
    }
    QString resultText = (procECols ? "Even" : "Odd") + QString(" columns sum: ") + QString::number(colSums[0]);
    for (int i = 1; i < colSums.size(); ++i) {
        resultText += ", " + QString::number(colSums[i]);
    }

    ui->output->clear();
    ui->output->appendPlainText(resultText);
}

