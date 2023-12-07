#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFont>
#include <QFontDialog>
#include <QFlags>
#include <QVariant>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QSettings>
#include <QDir>

#include "./ui_texteditor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &fName= QString(), QWidget *parent = nullptr);
    ~TextEditor();


protected:
    void closeEvent(QCloseEvent *e);


private slots:
    void on_actionNew_triggered();
    void documentModified();
    void on_actionSelectFont_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();

    bool saveFile();
    bool saveFileAs();

private:
    Ui::TextEditor *ui;

    QString m_fName;

    static QString CloseModTitle;
    static QString CloseModText;

    static QString AboutTitle;
    static QString AboutText;

    static QString FOpenErrTitle;
    static QString FOpenErrText;

    static QString newDocTitle;
    static QString TextFFilters;
    static QString FOpenTitle;
    static QString SaveFTitle;

    void loadFile(const QString &fName);
    void setFileName(const QString &fName = QString());

};
#endif // TEXTEDITOR_H
