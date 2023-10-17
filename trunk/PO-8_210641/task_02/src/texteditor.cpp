#include "texteditor.h"
#include "ui_texteditor.h"

#include <QMessageBox>
#include <QFontDialog>
#include <QFileDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>

TextEditor::TextEditor(const QString &filename, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);
    QSettings settings;
    QFont defaultFont = QApplication::font();
    QFont viewFont = settings.value("viewFont", QVariant::fromValue(defaultFont)).value<QFont>();
    ui->textEdit->setFont(viewFont);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));
    connect(ui->actionSelectFont, SIGNAL(triggered()), this, SLOT(on_actionSelectFont_triggered()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    setWindowTitle("TextEditor[*]");

    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);

    loadFile(filename);

}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::on_actionNew_triggered()
{
    TextEditor *newEditor = new TextEditor;
    newEditor->updateFont(ui->textEdit->font());
    newEditor->show();
}


void TextEditor::documentModified(){
    setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e){
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified. "
                                     "Do you want to save your changes?\n"
                                     "You will lose and unsaved changes.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes:
            saveFile();
            break;
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        default:
            break;
        }
    }
    else
    {
        e->accept();
    }

}

void TextEditor::updateFont(const QFont &newFont) {
    ui->textEdit->setFont(newFont);
    QSettings settings;
    settings.setValue("viewFont", QVariant::fromValue(newFont));
}


void TextEditor::on_actionSelectFont_triggered()
{
    bool ok;
    QFont initialFont = ui->textEdit->font();
    QFont selectedFont = QFontDialog::getFont(&ok, initialFont, this);

    if (ok) {
        updateFont(selectedFont);
    }
}

void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About program",
                       "A universal tool for editing text and creating documents. It can work with several documents and has the ability to open and save, cancel actions, work with the clipboard and others.");
}

void TextEditor::loadFile(const QString &fileName){
    if (fileName.isEmpty()){
        setFileName(QString());
        return;
    }
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName(QString());
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
    setFileName(fileName);
    setWindowModified(false);
}

void TextEditor::setFileName(const QString &fileName)
{
    m_fileName = fileName;
    setWindowTitle(QString("%1[*] - %2")
                       .arg(m_fileName.isNull() ? "untitled" : QFileInfo(m_fileName).fileName())
                       .arg(QApplication::applicationName()));
}

void TextEditor::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if(fileName.isNull())
        return;
    if (m_fileName.isNull() && !isWindowModified()) {
        loadFile(fileName);
    }
    else {
        TextEditor *newEditor = new TextEditor;
        newEditor->show();
        newEditor->loadFile(fileName);
    }
}


void TextEditor::on_actionClose_triggered()
{

}


void TextEditor::on_actionExit_triggered()
{

}

bool TextEditor::saveFileAs() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    m_fileName.isNull() ? QDir::currentPath() : m_fileName, "Text documents (*.txt)");

    if (fileName.isEmpty()) {
        return false;
    }

    setFileName(fileName);
    return saveFile();
}

bool TextEditor::saveFile() {
    if (m_fileName.isNull()) {
        return saveFileAs();
    }

    QFile file(m_fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();

        setWindowModified(false);
        return true;
    } else {
        QMessageBox::warning(this, "Warning", "Can't save in this file.");
        setFileName(QString());
        return false;
    }
}

