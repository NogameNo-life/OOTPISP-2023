#include <QApplication>
#include <QMainWindow>
#include <QTextStream>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QLabel>
#include <QMessageBox>
#include <QListWidget>
#include <QInputDialog>
#include <QRandomGenerator>
#include <QStack>
#include <QQueue>
#include <QStringList>
#include <QFile>
#include <QFileDialog>

#include <iostream>

void task1()
{
    QWidget *w = new QWidget;

    QVBoxLayout* layout = new QVBoxLayout(w);
    QLineEdit *lineEditX = new QLineEdit;
    QLineEdit *lineEditY = new QLineEdit;
    QPushButton *button = new QPushButton("&Выполнить операцию");

    layout->addWidget(new QLabel("Введите значения A и B:"));
    layout->addWidget(new QLabel("A:"));
    layout->addWidget(lineEditX);
    layout->addWidget(new QLabel("B:"));
    layout->addWidget(lineEditY);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, w, [=]{
        int A = lineEditX->text().toInt();
        int B = lineEditY->text().toInt();

        if (A != B) {
            A = A + B;
            B = A;
        } else {
            A = 0;
            B = 0;
        }

        lineEditX->setText(QString::number(A));
        lineEditY->setText(QString::number(B));

        QMessageBox::information(w, "Результат", QString("A: %1, B: %2").arg(A).arg(B));
    });

    w->show();
}


void task2()
{
    //Дана матрица размера m x n. В каждой строке найти количество элементов, больших среднего арифметического всех элементов этой строки.
    const int rows = 3;
    const int cols = 4;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QTableWidget *tableWidget = new QTableWidget(rows, cols);
    QPushButton *calculateButton = new QPushButton("Подсчитать");
    QLabel *resultLabel = new QLabel("Результат:");

    layout->addWidget(tableWidget);
    layout->addWidget(calculateButton);
    layout->addWidget(resultLabel);

    QObject::connect(calculateButton, &QPushButton::clicked, widget, [=]() {
        QString result;
        for (int row = 0; row < rows; ++row) {
            int sum = 0;
            int countGreater = 0;

            for (int col = 0; col < cols; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (!item) continue;

                int value = item->text().toInt();
                sum += value;
            }

            double avg = static_cast<double>(sum) / cols;

            for (int col = 0; col < cols; ++col) {
                QTableWidgetItem *item = tableWidget->item(row, col);
                if (!item) continue;

                int value = item->text().toInt();
                if (value > avg) {
                    countGreater++;
                }
            }

            result += QString("В строке %1 элементов больше среднего: %2\n").arg(row + 1).arg(countGreater);
        }

        resultLabel->setText(result);
    });

    srand(time(nullptr));
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int value = rand() % 100;
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(value));
            tableWidget->setItem(row, col, item);
        }
    }

    widget->show();
}

void task3()
{
    const int itemCount = 30;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    QListWidget *listWidget = new QListWidget();
    QPushButton *removeButton = new QPushButton("Удалить элементы с N по K");
    QPushButton *sortButton = new QPushButton("Отсортировать по убыванию");

    layout->addWidget(listWidget);
    layout->addWidget(removeButton);
    layout->addWidget(sortButton);

    // Заполнение списка случайными элементами
    for (int i = 0; i < itemCount; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(100);
        listWidget->addItem(QString::number(randomValue));
    }

QObject::connect(removeButton, &QPushButton::clicked, widget, [=]() {
        bool ok1, ok2;
        int start = QInputDialog::getInt(widget, "Введите N", "N:", 0, 0, listWidget->count() - 1, 1, &ok1);
        int end = QInputDialog::getInt(widget, "Введите K", "K:", listWidget->count() - 1, 0, listWidget->count() - 1, 1, &ok2);

        if (ok1 && ok2) {
            while (end >= start && end < listWidget->count()) {
                QListWidgetItem *item = listWidget->takeItem(start);
                delete item;
                ++end;
            }
        }
    });

    QObject::connect(sortButton, &QPushButton::clicked, widget, [=]() {
        QList<int> values;

        for (int i = 0; i < listWidget->count(); ++i) {
            values << listWidget->item(i)->text().toInt();
        }

        std::sort(values.begin(), values.end(), std::greater<int>());

        listWidget->clear();

        for (const auto &value : values) {
            listWidget->addItem(QString::number(value));
        }
    });

    widget->show();
}

void task4()
{
    QWidget *widget = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout(widget);

    QLabel *stackLabel1 = new QLabel("Стек до замены значений:");
    QStack<int> myStack;
    myStack << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100 << rand() % 100;

    layout->addWidget(stackLabel1);
    for (int i = 0; i < myStack.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myStack[i]));
        layout->addWidget(label);
    }

    QStack<int> newStack;
    for (int i = 0; i < myStack.size(); ++i) {
        newStack << myStack[i] * myStack[myStack.size() - 1 - i];
    }

    QLabel *stackLabel = new QLabel("Стек после замены значений:");
    layout->addWidget(stackLabel);

    while (!newStack.isEmpty()) {
        QLabel *label = new QLabel(QString::number(newStack.top()));
        layout->addWidget(label);
        newStack.pop();
    }

    QQueue<int> myQueue;
    srand(time(NULL));
    for (int i = 0; i < 8; ++i) {
        int randomNumber = rand() % 71 - 20;
        myQueue.enqueue(randomNumber);
    }

    QLabel *queueLabel1 = new QLabel("Очередь случайных чисел:");
    layout->addWidget(queueLabel1);

    for (int i = 0; i < myQueue.size(); ++i) {
        QLabel *label = new QLabel(QString::number(myQueue[i]));
        layout->addWidget(label);
    }

    QQueue<double> averageQueue;
    for (int i = 0; i < myQueue.size() - 1; ++i) {
        double average = (myQueue[i] + myQueue[i + 1]) / 2.0;
        averageQueue.enqueue(average);
    }

    QLabel *queueLabel2 = new QLabel("Очередь средних значений:");
    layout->addWidget(queueLabel2);

    while (!averageQueue.isEmpty()) {
        QLabel *label = new QLabel(QString::number(averageQueue.head()));
        layout->addWidget(label);
        averageQueue.dequeue();
    }


    widget->show();
}

void task5()
{
    QMap<QString, QStringList> cars = {
        {"Toyota", {"USA", "Canada", "Japan", "Germany", "Spain"}},
        {"Lada", {}},
        {"Citroën", {"USA", "France"}},
        {"Mitsubishi", {"USA", "Canada", "Japan"}},
        {"Hyundai", {"Germany"}}
    };

    QStringList allCountries;
    QStringList someCountries;
    QStringList noCountries;

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);

    for (auto it = cars.begin(); it != cars.end(); ++it) {
        const QString &car = it.key();
        const QStringList &countries = it.value();

        QLabel *labelCar = new QLabel("Марка: " + car);
        layout->addWidget(labelCar);

        QLabel *labelCountries = new QLabel("Доставлена в страны: " + countries.join(", "));
        layout->addWidget(labelCountries);

        layout->addSpacing(1);
    }

    for (auto it = cars.begin(); it != cars.end(); ++it) {
        const QStringList &countries = it.value();

        if (countries.size() == static_cast<int>(cars.size())) {
            allCountries << it.key();
        }
        else if (countries.size() > 0) {
            someCountries << it.key();
        }
        else {
            noCountries << it.key();
        }
    }

    QLabel *labelAllCars = new QLabel("Марки автомобилей, доставленные во все страны: " + allCountries.join(", "));
    QLabel *labelSomeCars = new QLabel("Марки автомобилей, доставленные в некоторые страны: " + someCountries.join(", "));
    QLabel *labelNoCars = new QLabel("Марки автомобилей, не доставленные ни в одну страну: " + noCountries.join(", "));

    layout->addWidget(labelAllCars);
    layout->addWidget(labelSomeCars);
    layout->addWidget(labelNoCars);

    widget->setLayout(layout);
    widget->show();

}

void filterFile(const QString &inputFileName, const QString &outputFileName) {
    QFile inputFile(inputFileName);
    if (!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для чтения";
        return;
    }

    QVector<int> numbers;
    QTextStream inStream(&inputFile);
    while (!inStream.atEnd()) {
        QString line = inStream.readLine();
        QStringList tokens = line.split(" ", Qt::SkipEmptyParts);
        for (const QString& token : tokens) {
            bool ok;
            int num = token.toInt(&ok);
            if (ok) {
                numbers.append(num);
            }
        }
    }
    inputFile.close();

    QFile outputFile(outputFileName);
    if (!outputFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть файл для записи";
        return;
    }

    QTextStream outStream(&outputFile);

    for (int num : numbers) {
        if (num % 2 == 0) {
            outStream << num << " (четное)\n";
        }

        if (num % 3 == 0 && num % 7 != 0) {
            outStream << num << " (делящееся на 3, но не на 7)\n";
        }

        int sqrtNum = sqrt(num);
        if (sqrtNum * sqrtNum == num) {
            outStream << num << " (точный квадрат)\n";
        }
    }

    outputFile.close();
}

void task6() {
    QWidget *w = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(w);

    QPushButton *selectInputFileButton = new QPushButton("Выбрать входной файл");
    QPushButton *selectOutputFileButton = new QPushButton("Выбрать выходной файл");
    QLabel *inputFilePathLabel = new QLabel("Выбранный входной файл:");
    QLabel *outputFilePathLabel = new QLabel("Выбранный выходной файл:");
    QPushButton *processButton = new QPushButton("Обработать файлы");

    layout->addWidget(selectInputFileButton);
    layout->addWidget(inputFilePathLabel);
    layout->addWidget(selectOutputFileButton);
    layout->addWidget(outputFilePathLabel);
    layout->addWidget(processButton);

    QObject::connect(selectInputFileButton, &QPushButton::clicked, w, [=]() {
        QString inputFileName = QFileDialog::getOpenFileName(nullptr, "Выберите входной файл", "", "Text Files (*.txt)");
        if (!inputFileName.isEmpty()) {
            inputFilePathLabel->setText("Выбранный входной файл: " + inputFileName);
        }
    });

    QObject::connect(selectOutputFileButton, &QPushButton::clicked, w, [=]() {
        QString outputFileName = QFileDialog::getSaveFileName(nullptr, "Выберите выходной файл", "", "Text Files (*.txt)");
        if (!outputFileName.isEmpty()) {
            outputFilePathLabel->setText("Выбранный выходной файл: " + outputFileName);
        }
    });

    QObject::connect(processButton, &QPushButton::clicked, w, [=]() {
        QString inputFileName = inputFilePathLabel->text().remove("Выбранный входной файл: ");
        QString outputFileName = outputFilePathLabel->text().remove("Выбранный выходной файл: ");

        if (!inputFileName.isEmpty() && !outputFileName.isEmpty()) {
            filterFile(inputFileName, outputFileName);
            QMessageBox::information(nullptr, "Готово", "Файлы обработаны и записаны.");
        } else {
            QMessageBox::warning(nullptr, "Ошибка", "Выберите входной и выходной файлы.");
        }
    });

    w->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *window = new QWidget;

    QVBoxLayout* mainLayout = new QVBoxLayout(window);
    QLineEdit *line = new QLineEdit;

    QPushButton *button = new QPushButton("&Подтвердить");

    mainLayout->addWidget(new QLabel("Введите номер задания"));
    mainLayout->addWidget(line);
    mainLayout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, window,  [=]{
        bool ok;
        int number = line->text().toInt(&ok);
        if (ok) {
            switch (number) {
            case 1:task1();break;
            case 2:task2();break;
            case 3:task3();break;
            case 4:task4();break;
            case 5:task5();break;
            case 6:task6();break;
            default:QMessageBox::warning(window, "Ошибка", "Введите цифру от 1 до 6)");break;
            }
        } else {
            QMessageBox::warning(window, "Ошибка", "Введите цифру от 1 до 6");
        }
    });
    window->show();

    return a.exec();
}
//Кодаси обязательно проснётся