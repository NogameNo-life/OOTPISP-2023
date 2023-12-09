#include "weatherform.h"
#include "ui_weatherform.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QLineEdit>

WeatherForm::WeatherForm(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::WeatherForm)
{
    ui->setupUi(this);

    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(on_connectButton_clicked()));
    connect(ui->populateButton, SIGNAL(clicked()), this, SLOT(on_populateButton_clicked()));
    connect(ui->sunnyDaysButton, SIGNAL(clicked()), this, SLOT(on_sunnyDaysButton_clicked()));
    connect(ui->periodButton, SIGNAL(clicked()), this, SLOT(on_periodButton_clicked()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(on_deleteButton_clicked()));
}

WeatherForm::~WeatherForm()
{
    delete ui;
}

void WeatherForm::on_connectButton_clicked()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("weather.db");

    if (db.open()) {
        createTables();
        loadWeatherData();
    } else {
        qDebug() << "Error: " << db.lastError().text();
    }
}

void WeatherForm::createTables()
{
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS day (id INTEGER PRIMARY KEY, day INTEGER, month INTEGER, year INTEGER)");
    query.exec("CREATE TABLE IF NOT EXISTS pogoda (id INTEGER PRIMARY KEY, davlenie REAL, temperat REAL, vid TEXT)");
}

void WeatherForm::on_populateButton_clicked()
{
    QSqlQuery query;
    for (int i = 1; i <= 30; ++i) {
        query.prepare("INSERT INTO day (day, month, year) VALUES (?, ?, ?)");
        query.bindValue(0, i);
        query.bindValue(1, 12); // Месяц декабрь
        query.bindValue(2, 2023); // Год 2023
        query.exec();

        query.prepare("INSERT INTO pogoda (davlenie, temperat, vid) VALUES (?, ?, ?)");
        query.bindValue(0, 760 + rand() % 10);
        query.bindValue(1, -10 + rand() % 20);
        query.bindValue(2, (rand() % 2 == 0) ? "Солнечно" : "Облачно");
        query.exec();
    }

    loadWeatherData();
}

void WeatherForm::on_sunnyDaysButton_clicked()
{
    bool ok;
    QString monthStr = QInputDialog::getText(this, tr("Enter Month"), tr("Enter the month:"), QLineEdit::Normal, "", &ok);
    if (!ok) return;

    int month = monthStr.toInt(&ok);
    if (!ok || (month < 1) || (month > 12)) {
        QMessageBox::warning(this, tr("Error"), tr("Invalid month. Please enter a number between 1 and 12."));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM day JOIN pogoda ON day.id = pogoda.id WHERE vid = 'Солнечно' AND month = ?");
    query.bindValue(0, month);
    query.exec();

    showResult(query);
}

void WeatherForm::on_periodButton_clicked()
{
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();

    if (startDate > endDate) {
        QMessageBox::warning(this, tr("Error"), tr("Start date cannot be later than end date."));
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT davlenie, temperat FROM day JOIN pogoda ON day.id = pogoda.id WHERE (year > ? OR (year = ? AND month > ?) OR (year = ? AND month = ? AND day >= ?)) AND (year < ? OR (year = ? AND month < ?) OR (year = ? AND month = ? AND day <= ?))");
    query.bindValue(0, startDate.year());
    query.bindValue(1, startDate.year());
    query.bindValue(2, startDate.month());
    query.bindValue(3, startDate.year());
    query.bindValue(4, startDate.month());
    query.bindValue(5, startDate.day());
    query.bindValue(6, endDate.year());
    query.bindValue(7, endDate.year());
    query.bindValue(8, endDate.month());
    query.bindValue(9, endDate.year());
    query.bindValue(10, endDate.month());
    query.bindValue(11, endDate.day());
    query.exec();

    ui->dataTableView->clearContents();

    int row = 0;
    ui->dataTableView->setRowCount(0);
    ui->dataTableView->setColumnCount(2);

    while (query.next()) {
        ui->dataTableView->insertRow(row);
        // Загружаем davlenie, temperat из таблицы pogoda
        ui->dataTableView->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->dataTableView->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        row++;
    }

    QMessageBox::information(this, tr("Query Result"), tr("Result: %1 rows found").arg(row));
}

void WeatherForm::loadWeatherData()
{
    QSqlQuery query("SELECT * FROM day JOIN pogoda ON day.id = pogoda.id");
    int row = 0;

    ui->dataTableView->setRowCount(0);
    ui->dataTableView->setColumnCount(6);

    while (query.next()) {
        ui->dataTableView->insertRow(row);
        // Загружаем day, month, year из таблицы day
        ui->dataTableView->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->dataTableView->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->dataTableView->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));
        // Загружаем davlenie, temperat, vid из таблицы pogoda
        ui->dataTableView->setItem(row, 3, new QTableWidgetItem(query.value(5).toString()));
        ui->dataTableView->setItem(row, 4, new QTableWidgetItem(query.value(6).toString()));
        ui->dataTableView->setItem(row, 5, new QTableWidgetItem(query.value(7).toString()));
        row++;
    }
}

void WeatherForm::showResult(QSqlQuery& query)
{
    ui->dataTableView->clearContents();
    ui->dataTableView->setRowCount(0);
    ui->dataTableView->setColumnCount(6);
    int row = 0;

    while (query.next()) {
        ui->dataTableView->insertRow(row);
        // Загружаем day, month, year из таблицы day
        ui->dataTableView->setItem(row, 0, new QTableWidgetItem(query.value(1).toString()));
        ui->dataTableView->setItem(row, 1, new QTableWidgetItem(query.value(2).toString()));
        ui->dataTableView->setItem(row, 2, new QTableWidgetItem(query.value(3).toString()));
        // Загружаем davlenie, temperat, vid из таблицы pogoda
        ui->dataTableView->setItem(row, 3, new QTableWidgetItem(query.value(5).toString()));
        ui->dataTableView->setItem(row, 4, new QTableWidgetItem(query.value(6).toString()));
        ui->dataTableView->setItem(row, 5, new QTableWidgetItem(query.value(7).toString()));
        row++;
    }

    QMessageBox::information(this, tr("Query Result"), tr("Result: %1 rows found").arg(row));
}

void WeatherForm::on_deleteButton_clicked() {
    QSqlQuery query;
    query.exec("DROP TABLE day");
    query.exec("DROP TABLE pogoda");
}

