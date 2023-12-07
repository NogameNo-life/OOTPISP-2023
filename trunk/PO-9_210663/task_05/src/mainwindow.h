#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QTextEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QTableView>
#include <QSqlQueryModel>

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
    void searchPhoneNumberByFullName();
    void searchFullNameByPhoneNumber();
    void createTables();
    void displayData();

private:
    Ui::MainWindow *ui;
    QSqlDatabase sdb;
    QSqlQuery *query;
    QTableView *table;
    QGridLayout *layout;
    QTextEdit *familyNameTextBox;
    QTextEdit *nameTextBox;
    QTextEdit *phoneNumberTextBox;
    QPushButton *searchPhoneButton;
    QPushButton *searchFullNameButton;
    QSqlQueryModel *model;

};

#endif // MAINWINDOW_H
