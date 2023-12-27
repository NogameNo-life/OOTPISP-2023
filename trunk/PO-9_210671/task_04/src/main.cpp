#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QLabel>

class ResistorCalculator : public QWidget {
    Q_OBJECT

public:
    ResistorCalculator(QWidget *parent = nullptr) : QWidget(parent) {
        setupUi();
    }

private slots:
    void calculateResistance();
    void calculateJouleHeat();

private:
    void setupUi();
    void highlightValues();

    QTableWidget *table;
    QPushButton *resistanceButton;
    QPushButton *jouleHeatButton;
    QLabel *resultLabel;

    int highlightedCount;
};

void ResistorCalculator::setupUi() {
    // Create table
    table = new QTableWidget(15, 4, this);
    table->setHorizontalHeaderLabels({"R1", "R2", "Resistance", "Joule Heat"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Create buttons
    resistanceButton = new QPushButton("Calculate Resistance", this);
    jouleHeatButton = new QPushButton("Calculate Joule Heat", this);

    // Create result label
    resultLabel = new QLabel(this);

    // Connect signals and slots
    connect(resistanceButton, &QPushButton::clicked, this, &ResistorCalculator::calculateResistance);
    connect(jouleHeatButton, &QPushButton::clicked, this, &ResistorCalculator::calculateJouleHeat);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(table);
    layout->addWidget(resistanceButton);
    layout->addWidget(jouleHeatButton);
    layout->addWidget(resultLabel);

    setLayout(layout);
}

void ResistorCalculator::calculateResistance() {
    table->clearContents();
    highlightedCount = 0;

    for (int row = 0; row < 15; ++row) {
        int r1 = QRandomGenerator::global()->bounded(10, 101);
        int r2 = QRandomGenerator::global()->bounded(10, 101);

        QTableWidgetItem *itemR1 = new QTableWidgetItem(QString::number(r1));
        QTableWidgetItem *itemR2 = new QTableWidgetItem(QString::number(r2));

        table->setItem(row, 0, itemR1);
        table->setItem(row, 1, itemR2);

        double resistance = r1 + r2;
        QTableWidgetItem *itemResistance = new QTableWidgetItem(QString::number(resistance));
        table->setItem(row, 2, itemResistance);

        // Highlight the cell if the resistance is between 100 and 1000 ohms
        if (resistance >= 100 && resistance <= 1000) {
            itemResistance->setBackground(QBrush(QColor(Qt::yellow)));
            highlightedCount++;
        }
    }

    highlightValues();
}

void ResistorCalculator::calculateJouleHeat() {
    for (int row = 0; row < 15; ++row) {
        QTableWidgetItem *itemResistance = table->item(row, 2);
        if (!itemResistance) continue;

        double resistance = itemResistance->text().toDouble();

        double jouleHeat = resistance * resistance * 10; // Assuming time is 10 seconds

        QTableWidgetItem *itemJouleHeat = new QTableWidgetItem(QString::number(jouleHeat));
        table->setItem(row, 3, itemJouleHeat);

        // Highlight the cell if the joule heat is between 10 and 100 J
        if (jouleHeat >= 10 && jouleHeat <= 100) {
            itemJouleHeat->setBackground(QBrush(QColor(Qt::green)));
            highlightedCount++;
        }
    }

    highlightValues();
}

void ResistorCalculator::highlightValues() {
    // Display the count of highlighted cells
    resultLabel->setText(QString("Number of highlighted cells: %1").arg(highlightedCount));
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ResistorCalculator calculator;
    calculator.show();

    return app.exec();
}

#include "main.moc"
