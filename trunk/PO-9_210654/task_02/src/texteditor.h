#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFontDialog>
#include <QSettings>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class textEditor; }
QT_END_NAMESPACE

class textEditor : public QMainWindow
{
    Q_OBJECT

public:
    textEditor(const QString &fileName = QString(), QWidget *parent = 0);
    ~textEditor();

protected:
    void closeEvent(QCloseEvent *e) override;//Уточнение закрытия изменённого документа

private slots:
    void actionNewTriggered();//Создание нового документа
    void actionOpenTriggered();//Открыте файла
    bool saveFile();//Сохранить изменения файл
    bool saveFileAs();//Сохранить файл на жёсткий диск
    void documentModified();//Документ изменён
    void actionSelectFontTriggered();//Выбор стиля шрифта документа
    void actionAboutTriggered();//О программе

private:
    Ui::textEditor *ui;
    QString m_fileName;

    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);
};
#endif // TEXTEDITOR_H
