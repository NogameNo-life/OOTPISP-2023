#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_findDivisibleByTwo();
    void on_findDivisibleByThree();
    void on_findDivisibleByFour();
    void on_findDivisibleByFive();
    void on_findDivisibleBySix();
    void updateToolTip(int row, int column);

private:
    Ui::MainWindow *ui;
    void highlightNumbersDivisibleBy(int divisor);

    QShortcut *shortcutDivisibleByTwo;
    QShortcut *shortcutDivisibleByThree;
    QShortcut *shortcutDivisibleByFour;
    QShortcut *shortcutDivisibleByFive;
    QShortcut *shortcutDivisibleBySix;
};

#endif // MAINWINDOW_H
