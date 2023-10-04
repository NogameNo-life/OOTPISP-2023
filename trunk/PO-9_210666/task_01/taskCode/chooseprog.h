#ifndef CHOOSEPROG_H
#define CHOOSEPROG_H

#include <QMainWindow>
#include "QGridLayout"
#include "QWidget"
#include "QPushButton"
#include "QObject"
#include "mainwindow.h"
#include "openfile.h"

namespace Ui {
class ChooseProg;
}

class ChooseProg : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseProg(QWidget *parent = nullptr);
    ~ChooseProg();

private:
    Ui::ChooseProg *ui;
    OpenFile* of;
    MainWindow* mw;

public slots:
    void openBgColor();
    void openFileOpener();
};

#endif // CHOOSEPROG_H
