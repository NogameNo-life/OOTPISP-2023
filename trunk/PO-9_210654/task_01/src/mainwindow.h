#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QPlainTextEdit>

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
    void redValueChanged(int value);
    void greenValueChanged(int value);
    void blueValueChanged(int value);
    void setColor();
    void openFile();

private:
    Ui::MainWindow *ui;
    struct Color {
        int red;
        int green;
        int blue;
    }color;
};
#endif // MAINWINDOW_H
