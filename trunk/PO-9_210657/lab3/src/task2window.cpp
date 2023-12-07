#include "task2window.h"
#include "ui_task2window.h"
#include <QVector>
#include <QMessageBox>
#include <QTime>
#include <QInputDialog>

Task2Window::Task2Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task2Window)
{
    ui->setupUi(this);

    connect(ui->pushButtonGenerateArray, SIGNAL(clicked()), this, SLOT(on_pushButtonGenerateArray_clicked()));
    connect(ui->pushButtonFindElement, SIGNAL(clicked()), this, SLOT(on_pushButtonFindElement_clicked()));
    connect(ui->pushButtonGenerateMatrix, SIGNAL(clicked()), this, SLOT(on_pushButtonGenerateMatrix_clicked()));

    // Populate comboBox with operations
    ui->comboBoxOperation->addItem("Minimum");
    ui->comboBoxOperation->addItem("Maximum");
}

Task2Window::~Task2Window()
{
    delete ui;
}

void Task2Window::on_pushButtonGenerateArray_clicked()
{
    QVector<int> array;
    array.resize(10);

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    for (int i = 0; i < 10; ++i) {
        array[i] = rand() % 100;  // Adjust the range as needed
    }

    QString output = [&array]() {
        QString result;
        for (const int& value : array)
            result += QString::number(value) + ", ";
        return result.mid(0, result.length() - 2);  // Remove the trailing comma and space
    }();

    ui->textEditOutput->setText(output);
}

void Task2Window::on_pushButtonFindElement_clicked()
{
    // Retrieve the array from the textEdit
    QString arrayText = ui->textEditOutput->toPlainText();
    QStringList arrayStrings = arrayText.split(",", Qt::SkipEmptyParts);
    QVector<int> array;

    for (const QString &str : arrayStrings) {
        array.append(str.trimmed().toInt());

    }

    // Find the element satisfying the condition
    int result = 0;
    for (int i = 1; i < array.size() - 1; ++i) {
        if (array[0] < array[i] && array[i] < array[array.size() - 1]) {
            result = array[i];
            break;
        }
    }

    QString output = "Result: " + QString::number(result);
    ui->labelFindElementResult->setText(output);
}

void Task2Window::on_pushButtonGenerateMatrix_clicked()
{
    bool ok;
    int m = ui->lineEditRows->text().toInt(&ok);
    int n = ui->lineEditColumns->text().toInt(&ok);

    generateMatrix(m, n);
}

void Task2Window::generateMatrix(int m, int n)
{
    QVector<QVector<int>> matrix;
    matrix.resize(m);
    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    for (int i = 0; i < m; ++i) {
        matrix[i].resize(n);
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;  // Adjust the range as needed
        }
    }

    QString output = "Matrix:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            output += QString::number(matrix[i][j]) + " ";
        }

        int extrema = (ui->comboBoxOperation->currentIndex() == 0) ? *std::min_element(matrix[i].begin(), matrix[i].end()) : *std::max_element(matrix[i].begin(), matrix[i].end());
        output += QString(" | %1: %2\n").arg((ui->comboBoxOperation->currentIndex() == 0) ? "Min" : "Max").arg(extrema);
    }

    ui->textEditMatrixOutput->setText(output);
}
