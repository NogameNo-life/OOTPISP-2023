#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &filename=QString(), QWidget *parent = nullptr);
    ~TextEditor();

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_action_New_triggered();
    void documentEdited();

    void on_action_SelectFont_triggered();
    void on_action_About_triggered();
    void on_action_Open_triggered();

    bool save_File();
    bool save_File_As();

private:
    void loadFile(const QString &filename);
    void setFileName(const QString &filename);


    Ui::TextEditor *ui;
    QString m_fileName;
};
#endif // TEXTEDITOR_H
