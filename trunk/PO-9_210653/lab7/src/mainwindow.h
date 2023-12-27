#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer *timer;
    qreal angle;
    qreal posX;
    qreal posY;
    qreal pedestalX;
    qreal pedestalY;
};

#endif // MAINWINDOW_H
