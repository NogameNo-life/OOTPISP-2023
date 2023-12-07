#ifndef TASK2WINDOW_H
#define TASK2WINDOW_H

#include <QDialog>

namespace Ui {
class Task2Window;
}

class Task2Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task2Window(QWidget *parent = nullptr);
    ~Task2Window();

private slots:
    void on_pushButtonGenerateArray_clicked();
    void on_pushButtonFindElement_clicked();
    void on_pushButtonGenerateMatrix_clicked();

private:
    Ui::Task2Window *ui;
    void generateMatrix(int m, int n);
};

#endif // TASK2WINDOW_H
