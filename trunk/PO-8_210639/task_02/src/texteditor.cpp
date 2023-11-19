#include "texteditor.h"
#include "ui_texteditor.h"

textEditor::textEditor(const QString &fileName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textEditor)
{
    ui->setupUi(this);
    setWindowTitle("TextEditor[*]");
    QSettings settings;
    QFont defaultFont = QApplication::font();
    QFont viewFont = settings.value("viewFont", QVariant::fromValue(defaultFont)).value<QFont>();
    ui->textEdit->setFont(viewFont);

    ui->actionCopy210639->setEnabled(false);
    ui->actionCut210639->setEnabled(false);
    ui->actionUndo210639->setEnabled(false);
    ui->actionRedo210639->setEnabled(false);

    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->actionClose210639, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionExit210639, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(documentModified210639()));
    connect(ui->actionAbout_Qt210639, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionCut210639, SIGNAL(triggered()), ui->textEdit, SLOT(cut()));
    connect(ui->actionCopy210639, SIGNAL(triggered()), ui->textEdit, SLOT(copy()));
    connect(ui->actionPaste210639, SIGNAL(triggered()), ui->textEdit, SLOT(paste()));
    connect(ui->actionUndo210639, SIGNAL(triggered()), ui->textEdit, SLOT(undo()));
    connect(ui->actionRedo210639, SIGNAL(triggered()), ui->textEdit, SLOT(redo()));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCopy210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(copyAvailable(bool)), ui->actionCut210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(undoAvailable(bool)), ui->actionUndo210639, SLOT(setEnabled(bool)));
    connect(ui->textEdit, SIGNAL(redoAvailable(bool)), ui->actionRedo210639, SLOT(setEnabled(bool)));
    loadFile210639(fileName);
    connect(ui->actionSave210639, SIGNAL(triggered()), this, SLOT(saveFile210639()));
    connect(ui->actionSaveAS210639, SIGNAL(triggered()), this, SLOT(saveFileAs210639()));
}

textEditor::~textEditor()
{
    delete ui;
}

void textEditor::documentModified210639()
{
    this->setWindowModified(true);
}

void textEditor::closeEvent210639(QCloseEvent *e)
{
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
            if(!saveFile210639()){
               e->accept();
            }
            e->ignore();
            break;
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

void textEditor::loadFile210639(const QString &fileName){
    if (fileName.isEmpty()){
        setFileName210639(QString());
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName210639(QString());
        return;
    }
    QTextStream stream(&file);
    ui->textEdit->setText(stream.readAll());
    file.close();
    setFileName210639(fileName);
    setWindowModified(false);
}

void textEditor::setFileName210639(const QString &fileName){
    m_fileName=fileName;
    setWindowTitle(QString("%1[*] - %2")
                    .arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName())
                    .arg(QApplication::applicationName()));
}

bool textEditor::saveFileAs210639(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save document", m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if(fileName.isNull()){
        return false;
    }
    else{
        setFileName210639(fileName);
        return saveFile210639();
    }
}

bool textEditor::saveFile210639(){
    if(m_fileName.isNull()){
        return saveFileAs210639();
    }
    QFile file(m_fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Warning", "Can't open this file");
        setFileName210639(QString());
        return false;
    }
    else{
        QTextStream out_stream(&file);
        out_stream << ui->textEdit->toPlainText();
        file.close();
        setWindowModified(false);
        return true;
    }
}

void textEditor::on_actionNew210639_triggered()
{
    textEditor *texteditor= new textEditor();
    texteditor->show();
}

void textEditor::on_actionSelectFont210639_triggered()
{
    bool ok;
    QFont font;
    QFont initial = ui->textEdit->font();
    font = QFontDialog::getFont(&ok, initial, this);
    if(ok){
        ui->textEdit->setFont(font);
        QSettings settings;
        settings.setValue("viewFont", QVariant::fromValue(font));
    }
}

void textEditor::on_actionAbout210639_triggered()
{
    QMessageBox::about(this, "About", "Text editor.");
}


void textEditor::on_actionOpen210639_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open document", QDir::currentPath(), "Text documents (*.txt)");
    if(fileName.isNull()){
        return;
    }
    if(m_fileName.isNull() && !isWindowModified()){
        loadFile210639(fileName);
    }
    else{
        textEditor *texteditor = new textEditor(fileName);
        texteditor->show();
    }
}

