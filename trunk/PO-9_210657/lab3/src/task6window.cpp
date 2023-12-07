#include "task6window.h"
#include "ui_task6window.h"
#include <QFile>
#include <QTextStream>

Task6Window::Task6Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task6Window)
{
    ui->setupUi(this);

    createAndWriteToFile("f1.txt", "Hello from f1!");
    createAndWriteToFile("f2.txt", "World from f2!");
    createAndWriteToFile("h.txt", " ");

    QFile file1("f1.txt");
    QFile file2("f2.txt");
    if(file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file1);
        ui->textEdit_f1->setText(in.readAll());
        file1.close();
    }

    if(file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file2);
        ui->textEdit_f2->setText(in.readAll());
        file2.close();
    }

}

Task6Window::~Task6Window()
{
    delete ui;
}

void Task6Window::createAndWriteToFile(const QString &fileName, const QString &content)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << content;
        file.close();
    }
}

void Task6Window::on_btnExecute_clicked()
{
    swapFiles();
}

void Task6Window::swapFiles()
{
    QString tempFilePath = "h.txt";
    QFile file1("f1.txt");
    QFile file2("f2.txt");
    QFile tempFile(tempFilePath);

    if(tempFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&tempFile);
        out << ui->textEdit_f1->toPlainText();
        tempFile.close();
    }

    if(file1.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file1);
        out << ui->textEdit_f2->toPlainText();
        file1.close();
    }

    if(file2.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QFile tempFile(tempFilePath);
        if(tempFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&tempFile);
            QTextStream out(&file2);
            out << in.readAll();
            tempFile.close();
        }
        file2.close();
    }

    if(file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file1);
        ui->textEdit_f1->setText(in.readAll());
        file1.close();
    }

    if(file2.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file2);
        ui->textEdit_f2->setText(in.readAll());
        file2.close();
    }
}
