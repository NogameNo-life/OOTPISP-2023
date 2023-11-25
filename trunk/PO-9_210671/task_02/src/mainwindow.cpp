#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Инициализация главного окна и его компонентов
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);

    // Соединение сигналов и слотов для различных действий
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    // Выключение некоторых действий по умолчанию
    ui->actionCopy->setEnabled(false);
    ui->actionPaste->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    // Загрузка файла при создании окна
    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    // Удаление объекта интерфейса при закрытии окна
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    // Создание нового главного окна при выборе "Новый"
    MainWindow *mainWindow = new MainWindow;
    mainWindow->setVisible(true);
}

void MainWindow::documentModified() {
    // Установка флага модификации окна при изменении документа
    this->setWindowModified(true);
}

void MainWindow::closeEvent(QCloseEvent *e) {
    if(this->isWindowModified())
    {
        // Проверка модификации и запрос сохранения изменений
        switch(QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified. "
                                     "Do you want to save your changes?\n"
                                     "You will lose any unsaved changes.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            // Пропущен break, что может вызвать некорректное поведение
            // при выборе QMessageBox::Yes
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        }
    }
    else
    {
        e->accept();
    }
}

void MainWindow::on_actionSelectFont_triggered()
{
    // Диалог выбора шрифта и сохранение в настройках
    bool changeFont;
    QFont font = QFontDialog::getFont(&changeFont, ui->textEdit->font(), this);
    if (changeFont) {
        QSettings settings;
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}

void MainWindow::on_actionAbout_triggered()
{
    // Отображение информации о программе
    QMessageBox::about(this, "About", "Text about program");
}

void MainWindow::loadFile(const QString &fileName)
{
    if (fileName.isNull()) {
        // Обработка случая, когда имя файла пустое
        setFileName(QString());
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        // Обработка ошибки открытия файла
        QMessageBox::warning(this, "Error", "File is not open");
        setFileName(QString());
        return;
    }

    // Чтение содержимого файла и его загрузка в текстовое поле
    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();

    // Сброс флага модификации и установка имени файла
    setWindowModified(false);
    setFileName(fileName);
}

void MainWindow::setFileName(QString fileName) {
    // Установка имени файла в заголовок окна
    m_fileName = fileName;
    setWindowTitle((fileName.isNull() ? "untitled" : fileName) + "[*] - Text Editor");
}

void MainWindow::on_actionOpen_triggered()
{
    // Диалог выбора файла для открытия
    QString fileName = QFileDialog::getOpenFileName(this, "Open...", QDir::currentPath(), "Text (*.txt)");
    if (fileName.isNull()) {
        // Обработка случая, когда имя файла пустое
        return;
    }
    if (m_fileName.isNull() && !isWindowModified()) {
        // Загрузка файла, если текущий файл не модифицирован
        loadFile(fileName);
    } else {
        // Создание нового главного окна для открытия другого файла
        MainWindow *mainWindow = new MainWindow(fileName);
        mainWindow->setVisible(true);
    }
}

bool MainWindow::saveFile() {
    if (m_fileName.isNull()) {
        // Сохранение файла, если имя файла пустое
        return saveFileAs();
    }

    // Открытие файла для записи и сохранение данных
    QFile file(m_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        // Обработка ошибки открытия файла
        QMessageBox::warning(this, "Error", "File is not open");
        setFileName(QString());
        return false;
    }

    QTextStream fout(&file);
    fout << ui->textEdit->toPlainText();
    file.close();
    // Сброс флага модификации
    setWindowModified(false);
    return true;
}

bool MainWindow::saveFileAs() {
    // Диалог выбора файла для сохранения
    QString fileName = QFileDialog::getSaveFileName(this, "Save document", m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if (fileName.isNull()) {
        // Обработка случая, когда имя файла пустое
        return false;
    }

    // Установка имени файла и сохранение файла
    setFileName(fileName);
    return saveFile();
}
