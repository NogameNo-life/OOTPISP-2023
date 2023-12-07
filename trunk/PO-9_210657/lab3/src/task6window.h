#ifndef TASK6WINDOW_H
#define TASK6WINDOW_H

#include <QDialog>

namespace Ui {
class Task6Window;
}

class Task6Window : public QDialog
{
    Q_OBJECT

public:
    explicit Task6Window(QWidget *parent = nullptr);
    ~Task6Window();

private slots:
    void on_btnExecute_clicked();

private:
    Ui::Task6Window *ui;
    void swapFiles();
    void createAndWriteToFile(const QString &fileName, const QString &content);
};

#endif // TASK6WINDOW_H
