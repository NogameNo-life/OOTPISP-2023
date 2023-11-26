#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication5.h"

class QtWidgetsApplication5 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication5(QWidget *parent = nullptr);
    ~QtWidgetsApplication5();

private:
    Ui::QtWidgetsApplication5Class ui;
};
