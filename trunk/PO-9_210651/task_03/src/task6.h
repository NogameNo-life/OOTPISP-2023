#ifndef TASK6_H
#define TASK6_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <algorithm>

namespace Ui {
class task6;
}

class task6 : public QWidget
{
    Q_OBJECT

public:
    explicit task6(QWidget *parent = nullptr);
    ~task6();

private slots:
    void onexecuteClicked();


private:
    Ui::task6 *ui;
     void procFile(const QString& Fin, const QString& Fout);
};

#endif // TASK6_H
