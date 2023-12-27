#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updatePosition();

private:
    Ui::MainWindow *ui;
    float offSetX;
    float offSetY;
    float dx, dy;
    int objWidth, objHeight;
};
#endif // MAINWINDOW_H
