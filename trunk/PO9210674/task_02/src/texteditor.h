#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditor; }
QT_END_NAMESPACE

class TextEditor : public QMainWindow
{
    Q_OBJECT

public:
    TextEditor(QWidget *parent = nullptr);
    ~TextEditor();
    TextEditor(const QString &fileName = QString(), QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *e);


private slots:
    void on_actionNew_triggered();

    void documentModified();

    void on_actionSelectFont_triggered();

    void on_actionAbout_2_triggered();

    void on_actionOpen_triggered();

    bool saveFile();
    bool saveFileAs();

private:
    Ui::TextEditor *ui;
    QString m_fileName;
    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
};
#endif // TEXTEDITOR_H
