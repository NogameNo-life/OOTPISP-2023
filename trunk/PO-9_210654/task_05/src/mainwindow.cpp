#include "mainwindow.h"
#include "./ui_mainwindow.h"

QVector<QString> monthList = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (const QString& month : monthList) {//Установка значений для comboBox
        ui->monthChoose->addItem(month);
        ui->monthChoose2->addItem(month);
    }
    ui->findMonthlySalaryOfWorkers->setEnabled(false);//Отключить поиск выборок
    ui->findMonthlyWorkerWorkType->setEnabled(false);
    this->db = QSqlDatabase::addDatabase("QSQLITE");//Подключение к БД
    QString dbName = "dataBase.sqlite";
    this->db.setDatabaseName(dbName);
    this->db.open();
    this->query = new QSqlQuery(db);//Настройка query на работу с БД
    this->query->exec("CREATE TABLE IF NOT EXISTS Person (Id INTEGER PRIMARY KEY, Name TEXT NOT NULL, SecondName TEXT NOT NULL, MidName TEXT NOT NULL);");
    this->query->exec("CREATE TABLE IF NOT EXISTS Work (Id INTEGER, Type TEXT NOT NULL, Month TEXT NOT NULL, Salary INTEGER NOT NULL);");
    connect(ui->generateSelection, &QPushButton::clicked, this, &MainWindow::generateWorkersTable);
    connect(ui->generateSelection, &QPushButton::clicked, this, &MainWindow::generateWorkTypeTable);
    connect(ui->findMonthlySalaryOfWorkers, &QPushButton::clicked, this, &MainWindow::findMonthlySalaryOfWorkers);
    connect(ui->findMonthlyWorkerWorkType, &QPushButton::clicked, this, &MainWindow::findMonthlyWorkerWorkType);
}

MainWindow::~MainWindow()
{
    this->db.close();
    delete this->query;
    delete ui;
}

void MainWindow::generateWorkersTable()
{
    this->query->exec("DELETE FROM Person");//Очистить таблицу работников
    ui->workersTable->clear();//Очистить виджет работников
    QVector<QString> nameList = {"Vasya", "Gena", "Ilya", "Grigory", "Nikita", "Katya", "Veronika", "Jana"};
    QVector<QString> secondNameList = {"Ivanov", "Smirnov", "Kuznecov", "Popov", "Vasilyev", "Petrov", "Sokolov", "Mihailov"};
    QVector<QString> midNameList = {"Ivanovich", "Aleksandrovich", "Sergeevich", "Dmitrievich", "Nikolaevich", "Andreevich", "Vladimirovich", "Petrovich"};
    QStringList workerList;//ФИО работника
    for(int i = 0; i < rand() % 6 + 5; ++i) {//Добавить записи в таблицу работников, где хотя бы одно поле отличается
        QString name = nameList[rand() % nameList.size()];
        QString secondName = secondNameList[rand() % secondNameList.size()];
        QString midName = midNameList[rand() % midNameList.size()];
        workerList.push_back(name + ' ' + secondName + ' ' + midName);//Добавление работника в список работников
        this->query->exec("SELECT EXISTS(SELECT * FROM Person WHERE Name = '" + name + "' AND SecondName = '" + secondName + "' AND MidName = '" + midName + "');");
        if (this->query->next() && query->value(0).toBool()) { --i; }
        else { this->query->exec("INSERT INTO Person (Name, SecondName, MidName) VALUES ('"+name+"', '"+secondName+"', '"+midName+"');"); }
    }
    ui->employeeChoose->clear();
    for (const QString& worker : workerList) {//Установка значений для comboBox
        ui->employeeChoose->addItem(worker);
    }
    this->query->exec("SELECT COUNT(*) FROM Person");//Установить количество записей для виджета
    this->query->next();
    ui->workersTable->setRowCount(this->query->value(0).toInt());
    this->query->exec("SELECT * FROM Person");//Установить количество столбцов для виджета
    ui->workersTable->setColumnCount(this->query->record().count());
    ui->workersTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList columnNames;//Установить название столбоцов в виджет
    for(int i = 0; i < this->query->record().count(); ++i) {
        columnNames.push_back(this->query->record().fieldName(i));
    }
    ui->workersTable->setHorizontalHeaderLabels(columnNames);
    int i = 0;//Добавить записи в виджет
    while(this->query->next()) {
        for(int j = 0; j < this->query->record().count(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(this->query->value(j).toString());
            ui->workersTable->setItem(i, j, item);
            ui->workersTable->resizeRowToContents(i);
            ui->workersTable->resizeColumnToContents(j);
        }
        ++i;
    }
    ui->findMonthlySalaryOfWorkers->setEnabled(true);//Включить поиск выборок
    ui->findMonthlyWorkerWorkType->setEnabled(true);
}

void MainWindow::generateWorkTypeTable()
{
    this->query->exec("DELETE FROM Work");//Очистить таблицу работ
    this->query->exec("SELECT Id FROM Person");
    QVector<QString> workerIdList;
    while(this->query->next()) { workerIdList.push_back(this->query->value(0).toString()); }
    QVector<QString> typeList = {"Medical", "Educational", "IT", "Finantial", "Engineering", "Sales and Marketing", "Arts and Entertainment"};
    QVector<QString> salaryList = {"300", "400", "250", "600", "700", "540", "1203", "125"};
    for(int i = 0; i < rand() % 21 + 10; ++i) {//Добавить записи в таблицу работ
        QString type = typeList[rand() % typeList.size()];
        QString month = monthList[rand() % monthList.size()];
        QString salary = salaryList[rand() % salaryList.size()];
        QString workerId = workerIdList[rand() % workerIdList.size()];
        this->query->exec("SELECT EXISTS(SELECT * FROM Work WHERE Id = '" + workerId + "' AND Type = '"+type+"' AND Month = '"+month+"');");
        if (this->query->next() && query->value(0).toBool()) { --i; }
        else { this->query->exec("INSERT INTO Work (Id, Type, Month, Salary) VALUES ('"+workerId+"', '"+type+"', '"+month+"', '"+salary+"');"); }
    }
    this->query->exec("SELECT COUNT(*) FROM Work");//Установить количество записей для виджета
    this->query->next();
    ui->workTypeTable->setRowCount(this->query->value(0).toInt());
    this->query->exec("SELECT * FROM Work");//Установить количество столбцов для виджета
    ui->workTypeTable->setColumnCount(this->query->record().count());
    ui->workTypeTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList columnNames;//Установить название столбоцов в виджет
    for(int i = 0; i < this->query->record().count(); ++i) {
        columnNames.push_back(this->query->record().fieldName(i));
    }
    ui->workTypeTable->setHorizontalHeaderLabels(columnNames);
    int i = 0;//Добавить записи в виджет
    while(this->query->next()) {
        for(int j = 0; j < this->query->record().count(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(this->query->value(j).toString());
            ui->workTypeTable->setItem(i, j, item);
            ui->workTypeTable->resizeRowToContents(i);
            ui->workTypeTable->resizeColumnToContents(j);
        }
        ++i;
    }
}

void MainWindow::findMonthlySalaryOfWorkers()
{
    QString month = ui->monthChoose->currentText();
    this->query->exec("SELECT "
                      "Person.Id, "
                      "Person.Name, "
                      "Person.SecondName, "
                      "Person.MidName, "
                      "SUM(Work.Salary) AS TotalSalary, "
                      "Work.Month "
                      "FROM Person "
                      "JOIN Work ON Person.Id = Work.Id "
                      "WHERE Work.Month = '"+month+"' "
                      "GROUP BY Person.Id;");
    ui->monthlySalaryOfWorkers->setColumnCount(this->query->record().count());
    int count = 0;
    QVector<QVector<QString>> rawValues(this->query->record().count());
    while(this->query->next()) {
        for(int i = 0; i < this->query->record().count(); ++i) {
            rawValues[count].push_back(this->query->value(i).toString());
        }
        ++count;
    }
    ui->monthlySalaryOfWorkers->setRowCount(count);
    ui->monthlySalaryOfWorkers->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->monthlySalaryOfWorkers->setSortingEnabled(true);
    QStringList columnNames;//Установить название столбоцов в виджет
    for(int i = 0; i < this->query->record().count(); ++i) {
        columnNames.push_back(this->query->record().fieldName(i));
    }
    ui->monthlySalaryOfWorkers->setHorizontalHeaderLabels(columnNames);
    for(int i = 0; i < rawValues.size(); ++i) {//Установить значения полей в каждой записи
        for(int j = 0; j < rawValues[i].size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(rawValues[i][j]);
            ui->monthlySalaryOfWorkers->setItem(i, j, item);
            ui->monthlySalaryOfWorkers->resizeRowToContents(i);
            ui->monthlySalaryOfWorkers->resizeColumnToContents(j);
        }
    }
}

void MainWindow::findMonthlyWorkerWorkType()
{
    QString employee = ui->employeeChoose->currentText();
    QStringList worker = employee.split(' ');
    QString name = worker[0];
    QString secondName = worker[1];
    QString midName = worker[2];
    QString month = ui->monthChoose2->currentText();
    this->query->exec("SELECT "
                      //"Person.Id, "
                      "Person.Name, "
                      "Person.SecondName, "
                      "Person.MidName, "
                      "Work.Type "
                      //"Work.Month "
                      "FROM Person "
                      "JOIN Work ON Person.Id = Work.Id "
                      "WHERE Work.Month = '"+month+"' AND Person.Name = '"+name+"' AND Person.SecondName = '"+secondName+"' AND Person.MidName = '"+midName+"' ;");
    ui->monthlyWorkerWorkType->setColumnCount(this->query->record().count());
    int count = 0;
    QVector<QVector<QString>> rawValues(this->query->record().count());
    while(this->query->next()) {
        for(int i = 0; i < this->query->record().count(); ++i) {
            rawValues[count].push_back(this->query->value(i).toString());
        }
        ++count;
    }
    ui->monthlyWorkerWorkType->setRowCount(count);
    ui->monthlyWorkerWorkType->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->monthlyWorkerWorkType->setSortingEnabled(true);
    QStringList columnNames;//Установить название столбоцов в виджет
    for(int i = 0; i < this->query->record().count(); ++i) {
        columnNames.push_back(this->query->record().fieldName(i));
    }
    ui->monthlyWorkerWorkType->setHorizontalHeaderLabels(columnNames);
    for(int i = 0; i < rawValues.size(); ++i) {//Установить значения полей в каждой записи
        for(int j = 0; j < rawValues[i].size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(rawValues[i][j]);
            ui->monthlyWorkerWorkType->setItem(i, j, item);
            ui->monthlyWorkerWorkType->resizeRowToContents(i);
            ui->monthlyWorkerWorkType->resizeColumnToContents(j);
        }
    }
}
