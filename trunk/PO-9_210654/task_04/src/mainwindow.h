#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void calculateDeterminant();
    void changeTableBackground(int i, int x, int y);
    void enterNumberInText(int i, int x, int y, char ch, QString &result,
                           QVector<QPair<int, int>> matrixIndexes, QVector<QVector<QString>> matrixString);
    void printWithDelayAfter(QString result, int delayInMS, int step);
    void clearLabels();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
