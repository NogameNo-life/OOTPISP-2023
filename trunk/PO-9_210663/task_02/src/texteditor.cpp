#include "texteditor.h"//210663_texteditor.cpp
#include "./ui_texteditor.h" //210663_texteditor.cpp

TextEditor::TextEditor(const QString &fileName,QWidget *parent) //210663_texteditor.cpp
    : QMainWindow(parent) //210663_texteditor.cpp
    , ui(new Ui::TextEditor) //210663_texteditor.cpp
{
    ui->setupUi(this); //210663_texteditor.cpp
    this->setWindowTitle(tr("Text Editor[*]")); //210663_texteditor.cpp

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close())); //210663_texteditor.cpp
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentEdited210663())); //210663_texteditor.cpp
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows())); //210663_texteditor.cpp

    connect(ui->actionPaste, SIGNAL(triggered()), ui->textEdit, SLOT(paste())); //210663_texteditor.cpp
    ui->actionPaste->setEnabled(true); //210669_texteditor.cpp
    connect(ui->actionUndo, SIGNAL(triggered()), ui->textEdit, SLOT(undo())); //210663_texteditor.cpp
    ui->actionUndo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->actionRedo, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    ui->actionRedo->setEnabled(false);
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    ui->actionCut->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool))); //210669_texteditor.cpp
    connect(ui->actionCopy, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    ui->actionCopy->setEnabled(false);
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    loadFile(fileName);
}

TextEditor::~TextEditor()
{
    delete ui;
}


void TextEditor::on_actionNew_triggered()
{
    TextEditor* newTextEditor = new TextEditor();
    newTextEditor->show();
}

//210669_texteditor.cpp
void TextEditor::on_actionClose_triggered()
{

}

void TextEditor::on_actionExit_triggered()
{

}
void TextEditor::documentEdited(){
    setWindowModified(true);
}
void TextEditor::closeEvent(QCloseEvent *e) //210663_texteditor.cpp
{
    if(isWindowModified())
    {
        switch(QMessageBox::warning(this, "Document Modified",
                                     "The document has been modified, "
                                     "do you want to save your changes?\n"
                                     "You will lose all your changes.",
                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                     QMessageBox::Cancel))
        {
        case QMessageBox::Yes: //210663_texteditor.cpp
            saveFile();
            break;
        case QMessageBox::No: //210663_texteditor.cpp
            e->accept();
            break;
        case QMessageBox::Cancel: //210663_texteditor.cpp
            e->ignore();
            break;
        }
    }
    else
    {
        e->accept();
    }
}


void TextEditor::on_actionSelectFont_triggered() //210663_texteditor.cpp
{
    bool ok;
    QFont currentFont = ui->textEdit->font();
    QFont font = QFontDialog::getFont(&ok, currentFont, this); //210663_texteditor.cpp
    if (ok) {
        QSettings settings;
        settings.setValue("View Font", font);
        ui->textEdit->setFont(font);
    }
}


void TextEditor::on_actionAbout_triggered()
{
    QMessageBox::about(this, "О программе", "Папагимабади защитайте мне все лабы");
}
void TextEditor::setFileName(const QString &filesName) { //210663_texteditor.cpp
    fileName = filesName;
    this->setWindowTitle(QString("%1[*] - %2")
                             .arg(fileName.isNull() ? "untitled" : QFileInfo(fileName).fileName())
                             .arg(QApplication::applicationName())
                         );
}
void TextEditor::loadFile(const QString &fileName)
{
    if (fileName.isNull()){
        setFileName(QString()); //210663_texteditor.cpp
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "The file is not open"); //210663_texteditor.cpp
        setFileName(QString()); //210663_texteditor.cpp
        return;
    }
    QTextStream fin(&file);
    ui->textEdit->setText(fin.readAll());
    file.close();
    setFileName(fileName);
    setWindowModified(false); //210663_texteditor.cpp

}


void TextEditor::on_actionOpen_triggered() //21066_texteditor.cpp
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open document",
                                                    QDir::currentPath(), "Text documents (*.txt)");
    if (fileName.isNull())
        return;
    if (this->fileName.isNull() && !this->isWindowModified()) //210663_texteditor.cpp
        loadFile(fileName);
    else {
        TextEditor* text_editor = new TextEditor(fileName);
        text_editor->show();
    }
}

bool TextEditor::saveFile(){ //210663_texteditor.cpp
    if (this->fileName.isNull())
        return saveFileAs();

    QFile file(this->fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "The file is not open");
        setFileName(QString());
        return false;
    }

    QTextStream fin(&file);
    fin << ui->textEdit->toPlainText();
    file.close();

    this->setWindowModified(false);
    return true;
}

bool TextEditor::saveFileAs(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document",
                                                    fileName.isNull() ? QDir::currentPath() : fileName,
                                                    "Text documents (*.txt)");
    if (fileName.isNull())
        return false;
    setFileName(fileName);
    return saveFile();
}
