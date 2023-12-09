#ifndef TASK3_H
#define TASK3_H

#include <QWidget>
#include <QList>
namespace Ui {
class task3;
}

class task3 : public QWidget
{
    Q_OBJECT

public:
    explicit task3(QWidget *parent = nullptr);
    ~task3();

private slots:
    void onExecuteClicked();

private:
    Ui::task3 *ui;
    QList<int> list1;
    QList<int> list2;

    QString listToStr(const QList<int>& list, const QString& sep);
    void updateOutput(const QString& text);

};

#endif // TASK3_H
