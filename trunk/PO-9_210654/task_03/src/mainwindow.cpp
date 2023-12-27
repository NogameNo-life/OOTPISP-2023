#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Задание 1
    ui->maxText->setText("");
    ui->differenceText->setText("");
    ui->resultText->setText("");
    connect(ui->numbersEdit, &QLineEdit::editingFinished, this, &MainWindow::numbersEditEditingFinished);
    //Задание 2
    connect(ui->generateSelectionArray, &QPushButton::clicked, this, &MainWindow::showArrayAndEvenThenOddElements);
    connect(ui->generateSelectionArray, &QPushButton::clicked, this, &MainWindow::showTwoDimmensionalArrayAndChangeMinAndMaxInLines);
    //задание 3
    connect(ui->generateSelectionList, &QPushButton::clicked, this, &MainWindow::listOneButMinInsteadPositive);
    connect(ui->generateSelectionList, &QPushButton::clicked, this, &MainWindow::listButSmallerThanKDeleted);
    //Задание 4
    connect(ui->generateSelectionStackAndQueue, &QPushButton::clicked, this, &MainWindow::stackButMinAndMaxSwapped);
    connect(ui->generateSelectionStackAndQueue, &QPushButton::clicked, this, &MainWindow::queueButEvenReplacedAverage);
    //Задание 5
    connect(ui->generateSelectionOfFishes, &QPushButton::clicked, this, &MainWindow::letTheFishingBegin);
    //Задание 6
    connect(ui->generateSelectionFile, &QPushButton::clicked, this, &MainWindow::showArrayFromFileAndEvenThenOddElementsFromOtherFiles);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Задание 1
void MainWindow::numbersEditEditingFinished()//Весь ввод в это поле - забавы ради
{
    QString text = ui->numbersEdit->text();
    QString filteredText;
    QStringList numbersList;
    if (text.size() <= 0) {
        fillWithZeroes(numbersList);
        filteredText = numbersList.join(", ");
        ui->numbersEdit->setText(filteredText);
        ui->maxText->setText("Самое большое число: 0");
        ui->differenceText->setText("Разность между двумя оставшимися: 0");
        ui->resultText->setText("Результат: " + filteredText);
        return;
    }
    for(int i = 0; i < text.size(); ++i) {//Оставляем только ' ' '.' и цифры
        QChar ch = text[i];
        if (ch.isDigit() || ch == '.' || ch == ' ' || ch == '-') { filteredText.append(text[i]); }
    }
    if(filteredText.size() <= 0) {//Если получилась пустая строка, то дальнейшая работа не нужна
        fillWithZeroes(numbersList);
        filteredText = numbersList.join(", ");
        ui->numbersEdit->setText(filteredText);
        ui->maxText->setText("Самое большое число: 0");
        ui->differenceText->setText("Разность между двумя оставшимися: 0");
        ui->resultText->setText("Результат: " + filteredText);
        return;
    }
    for(int i = 0; i < filteredText.size(); ++i) {//отделяем минусы от впереди стоящих символов пробелом
        if(filteredText[i] == '-' && i - 1 >= 0) {
            filteredText.insert(i, ' ');
            ++i;
        }
    }
    for(int i = 0; i < filteredText.size(); ++i) {//Если пробелов больше, чем 1 подряд, убираем их
        if(i + 1 <= filteredText.size() - 1 && filteredText[i] == ' ' && filteredText[i + 1] == ' ') {
            filteredText.remove(i + 1, 1);
            --i;
        }
    }
    int dotCounter = 0;
    for(int i = 0; i < filteredText.size(); ++i) {//разделяем слова с двумя точками
        if(filteredText[i] == '.') {
            ++dotCounter;
            if(dotCounter > 1) {
                filteredText.insert(i, ' ');
            }
        }
        if(filteredText[i] == ' ') { dotCounter = 0; }
    }
    for(int i = 0; i < filteredText.size(); ++i) {//Если у нуля нет целой или дробной части, то дописать в этой части 0
        if(filteredText[i] == '.') {
            if(i + 1 > filteredText.size() - 1) { filteredText.append("0"); }
            else if(!filteredText[i + 1].isDigit()) { filteredText.insert(i + 1, "0"); }
            if(i - 1 < 0 || !filteredText[i - 1].isDigit()) { filteredText.insert(i, "0"); }
        }
    }
    for(int i = 0; i < filteredText.size(); ++i) {//Если после минута стоит пробел, то поставит 0 после минуса
        if(filteredText[i] == '-') {
            if(i + 1 > filteredText.size() - 1) { filteredText.append("0"); }
            else if(!filteredText[i + 1].isDigit()) { filteredText.insert(i + 1, "0"); }
        }
    }

    QVector<double> numbers;
    numbersList = filteredText.split(' ');
    fillWithZeroes(numbersList);
    for(int i = 0; i < 3; ++i) {
        numbers.push_back(numbersList[i].toDouble());
    }
    numbersList.clear();
    for(int i = 0; i < 3; ++i) {//Убрать нули, если их больше одного спереди в целой части
        numbersList.push_back(QString::number(numbers[i]));
    }
    filteredText = numbersList.join(", ");
    ui->numbersEdit->setText(filteredText);
    sort(numbers.begin(), numbers.end());
    ui->maxText->setText("Максимальное: " + QString::number(numbers[2]));
    ui->differenceText->setText("Разность между двумя оставшимися: " + QString::number(numbers[0] - numbers[1]));
    numbers[2] = numbers[0] - numbers[1];
    numbersList.clear();
    for(int i = 0; i < 3; ++i) {
        numbersList.push_back(QString::number(numbers[i]));
    }
    filteredText = numbersList.join(", ");
    ui->resultText->setText("Результат: " + filteredText);
}

void MainWindow::fillWithZeroes(QStringList &list)
{
    if(list.size() > 3) { list.resize(3); }
    else {
        while (list.size() < 3) { list.push_back("0"); }
    }
}

//Задание 2
void MainWindow::showArrayAndEvenThenOddElements()
{
    QVector<int> array(rand() % 10 + 11);
    QVector<int> even;
    QVector<int> odd;
    ui->oneDimmensionalArrayPreview->setRowCount(1);
    ui->oneDimmensionalArrayPreview->setColumnCount(array.size());
    ui->oneDimmensionalArrayPreview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->evenAndOddNumbersPreview->setRowCount(1);
    ui->evenAndOddNumbersPreview->setColumnCount(array.size());
    ui->evenAndOddNumbersPreview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < array.size(); ++i) {//Запись изначального массива
        array[i] = rand() % 100 + 1;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(array[i]));
        ui->oneDimmensionalArrayPreview->setItem(0, i, item);
        ui->oneDimmensionalArrayPreview->resizeColumnToContents(i);
    }
    for(int i = 0; i < array.size(); ++i) {//Деление массива на чётные и нечётные числа
        if (array[i] % 2 == 0) {
            even.push_back(array[i]);
            ui->oneDimmensionalArrayPreview->item(0, i)->setBackground(QColor(0, 255, 0));
        }
        else {
            odd.push_back(array[i]);
            ui->oneDimmensionalArrayPreview->item(0, i)->setBackground(QColor(255, 0, 0));
        }
    }
    int count = 0;
    for(int i = 0; i < even.size(); ++i) {//Запись чётных чисел
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(even[i]));
        ui->evenAndOddNumbersPreview->setItem(0, count, item);
        ui->evenAndOddNumbersPreview->resizeColumnToContents(count);
        ++count;
    }
    for(int i = 0; i < odd.size(); ++i) {//Запись нечётных чисел
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(odd[i]));
        ui->evenAndOddNumbersPreview->setItem(0, count, item);
        ui->evenAndOddNumbersPreview->resizeColumnToContents(count);
        ++count;
    }
}

void MainWindow::showTwoDimmensionalArrayAndChangeMinAndMaxInLines()
{
    QVector<QVector<int>> array(rand()%3 + 1, QVector<int>(rand() % 11 + 11));
    ui->twoDimmensionalArrayPreview->setRowCount(array.size());
    ui->twoDimmensionalArrayPreview->setColumnCount(array[0].size());
    ui->twoDimmensionalArrayPreview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->mainAndMaxNumbersPreview->setRowCount(array.size());
    ui->mainAndMaxNumbersPreview->setColumnCount(array[0].size());
    ui->mainAndMaxNumbersPreview->setEditTriggers(QAbstractItemView::NoEditTriggers);
    for(int i = 0; i < array.size(); ++i) {
        for(int j = 0; j < array[i].size(); ++j) {
            array[i][j] = rand() % 100 + 1;
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(array[i][j]));
            ui->twoDimmensionalArrayPreview->setItem(i, j, item);
            ui->twoDimmensionalArrayPreview->resizeColumnToContents(j);
        }
    }
    for(int i = 0; i < array.size(); ++i) {
        int minIndex = 0, maxIndex = 0;
        int min = array[i][minIndex], max = array[i][maxIndex];
        for(int j = 0; j < array[i].size(); ++j) {
            if(min > array[i][j]) {
                min = array[i][j];
                minIndex = j;
            }
            if(max < array[i][j]) {
                max = array[i][j];
                maxIndex = j;
            }
        }
        swap(array[i][minIndex], array[i][maxIndex]);
        ui->twoDimmensionalArrayPreview->item(i, minIndex)->setBackground(QColor(255, 0, 0));
        ui->twoDimmensionalArrayPreview->item(i, maxIndex)->setBackground(QColor(0, 255, 0));

    }
    for(int i = 0; i < array.size(); ++i) {
        for(int j = 0; j < array[i].size(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(array[i][j]));
            ui->mainAndMaxNumbersPreview->setItem(i, j, item);
            ui->mainAndMaxNumbersPreview->resizeColumnToContents(j);
        }
    }
}

//Задание 3
void MainWindow::listOneButMinInsteadPositive()
{

    QList<int> listOne(rand() % 6 + 5);
    QList<int> listTwo(rand() % 6 + 5);
    ui->listOne->setRowCount(1);
    ui->listOne->setColumnCount(listOne.size());
    ui->listOne->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listTwo->setRowCount(1);
    ui->listTwo->setColumnCount(listTwo.size());
    ui->listTwo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->listOneButMinInsteadPositive->setRowCount(1);
    ui->listOneButMinInsteadPositive->setColumnCount(listOne.size());
    ui->listOneButMinInsteadPositive->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int count = 0;
    for(auto it = listOne.begin(); it < listOne.end(); ++it) {
        *it = rand() % 50 + 1 -25;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(*it));
        ui->listOne->setItem(0, count, item);
        ui->listOne->resizeColumnToContents(count);
        if(*it >= 0) ui->listOne->item(0, count)->setBackground(QColor(255, 0, 0));
        ++count;
    }
    count = 0;
    int min = 101, minIndex = 0;
    for(auto it = listTwo.begin(); it < listTwo.end(); ++it) {
        *it = rand() % 100 + 1;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(*it));
        ui->listTwo->setItem(0, count, item);
        ui->listTwo->resizeColumnToContents(count);
        if(min > *it) {
            min = *it;
            minIndex = count;
        }
        ++count;
    }
    ui->listTwo->item(0, minIndex)->setBackground(QColor(255, 0, 0));
    count = 0;
    for(auto it = listOne.begin(); it < listOne.end(); ++it) {
        if(*it >= 0) { *it = min; }
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(*it));
        ui->listOneButMinInsteadPositive->setItem(0, count, item);
        ui->listOneButMinInsteadPositive->resizeColumnToContents(count);
        ++count;
    }
}

void MainWindow::listButSmallerThanKDeleted()
{
    QList<int> list(rand() % 10 + 11);
    ui->list->setRowCount(1);
    ui->list->setColumnCount(list.size());
    ui->list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int count = 0, k = rand() % 100 + 1;
    ui->listName->setText("Список в котором удалены элементы больше k = " + QString::number(k));
    for(auto it = list.begin(); it < list.end(); ++it) {
        *it = rand() % 100 + 1;
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(*it));
        ui->list->setItem(0, count, item);
        ui->list->resizeColumnToContents(count);
        if (*it > k) ui->list->item(0, count)->setBackground(QColor(255, 0, 0));
        ++count;
    }
    for(auto it = list.begin(); it < list.end();) {
        if (*it > k) { it = list.erase(it); }
        else { ++it; }
    }
    ui->listButSmallerThanKDeleted->setRowCount(1);
    ui->listButSmallerThanKDeleted->setColumnCount(list.size());
    ui->listButSmallerThanKDeleted->setEditTriggers(QAbstractItemView::NoEditTriggers);
    count = 0;
    for(auto it = list.begin(); it < list.end(); ++it) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(*it));
        ui->listButSmallerThanKDeleted->setItem(0, count, item);
        ui->listButSmallerThanKDeleted->resizeColumnToContents(count);
        ++count;
    }
}

//Задание 4
void MainWindow::stackButMinAndMaxSwapped()
{
    QStack<int> stackBase;
    QStack<int> stackBuffer;
    int numberOfNumbers = 5;
    ui->stack->setRowCount(1);
    ui->stack->setColumnCount(numberOfNumbers);
    ui->stack->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->stackButMinAndMaxSwapped->setRowCount(1);
    ui->stackButMinAndMaxSwapped->setColumnCount(numberOfNumbers);
    ui->stackButMinAndMaxSwapped->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int min = 101, max = 0;
    for(int i = 0; i < numberOfNumbers; ++i) {
        stackBase.push(rand() % 100 + 1);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(stackBase.top()));
        ui->stack->setItem(0, i, item);
        ui->stack->resizeColumnToContents(i);
        if(min > stackBase.top()) { min = stackBase.top(); }
        if(max < stackBase.top()) { max = stackBase.top(); }
    }
    int count = 4;
    for(int i = 0; i < numberOfNumbers; ++i) {
        if (stackBase.top() == min) {
            stackBuffer.push(max);
            stackBase.pop();
            ui->stack->item(0, count)->setBackground(QColor(255, 0, 0));
        }
        else if (stackBase.top() == max) {
            stackBuffer.push(min);
            stackBase.pop();
            ui->stack->item(0, count)->setBackground(QColor(0, 255, 0));
        }
        else {
            stackBuffer.push(stackBase.top());
            stackBase.pop();
        }
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(stackBuffer.top()));
        ui->stackButMinAndMaxSwapped->setItem(0, count, item);
        ui->stackButMinAndMaxSwapped->resizeColumnToContents(count);
        --count;
    }
}

void MainWindow::queueButEvenReplacedAverage()
{
    QQueue<int> queueBase;
    QQueue<int> queueBuffer;
    int numberOfNumbers = 8, numberOfEvenNumbers = 0;
    ui->queue->setRowCount(1);
    ui->queue->setColumnCount(numberOfNumbers);
    ui->queue->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->queueButEvenReplacedAverage->setRowCount(1);
    ui->queueButEvenReplacedAverage->setColumnCount(numberOfNumbers);
    ui->queueButEvenReplacedAverage->setEditTriggers(QAbstractItemView::NoEditTriggers);
    double average = 0;
    for(int i = 0; i < numberOfNumbers; ++i) {
        queueBase.push_front(rand() % 51);
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(queueBase.front()));
        ui->queue->setItem(0, i, item);
        ui->queue->resizeColumnToContents(i);
        if( queueBase.front() % 2 == 0 ) {
            average += queueBase.front();
            numberOfEvenNumbers += 1;
            ui->queue->item(0, i)->setBackground(QColor(0, 255, 0));
        }
    }
    average = average / numberOfEvenNumbers;
    ui->queueText->setText("Очередь, но все чётные числа заменены их средним арифметическим k = " + QString::number(average));
    average = round(average);
    for(int i = 0; i < numberOfNumbers; ++i) {
        if (queueBase.back() % 2 == 0) {
            queueBuffer.push_front(average);
            queueBase.pop_back();
        }
        else {
            queueBuffer.push_front(queueBase.back());
            queueBase.pop_back();
        }
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(queueBuffer.front()));
        ui->queueButEvenReplacedAverage->setItem(0, i, item);
        ui->queueButEvenReplacedAverage->resizeColumnToContents(i);
    }
}

//Задание 5
void MainWindow::letTheFishingBegin()
{
    const QStringList fishTypeList = {"Чёрный", "Белый", "Серебряный", "Золотой", "Большой", "Маленький"},
        fishNameList = {"Карась", "Окунь", "Щука", "Сазан", "Карп", "Остропёрка"};
    QStringList lake;
    QStringList proFisher, intermediateFisher, noobyFisher;
    QStringList fishersFishPool, notFishersFishPool;
    int numberOfFishesTypeInLake = rand() % 16 + 10, proFishersCatchesPerHour = rand() % 6 + 5,
        intermediateFishersCatchesPerHour = rand() % 4 + 3, noobyFishersCatchesPerHour  = rand() % 3 + 2;
    ui->lake->setReadOnly(true);
    ui->proFisher->setReadOnly(true);
    ui->intermediateFisher->setReadOnly(true);
    ui->noobyFisher->setReadOnly(true);
    ui->fishersFishPool->setReadOnly(true);
    ui->notFishersFishPool->setReadOnly(true);
    for (int i = 0; i < numberOfFishesTypeInLake; ++i) {
        QString fishType = fishTypeList[rand() % fishTypeList.size()];
        QString fishName = fishNameList[rand() % fishNameList.size()];
        QString fish = fishType + ' ' + fishName;
        if (lake.contains(fish)) { --i; }
        else { lake.push_front(fish); }
    }
    ui->lake->setText(lake.join(", "));
    for (int i = 0; i < proFishersCatchesPerHour; ++i) {
        proFisher.push_front(lake[rand() % lake.size()]);
    }
    ui->proFisher->setText(proFisher.join(", "));
    for (int i = 0; i < intermediateFishersCatchesPerHour; ++i) {
        intermediateFisher.push_front(lake[rand() % lake.size()]);
    }
    ui->intermediateFisher->setText(intermediateFisher.join(", "));
    for (int i = 0; i < noobyFishersCatchesPerHour; ++i) {
        noobyFisher.push_front(lake[rand() % lake.size()]);
    }
    ui->noobyFisher->setText(noobyFisher.join(", "));
    for (auto &item : noobyFisher) {
        if (proFisher.contains(item) && intermediateFisher.contains(item)) {
            fishersFishPool.push_front(item);
        }
    }
    ui->fishersFishPool->setText(fishersFishPool.join(", "));
    notFishersFishPool = lake;
    for (int i = 0; i < fishersFishPool.size(); ++i) {
        if (notFishersFishPool.contains(fishersFishPool[i])) notFishersFishPool.removeOne(fishersFishPool[i]);
    }
    ui->notFishersFishPool->setText(notFishersFishPool.join(", "));
    ui->lakeText->setText("Виды рыб в озере: количество видов = "
                          + QString::number(numberOfFishesTypeInLake));
    ui->proFisherText->setText("Рыбак-профессионал, спустя час, "
                               "поймал следующий набор рыб: количество рыб = "
                               + QString::number(proFishersCatchesPerHour));
    ui->intermediateFisherText->setText("Рыбак-любитель, спустя час,"
                                        " поймал следующий набор рыб: количество рыб = "
                                        + QString::number(intermediateFishersCatchesPerHour));
    ui->noobyFisherText->setText("Рыбак-новичок, спустя час,"
                                 " поймал следующий набор рыб: количество рыб = "
                                 + QString::number(noobyFishersCatchesPerHour));
    ui->fishersFishPoolText->setText("У каждого рыбака, спустя час,"
                                     " есть следующие виды рыб: количество общих видов = "
                                     + QString::number(fishersFishPool.size()));
    ui->notFishersFishPoolText->setText("Виды рыб, которые остались в озере,"
                                        " не пойманные рыбаками: количество видов = "
                                        + QString::number(notFishersFishPool.size()));
}

//Задание 6
void MainWindow::showArrayFromFileAndEvenThenOddElementsFromOtherFiles()
{
    QVector<int> array(rand() % 10 + 11);
    QVector<int> even;
    QVector<int> odd;
    QString fileContent;
    QStringList numbersOfFile;
    QFile fileF("f.txt"), fileG("g.txt"), fileH("h.txt");
    QTextStream stream;
    ui->fileF->setRowCount(1);
    ui->fileF->setColumnCount(array.size());
    ui->fileF->setEditTriggers(QAbstractItemView::NoEditTriggers);
    fileF.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i = 0; i < array.size(); ++i) {//Создание файла F со всеми числами
        stream.setDevice(&fileF);
        array[i] = rand() % 100 + 1;
        if(i == array.size() - 1) { stream << array[i]; }
        else stream << array[i] << ' ';
    }
    fileF.close();
    array.clear();//Очистка массива для имитации чтения из файла F в массив
    fileF.open(QIODevice::ReadOnly | QIODevice::Text);
    stream.setDevice(&fileF);
    fileContent = stream.readAll();
    fileF.close();
    numbersOfFile = fileContent.split(' ');
    for(int i = 0; i < numbersOfFile.size(); ++i) {
        array.push_back(numbersOfFile[i].toInt());
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(array[i]));
        ui->fileF->setItem(0, i, item);
        ui->fileF->resizeColumnToContents(i);
    }
    for(int i = 0; i < array.size(); ++i) {//Деление массива на чётные и нечётные числа
        if (array[i] % 2 == 0) {
            even.push_back(array[i]);
            ui->fileF->item(0, i)->setBackground(QColor(0, 255, 0));
        }
        else {
            odd.push_back(array[i]);
            ui->fileF->item(0, i)->setBackground(QColor(255, 0, 0));
        }
    }
    ui->fileG->setRowCount(1);
    ui->fileG->setColumnCount(even.size());
    ui->fileG->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->fileH->setRowCount(1);
    ui->fileH->setColumnCount(odd.size());
    ui->fileH->setEditTriggers(QAbstractItemView::NoEditTriggers);
    fileG.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i = 0; i < even.size(); ++i) {//Создание файла G с чётными числами файла F
        stream.setDevice(&fileG);
        if(i == even.size() - 1) { stream << even[i]; }
        else stream << even[i] << ' ';
    }
    fileG.close();
    fileH.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i = 0; i < odd.size(); ++i) {//Создание файла H с нечётными числами файла F
        stream.setDevice(&fileH);
        if(i == odd.size() - 1) { stream << odd[i]; }
        else stream << odd[i] << ' ';
    }
    fileH.close();
    even.clear();//Очистка массива с чётными числами для имитации чтения из файла G в массив
    fileG.open(QIODevice::ReadOnly | QIODevice::Text);
    stream.setDevice(&fileG);
    fileContent = stream.readAll();
    fileG.close();
    numbersOfFile = fileContent.split(' ');
    for(int i = 0; i < numbersOfFile.size(); ++i) {
        even.push_back(numbersOfFile[i].toInt());
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(even[i]));
        ui->fileG->setItem(0, i, item);
        ui->fileG->resizeColumnToContents(i);
    }
    odd.clear();//Очистка массива с нечётными числами для имитации чтения из файла F в массив
    fileH.open(QIODevice::ReadOnly | QIODevice::Text);
    stream.setDevice(&fileH);
    fileContent = stream.readAll();
    fileH.close();
    numbersOfFile = fileContent.split(' ');
    for(int i = 0; i < numbersOfFile.size(); ++i) {
        odd.push_back(numbersOfFile[i].toInt());
        QTableWidgetItem *item = new QTableWidgetItem(QString::number(odd[i]));
        ui->fileH->setItem(0, i, item);
        ui->fileH->resizeColumnToContents(i);
    }
}
