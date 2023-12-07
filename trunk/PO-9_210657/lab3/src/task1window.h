#ifndef TASK1WINDOW_H
#define TASK1WINDOW_H

#include <QDialog>

namespace Ui {
class Task1Window;
}

class Task1Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task1Window(QWidget *parent = nullptr);
    ~Task1Window();

private slots:
    void on_pushButtonCalculate_clicked();

private:
    Ui::Task1Window *ui;
};

#endif // TASK1WINDOW_H
