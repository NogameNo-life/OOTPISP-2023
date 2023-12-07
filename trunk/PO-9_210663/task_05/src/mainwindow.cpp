#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *familyLabel = new QLabel("Family:", this);
    QLabel *nameLabel = new QLabel("Name:", this);
    QLabel *phoneLabel = new QLabel("Phone Number:", this);

    familyNameTextBox = new QTextEdit(this);
    familyNameTextBox->setMaximumWidth(250);
    familyNameTextBox->setMaximumHeight(26);

    nameTextBox = new QTextEdit(this);
    nameTextBox->setMaximumWidth(250);
    nameTextBox->setMaximumHeight(26);

    phoneNumberTextBox = new QTextEdit(this);
    phoneNumberTextBox->setMaximumWidth(250);
    phoneNumberTextBox->setMaximumHeight(26);

    searchPhoneButton = new QPushButton("Search Phone by FullName");
    searchFullNameButton = new QPushButton("Search FullName by Phone");

    connect(searchPhoneButton, &QPushButton::clicked, this, &MainWindow::searchPhoneNumberByFullName);
    connect(searchFullNameButton, &QPushButton::clicked, this, &MainWindow::searchFullNameByPhoneNumber);


    layout = new QGridLayout(this);
    layout->addWidget(familyLabel, 4, 2);
    layout->addWidget(familyNameTextBox, 5, 2);
    layout->addWidget(nameLabel, 6, 2);
    layout->addWidget(nameTextBox, 7, 2);
    layout->addWidget(phoneLabel, 8, 2);
    layout->addWidget(phoneNumberTextBox, 9, 2);
    layout->addWidget(searchPhoneButton, 10, 2);
    layout->addWidget(searchFullNameButton, 11, 2);
    ui->centralwidget->setLayout(layout);

    table = new QTableView(this);
    layout->addWidget(table, 0, 0, 4, 2); // Переместил таблицу выше

    model = new QSqlQueryModel(this);

    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("address_book.sqlite");

    createTables();
    displayData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchPhoneNumberByFullName() {
    if (!sdb.open()) {
        qDebug() << "Failed to open the database!";
    } else {
        qDebug() << "Database opened!";
        QSqlQuery query;
        query.prepare("SELECT telef FROM telephone t JOIN fio f ON t.id = f.id WHERE f.family = ? AND f.name = ?");
        query.addBindValue(familyNameTextBox->toPlainText());
        query.addBindValue(nameTextBox->toPlainText());
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}

void MainWindow::searchFullNameByPhoneNumber() {
    if (!sdb.open()) {
        qDebug() << "Failed to open the database!";
    } else {
        qDebug() << "Database opened!";
        QSqlQuery query;
        query.prepare("SELECT family, name, otch FROM fio f JOIN telephone t ON f.id = t.id WHERE t.telef = ?");
        query.addBindValue(phoneNumberTextBox->toPlainText());
        query.exec();
        model->setQuery(query);
        table->setModel(model);
    }
}

void MainWindow::createTables() {
    if (!sdb.open()) {
        qDebug() << "Failed to open the database!";
    } else {
        qDebug() << "Database opened!";
        query = new QSqlQuery(sdb);
        query->exec("CREATE TABLE IF NOT EXISTS fio (id INTEGER PRIMARY KEY AUTOINCREMENT, family TEXT NOT NULL, name TEXT NOT NULL, otch TEXT NOT NULL)");
        query->exec("CREATE TABLE IF NOT EXISTS address (id INTEGER PRIMARY KEY AUTOINCREMENT, gorod TEXT NOT NULL, street TEXT NOT NULL, dom TEXT NOT NULL)");
        query->exec("CREATE TABLE IF NOT EXISTS telephone (id INTEGER PRIMARY KEY AUTOINCREMENT, telef TEXT NOT NULL)");

        // Check if tables are empty before inserting test data
        QSqlQuery checkQuery(sdb);
        checkQuery.exec("SELECT COUNT(*) FROM fio");
        checkQuery.next();
        int rowCount = checkQuery.value(0).toInt();

        if (rowCount == 0) {
            // Insert test data only if tables are empty
            query->exec("INSERT INTO fio (family, name, otch) VALUES ('Иванов', 'Иван', 'Иванович')");
            int lastFioId = query->lastInsertId().toInt();
            query->exec("INSERT INTO address (id, gorod, street, dom) VALUES (" + QString::number(lastFioId) + ", 'Город', 'Улица', 'Дом 1')");
            query->exec("INSERT INTO telephone (id, telef) VALUES (" + QString::number(lastFioId) + ", '1234567890')");
            // Insert more test data here if needed
        }

        displayData();
    }
}


void MainWindow::displayData() {
    QSqlQueryModel *queryModel = new QSqlQueryModel(this);
    QSqlQuery query(sdb);

    query.prepare("SELECT fio.id, fio.family, fio.name, fio.otch, address.gorod, address.street, address.dom, telephone.telef \
                   FROM fio \
                   LEFT JOIN address ON fio.id = address.id \
                   LEFT JOIN telephone ON fio.id = telephone.id");

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
    } else {
        queryModel->setQuery(query);
        table->setModel(queryModel);
    }
}
