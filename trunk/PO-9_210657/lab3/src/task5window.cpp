#include "task5window.h"
#include "ui_task5window.h"
#include <QSet>
#include <QStringList>

Task5Window::Task5Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task5Window)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->pushButtonProcess, &QPushButton::clicked, this, &Task5Window::on_pushButtonProcess_clicked);
}

Task5Window::~Task5Window()
{
    delete ui;
}

void Task5Window::on_pushButtonProcess_clicked()
{
    processGirlsNames();
}

void Task5Window::processGirlsNames()
{
    // Get input from text edits
    QStringList allGirls = ui->textEditAllGirls->toPlainText().split(',', Qt::SkipEmptyParts);
    QStringList class1Girls = ui->textEditClass1Girls->toPlainText().split(',', Qt::SkipEmptyParts);
    QStringList class2Girls = ui->textEditClass2Girls->toPlainText().split(',', Qt::SkipEmptyParts);
    QStringList class3Girls = ui->textEditClass3Girls->toPlainText().split(',', Qt::SkipEmptyParts);

    // Create QSets from the input lists
    QSet<QString> setAllGirls(allGirls.begin(), allGirls.end());
    QSet<QString> setClass1Girls(class1Girls.begin(), class1Girls.end());
    QSet<QString> setClass2Girls(class2Girls.begin(), class2Girls.end());
    QSet<QString> setClass3Girls(class3Girls.begin(), class3Girls.end());

    // Calculate intersection, union, and difference of sets
    QSet<QString> intersectionSet = QSet<QString>(setClass1Girls).intersect(setClass2Girls).intersect(setClass3Girls);
    QSet<QString> unionSet = QSet<QString>(setClass1Girls).unite(setClass2Girls).unite(setClass3Girls);
    QSet<QString> differenceSet = setAllGirls.subtract(unionSet);

    // Display the result in textEditResult
    ui->textEditResult->clear();
    ui->textEditResult->append("Girls in all classes: " + joinQStringSet(intersectionSet));
    ui->textEditResult->append("\nGirls in some classes: " + joinQStringSet(unionSet));
    ui->textEditResult->append("\nGirls in no classes: " + joinQStringSet(differenceSet));
}

QString Task5Window::joinQStringSet(const QSet<QString> &set)
{
    QStringList list;
    for (const QString &item : set) {
        list.append(item);
    }
    return list.join(", ");
}
