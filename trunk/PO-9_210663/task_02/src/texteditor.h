#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings> //210663_texteditor.h

#include <QFileInfo> //210663_texteditor.h

#include <QFile> //210663_texteditor.h

#include <QCloseEvent> //210663_texteditor.h

#include <QFileDialog> //210663_texteditor.h


QT_BEGIN_NAMESPACE //210663_texteditor.h

namespace Ui { class TextEditor; } //210663_texteditor.h

QT_END_NAMESPACE //210663_texteditor.h


class TextEditor : public QMainWindow //210663_texteditor.h

{
    Q_OBJECT //210669_texteditor.h //210663_texteditor.h


public:
    TextEditor(const QString &fileName=QString(),QWidget *parent = nullptr); //210663_texteditor.h

    ~TextEditor(); //210663_texteditor.h


private slots:
    void documentEdited(); //210663_texteditor.h


    void on_actionNew_triggered(); //210663_texteditor.h


    void on_actionClose_triggered(); //210663_texteditor.h


    void on_actionExit_triggered();
    //210663_texteditor.h

    void on_actionSelectFont_triggered(); //210663_texteditor.h


    void on_actionAbout_triggered(); //210663_texteditor.h


    bool saveFile(); //210663_texteditor.h


    bool saveFileAs(); //210663_texteditor.h


    void on_actionOpen_triggered(); //210663_texteditor.h


private: //210663_texteditor.h

    void loadFile(const QString &fileName); //210663_texteditor.h

    void setFileName(const QString &fileName); //210663_texteditor.h

    QString fileName; //210663_texteditor.h

    Ui::TextEditor *ui; //210663_texteditor.h

protected: //210663_texteditor.h

    void closeEvent(QCloseEvent *e); //210663_texteditor.h

};
#endif // TEXTEDITOR_H //210663_texteditor.h

