#include "texteditor.h"
#include "./ui_texteditor.h"

textEditor::textEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textEditor)
{
    ui->setupUi(this);
    QApplication::setApplicationName("Текстовый редактор");//название окна
    //Установка иконки окна
    QIcon icon(":/icons/Resources/new.png");
    QApplication::setWindowIcon(icon);
    //Загрузка сохранённого шрифта
    QSettings settings("ExampleSoft", "Text Editor");//Изменение шрифта
    QFont savedFont = settings.value("viewFont", QApplication::font()).value<QFont>();
    ui->textEdit->setFont(savedFont);
    //Работа с окном
    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);
    this->setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &textEditor::documentModified);
    //Файл
    connect(ui->actionNew, &QAction::triggered, this, &textEditor::actionNewTriggered);
    connect(ui->actionOpen, &QAction::triggered, this, &textEditor::actionOpenTriggered);
    connect(ui->actionSave, &QAction::triggered, this, &textEditor::saveFile);
    connect(ui->actionSaveAs, &QAction::triggered, this, &textEditor::saveFileAs);
    connect(ui->actionClose, &QAction::triggered, this, &textEditor::close);
    connect(ui->actionExit, &QAction::triggered, qApp, &QApplication::closeAllWindows);
    //Вид
    connect(ui->actionSelectFont, &QAction::triggered, this, &textEditor::actionSelectFontTriggered);
    //Правка
    connect(ui->actionCut, &QAction::triggered, ui->textEdit, &QTextEdit::cut);
    connect(ui->actionCopy, &QAction::triggered, ui->textEdit, &QTextEdit::copy);
    connect(ui->actionPaste, &QAction::triggered, ui->textEdit, &QTextEdit::paste);
    connect(ui->actionUndo, &QAction::triggered, ui->textEdit, &QTextEdit::undo);
    connect(ui->actionRedo, &QAction::triggered, ui->textEdit, &QTextEdit::redo);
    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCut, &QAction::setEnabled);//Позволить вырезание
    connect(ui->textEdit, &QTextEdit::copyAvailable, ui->actionCopy, &QAction::setEnabled);//Позволить копирование
    connect(ui->textEdit, &QTextEdit::undoAvailable, ui->actionUndo, &QAction::setEnabled);//Позволить отмену
    connect(ui->textEdit, &QTextEdit::redoAvailable, ui->actionRedo, &QAction::setEnabled);//Позволить восстановление
    //Справка
    connect(ui->actionAbout, &QAction::triggered, this, &textEditor::actionAboutTriggered);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
    loadFile(fileName);
}

textEditor::~textEditor()
{
    delete ui;
}

void textEditor::actionNewTriggered()//Создание нового документа
{
    textEditor *obj = new textEditor;
    obj->show();
}

void textEditor::actionOpenTriggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open document", QDir::currentPath(), "Text documents (*.txt)");

    if (fileName.isNull()) { return; }

    if (m_fileName.isNull() && !ui->textEdit->document()->isModified()) { loadFile(fileName); }
    else {
        textEditor* newWindow = new textEditor(fileName);
        newWindow->show();
    }
}

bool textEditor::saveFile()
{
    if (m_fileName.isNull()) {
        return saveFileAs();
    }

    QFile file(m_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("Error"), tr("Failed to save the file."));
        setFileName(QString());
        return false;
    }

    QTextStream stream(&file);
    stream << ui->textEdit->toPlainText();
    file.close();

    setWindowModified(false);
    return true;
}

bool textEditor::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    m_fileName.isNull() ? QDir::currentPath() : m_fileName, "Text documents (*.txt)");

    if (fileName.isNull()) {
        return false;
    }

    setFileName(fileName);
    return saveFile();
}

void textEditor::documentModified()//Документ изменён
{
    setWindowModified(true);//установить статус
}

void textEditor::closeEvent(QCloseEvent *e)//Уточнение закрытия изменённого документа
{
        if(isWindowModified())
        {
            switch(QMessageBox::warning(this,
                                        "Документ изменён",
                                        "Вы хотите сохранить изменения?\n"
                                        "Вы потеряете несохранённые изменения.",
                                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                        QMessageBox::Cancel
                                        ))
            {
            case QMessageBox::Yes:
                if(saveFile()) { e->accept(); }
                else e->ignore();
                break;
            case QMessageBox::No:
                e->accept();
                break;
            case QMessageBox::Cancel:
                e->ignore();
                break;
            }
        }
        else { e->accept(); }
}

void textEditor::actionSelectFontTriggered()//Выбор стиля шрифта документа
{
    bool ok;
    QFont initialFont = ui->textEdit->font();
    QFont selectedFont = QFontDialog::getFont(&ok, initialFont, this);
    if (ok)
    {
        ui->textEdit->setFont(selectedFont);
        QSettings settings("ExampleSoft", "Text Editor");
        settings.setValue("viewFont", selectedFont);
    }
}

void textEditor::actionAboutTriggered()
{
    QMessageBox::about(this, "О программе", "Название программы: Текстовый редактор\n"
                                            "Версия программы: 0.1\n"
                                            "Название компании: Пример программного обеспечения\n"
                                            "Сайт компнаии: example.com"
                       );
}

void textEditor::loadFile(const QString &fileName)
{
    if (fileName.isEmpty()) {
        setFileName(QString());
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open the file.");
        setFileName(QString());
        return;
    }

    QTextStream stream(&file);
    QString fileContent = stream.readAll();
    file.close();

    ui->textEdit->setPlainText(fileContent);
    setFileName(fileName);
    setWindowModified(false);
}

void textEditor::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    QString windowTitle = QString("%1[*] - %2")
                              .arg(m_fileName.isNull() ? "untitled" : QFileInfo(m_fileName).fileName())
                              .arg(QApplication::applicationName());
    setWindowTitle(windowTitle);
}
