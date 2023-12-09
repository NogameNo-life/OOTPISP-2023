// weatherform.h
#ifndef WEATHERFORM_H
#define WEATHERFORM_H

#include <QMainWindow>
#include <QtSql>
#include <QDate>

namespace Ui {
class WeatherForm;
}

class WeatherForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit WeatherForm(QWidget *parent = nullptr);
    ~WeatherForm();

private slots:
    void on_connectButton_clicked();
    void on_populateButton_clicked();
    void on_sunnyDaysButton_clicked();
    void on_periodButton_clicked();
    void on_deleteButton_clicked();

private:
    Ui::WeatherForm *ui;
    QSqlDatabase db;

    void createTables();
    void loadWeatherData();
    void showResult(QSqlQuery& query);
};

#endif // WEATHERFORM_H
