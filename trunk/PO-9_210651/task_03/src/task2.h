#ifndef TASK2_H
#define TASK2_H

#include <QWidget>

namespace Ui {
class task2;
}

class task2 : public QWidget
{
    Q_OBJECT

public:
    explicit task2(QWidget *parent = nullptr);
    ~task2();

private slots:
    void on_funcArr_clicked();
    void on_funcMat_clicked();

private:
    Ui::task2 *ui;
    void processArr(const QVector<int>& arr);
    void processMat(const QVector<QVector<int>>& mat);
};

#endif // TASK2_H


