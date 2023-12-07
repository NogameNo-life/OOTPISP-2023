#ifndef TASK3WINDOW_H
#define TASK3WINDOW_H

#include <QDialog>

namespace Ui {
class Task3Window;
}

class Task3Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task3Window(QWidget *parent = nullptr);
    ~Task3Window();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::Task3Window *ui;
    QList<int> list1;
    QList<int> list2;

    void fillRandomList(QList<int> &list, int size);
    void updateListWidgets();
};

#endif // TASK3WINDOW_H
