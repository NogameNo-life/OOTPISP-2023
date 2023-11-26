#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QCloseEvent>
#include <QIcon>
#include <QFont>
#include <QFontDialog>
#include <QSettings>
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Определение класса MainWindow для текстового редактора
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Конструктор с параметрами по умолчанию
    MainWindow(const QString &fileName = QString(), QWidget *parent = nullptr);

    // Деструктор
    ~MainWindow();

    // Метод для установки имени файла
    void setFileName(QString fileName);

private slots:
    // Слот для действия "Новый"
    void on_actionNew_triggered();

    // Слот для обработки изменения документа
    void documentModified();

    // Слот для действия "Выбрать шрифт"
    void on_actionSelectFont_triggered();

    // Слот для действия "О программе"
    void on_actionAbout_triggered();

    // Слот для действия "Открыть"
    void on_actionOpen_triggered();

    // Метод для сохранения файла
    bool saveFile();

    // Метод для сохранения файла с выбором имени
    bool saveFileAs();

private:
    // Указатель на интерфейс главного окна
    Ui::MainWindow *ui;

    // Имя текущего файла
    QString m_fileName;

    // Метод для загрузки файла
    void loadFile(const QString &fileName);

protected:
    // Обработчик события закрытия окна
    void closeEvent(QCloseEvent *e);
};

#endif // MAINWINDOW_H
