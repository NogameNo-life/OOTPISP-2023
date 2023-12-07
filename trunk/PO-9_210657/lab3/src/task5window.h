#ifndef TASK5WINDOW_H
#define TASK5WINDOW_H

#include <QDialog>
#include <QSet>
#include <QString>

namespace Ui {
class Task5Window;
}

class Task5Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task5Window(QWidget *parent = nullptr);
    ~Task5Window();

private slots:
    void on_pushButtonProcess_clicked();

private:
    Ui::Task5Window *ui;

    void processGirlsNames();
    QString joinQStringSet(const QSet<QString> &set);
};

#endif // TASK5WINDOW_H
