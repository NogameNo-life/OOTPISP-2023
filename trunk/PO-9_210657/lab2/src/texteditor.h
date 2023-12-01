#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(const QString &filename=QString(), QWidget *parent = nullptr);
    ~TextEditor();

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
    QString m_fileName;
    void loadFile(const QString &fileName);
    void setFileName(const QString &);



protected:
    void closeEvent(QCloseEvent *e);
};
#endif // TEXTEDITOR_H
