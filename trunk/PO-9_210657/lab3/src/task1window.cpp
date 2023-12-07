#include "task1window.h"
#include "ui_task1window.h"
#include <QVector>
#include <QMessageBox>
#include <QString>
#include <QStringList>

Task1Window::Task1Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task1Window)
{
    ui->setupUi(this);

    connect(ui->pushButtonCalculate, SIGNAL(clicked()), this, SLOT(on_pushButtonCalculate_clicked()));
}

Task1Window::~Task1Window()
{
    delete ui;
}

void Task1Window::on_pushButtonCalculate_clicked()
{
    QString inputText = ui->lineEditInput->text();
    QStringList values = inputText.split(" ", Qt::SkipEmptyParts);

    if (values.size() != 3) {
        QMessageBox::warning(this, "Error", "Please enter exactly three values separated by spaces.");
        return;
    }

    bool conversionOk;
    QVector<int> numericValues;

    for (const QString &value : values) {
        int intValue = value.toInt(&conversionOk);
        if (!conversionOk) {
            QMessageBox::warning(this, "Error", "Invalid input. Please enter numeric values.");
            return;
        }
        numericValues.append(intValue);
    }

    QVector<int> sortedValues = numericValues;
    std::sort(sortedValues.begin(), sortedValues.end(), std::greater<int>());

    if (numericValues == sortedValues) {
        // Values are already sorted in descending order, double them
        std::transform(numericValues.begin(), numericValues.end(), numericValues.begin(), [](int x) { return 2 * x; });
    } else {
        // Values are not sorted in descending order, negate each value
        std::transform(numericValues.begin(), numericValues.end(), numericValues.begin(), std::negate<int>());
    }

    QString result = QString::number(numericValues[0]) + " " +
                     QString::number(numericValues[1]) + " " +
                     QString::number(numericValues[2]);

    ui->labelResult->setText(result);
}
