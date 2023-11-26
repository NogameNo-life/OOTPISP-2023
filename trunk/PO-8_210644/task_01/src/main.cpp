#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPalette>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>

class MyWindow : public QWidget {
    Q_OBJECT

public:
    MyWindow(QWidget* parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        // Создаем три слайдера
        redSlider = new QSlider(Qt::Horizontal);
        greenSlider = new QSlider(Qt::Horizontal);
        blueSlider = new QSlider(Qt::Horizontal);

        redSpinBox = new QSpinBox;
        greenSpinBox = new QSpinBox;
        blueSpinBox = new QSpinBox;

        QLabel* redLabel = new QLabel("Red");
        QLabel* greenLabel = new QLabel("Green");
        QLabel* blueLabel = new QLabel("Blue");

        // Создаем текстовое поле для предварительного просмотра цвета
        colorPreview = new QLineEdit();
        colorPreview->setReadOnly(true);

        // Подключаем сигналы слайдеров к слоту обновления цвета фона
        connect(redSlider, &QSlider::valueChanged, this, &MyWindow::updateBackgroundColor);
        connect(greenSlider, &QSlider::valueChanged, this, &MyWindow::updateBackgroundColor);
        connect(blueSlider, &QSlider::valueChanged, this, &MyWindow::updateBackgroundColor);
        connect(redSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MyWindow::updateBackgroundColor);
        connect(greenSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MyWindow::updateBackgroundColor);
        connect(blueSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MyWindow::updateBackgroundColor);

        // Устанавливаем диапазон значений для слайдеров
        redSlider->setRange(0, 255);
        greenSlider->setRange(0, 255);
        blueSlider->setRange(0, 255);

        redSpinBox->setRange(0, 255);
        greenSpinBox->setRange(0, 255);
        blueSpinBox->setRange(0, 255);

        QTextEdit* textEdit = new QTextEdit(this);

        // Добавляем кнопку
        QPushButton* openButton = new QPushButton("Open File", this);
        connect(openButton, &QPushButton::clicked, this, &MyWindow::openFile);


        // Добавляем виджеты в макет
        layout->addWidget(redLabel);
        layout->addWidget(redSlider);
        layout->addWidget(redSpinBox);
        
        layout->addWidget(greenLabel);
        layout->addWidget(greenSlider);
        layout->addWidget(greenSpinBox);
        
        layout->addWidget(blueLabel);
        layout->addWidget(blueSlider);
        layout->addWidget(blueSpinBox);

        layout->addWidget(colorPreview);

        layout->addWidget(openButton);
        layout->addWidget(textEdit);
    }

private slots:
    void updateBackgroundColor() {
        int red = redSlider->value();
        int green = greenSlider->value();
        int blue = blueSlider->value();

        redSpinBox->setValue(red);
        greenSpinBox->setValue(green);
        blueSpinBox->setValue(blue);

        // Устанавливаем цвет фона для текстового поля
        QPalette palette;
        palette.setColor(QPalette::Base, QColor(red, green, blue));
        colorPreview->setPalette(palette);
    }
    void openFile()
    {
        // Получаем имя выбранного файла
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "All Files (*)");

        // Открываем файл
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            // Читаем содержимое файла
            QTextStream in(&file);
            QString fileContent = in.readAll();

            // Помещаем содержимое в элемент QTextEdit
            QTextEdit* textEdit = findChild<QTextEdit*>();
            if (textEdit)
                textEdit->setPlainText(fileContent);

            file.close();
        }
    }

private:
    QSlider* redSlider;
    QSlider* greenSlider;
    QSlider* blueSlider;
    QSpinBox* blueSpinBox;
    QSpinBox* greenSpinBox;
    QSpinBox* redSpinBox;
    QLineEdit* colorPreview;
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MyWindow window;
    window.show();
    return a.exec();
}

#include "main.moc"
