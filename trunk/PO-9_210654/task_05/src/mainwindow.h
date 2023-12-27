#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

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
    void generateWorkersTable();
    void generateWorkTypeTable();
    void findMonthlySalaryOfWorkers();
    void findMonthlyWorkerWorkType();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
};
#endif // MAINWINDOW_H
