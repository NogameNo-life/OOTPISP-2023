#include <QApplication>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QQueue>
#include <random>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Решение задачи");

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QQueue<int> myQueue;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-20, 50);

    // Заполнение очереди 8 случайными числами из интервала [-20; 50]
    for (int i = 0; i < 8; ++i) {
        int randomNum = dis(gen);
        myQueue.enqueue(randomNum);
        QLabel *queueElement = new QLabel("Элемент " + QString::number(i + 1) + ": " + QString::number(randomNum));
        layout->addWidget(queueElement);
    }

    QQueue<int> resultQueue; // Очередь для хранения средних арифметических

    // Нахождение среднего арифметического двух соседних элементов очереди и помещение результата в другую очередь
    for (int i = 0; i < myQueue.size() - 1; ++i) {
        int average = (myQueue.at(i) + myQueue.at(i + 1)) / 2;
        resultQueue.enqueue(average);
        QLabel *queueAverage = new QLabel("Среднее арифметическое " + QString::number(i + 1) + " и " + QString::number(i + 2) + ": " + QString::number(average));
        layout->addWidget(queueAverage);
    }

    window.setLayout(layout);
    window.show();
    return a.exec();
}
