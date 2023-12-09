#include "task6.h"
#include "ui_task6.h"

task6::task6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task6)
{
    ui->setupUi(this);
    setWindowTitle("Task6");

    connect(ui->execute, &QPushButton::clicked, this, &task6::onexecuteClicked);
    onexecuteClicked();
}

task6::~task6()
{
    delete ui;
}

void task6::onexecuteClicked()
{
    procFile(ui->fin->text(),ui->fout->text());
}


void task6::procFile(const QString& Fin, const QString& Fout) {
    qDebug() << "Input file path:" << Fin;
    qDebug() << "Output file path:" << Fout;

    QFile inFile(Fin);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cant open this file";
        return;
    }

    QTextStream inStream(&inFile);
    QVector<int> fData;

    while (!inStream.atEnd()) {
        QString line = inStream.readLine();
        bool convOk = false;
        int value = line.toInt(&convOk);
        if (convOk) {
            fData.append(value);
        }
    }

    inFile.close();


    QFile outFile(Fout);
    if (!outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cant open this file";
        return;
    }

    QTextStream outStream(&outFile);

    int size = 5;
    int group = (fData.size() + size - 1) / size;

    for (int i = 0; i < group; ++i) {
        int start = i * size;
        int end = std::min((i + 1) * size, static_cast<int>(fData.size()));
        int maxEl = *std::max_element(fData.begin() + start, fData.begin() + end);

        outStream << maxEl << "\n";
    }

    outFile.close();
}
