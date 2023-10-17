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
    TextEditor(const QString &fileName=QString(), QWidget *parent=0);
    ~TextEditor();

    void updateFont(const QFont &newFont);

protected:
    void closeEvent(QCloseEvent *e);

private slots:
    void on_actionNew_triggered();
    void documentModified();
    void on_actionClose_triggered();
    void on_actionExit_triggered();
    void on_actionSelectFont_triggered();
    void on_actionAbout_triggered();
    void on_actionOpen_triggered();
    bool saveFile();
    bool saveFileAs();

private:
    void loadFile(const QString &filename);
    void setFileName(const QString &fileName);

    QString m_fileName;
    Ui::TextEditor *ui;
};
#endif // TEXTEDITOR_H
