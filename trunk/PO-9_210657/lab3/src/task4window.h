#ifndef TASK4WINDOW_H
#define TASK4WINDOW_H

#include <QDialog>
#include <QStack>
#include <QQueue>

namespace Ui {
class Task4Window;
}

class Task4Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task4Window(QWidget *parent = nullptr);
    ~Task4Window();

private slots:
    void on_pushButtonGenerateStack_clicked();
    void on_pushButtonGenerateQueue_clicked();

private:
    Ui::Task4Window *ui;
    QStack<int> stack;
    QQueue<int> queue;

    void fillStack();
    void fillQueue();
    void updateTextEdits();
};

#endif // TASK4WINDOW_H
