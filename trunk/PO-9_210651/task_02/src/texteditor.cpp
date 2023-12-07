#include "texteditor.h"
#include "./ui_texteditor.h"

TextEditor::TextEditor(const QString &fName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditor)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified()));

    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo, SIGNAL(triggered), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo, SIGNAL(triggered), ui->textEdit, SLOT(redo()));

    ui->actionCut->setEnabled(false);
    ui->actionCopy->setEnabled(false);
    ui->actionUndo->setEnabled(false);
    ui->actionRedo->setEnabled(false);

    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveFileAs()));

    loadFile(fName);
}

TextEditor::~TextEditor()
{
    delete ui;
}

//auxiliary inscriptions
QString TextEditor::CloseModTitle = "Modified document";
QString TextEditor::CloseModText = "The Document has been modified, do you want to save it?\nOtherwise You will lose all your changes  ";
QString TextEditor::AboutTitle = "About programm";
QString TextEditor::AboutText = "0.1 Version";
QString TextEditor::FOpenErrTitle = "Error!";
QString TextEditor::FOpenErrText ="Cant open this file";
QString TextEditor::newDocTitle = "Document";
QString TextEditor::TextFFilters = "Text documents (*.txt)";
QString TextEditor::FOpenTitle = "Open file";
QString TextEditor::SaveFTitle = "Save file";


void TextEditor::on_actionNew_triggered(){
    TextEditor* text_editor = new TextEditor();
    text_editor->show();
}

void TextEditor::loadFile(const QString &fName){//loading file
    if (fName.isNull()) return setFileName();

    QFile file(fName);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) ) {
        QMessageBox::warning(this, TextEditor::FOpenErrTitle, TextEditor::FOpenErrText);
        return setFileName();
    }

    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());

    file.close();
    setFileName(fName);
    this->setWindowModified(false);
}

void TextEditor::setFileName(const QString &fName){
    this->m_fName = fName;
    this->setWindowTitle(QString("%1[*]-%2").arg(m_fName.isNull()?TextEditor::newDocTitle:QFileInfo(m_fName).fileName()).arg(QApplication::applicationName()));
}

void TextEditor::documentModified(){
    this->setWindowModified(true);
}

void TextEditor::closeEvent(QCloseEvent *e){//closing files
    if (!this->isWindowModified()) return e->accept();

    QMessageBox::StandardButton answ;
    answ = QMessageBox::warning(this, TextEditor::CloseModTitle, TextEditor::CloseModText,
    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Cancel);

    switch(answ)
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
        e->ignore();
        break;
    }

}

void TextEditor::on_actionSelectFont_triggered(){//choosing font
    bool changes;
    QFont font = QFontDialog::getFont(&changes, ui->textEdit->font(), this);
    if (changes){
        QSettings settings;
        settings.setValue("viewFont", font);
        ui->textEdit->setFont(font);
    }
}

void TextEditor::on_actionAbout_triggered(){
    QMessageBox::about(this, TextEditor::AboutTitle, TextEditor::AboutText);
}

void TextEditor::on_actionOpen_triggered(){
     QString fName = QFileDialog::getOpenFileName(this, TextEditor::FOpenTitle, QDir::currentPath(), TextEditor::TextFFilters);
    if(this->m_fName.isNull() && !this->isWindowModified()){
        loadFile(fName);
    }else{
        TextEditor* text_editor = new TextEditor(fName);
        text_editor->show();
    }
    if(fName.isNull()){
        return;
    }
}


bool TextEditor::saveFile(){
    if (this->m_fName.isNull()){
        return saveFileAs();
    }
    QFile file(this->m_fName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, TextEditor::FOpenErrTitle, TextEditor::FOpenErrText);
        setFileName();
        return false;
    }

    QTextStream stream(&file);
    stream<<ui->textEdit->toPlainText();
    file.close();
    this->setWindowModified(false);
}

bool TextEditor::saveFileAs(){
    QString fName = QFileDialog::getSaveFileName(this, TextEditor::SaveFTitle, m_fName.isNull()?QDir::currentPath():m_fName, TextEditor::TextFFilters);
    if(fName.isNull()){
        return false;
    }

    setFileName(fName);
    return saveFile();
}















