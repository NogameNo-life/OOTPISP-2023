#include "task5.h"
#include "ui_task5.h"

task5::task5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::task5)
{
    ui->setupUi(this);
    setWindowTitle("Task5");
    QVector <QString> *items = new QVector <QString>[4];
    QObject::connect(ui->Add, &QPushButton::clicked, [=]{
        int i = ui->Option->currentIndex();
        QString item = ui->inputItem->text();
        if (!items[i].contains(item)){
            items[i].push_back(item);
        }
        QVector <QString> allItems, oneItem, noItem;
        int ItemsSize = items[3].size();
        for (auto currItem: items[3]){
            int count = 0;
            for (int j = 0; j < 3; j++){
                if (items[j].contains(currItem))
                    count++;

            }
            switch (count) {
            case 0:
                noItem.push_back(currItem);
                break;
            case 1:
            case 2:
                oneItem.push_back(currItem);
                break;
            case 3:
                allItems.push_back(currItem);
            default:
                break;
            }
        }
        ui->all->setPlainText(allItems.join('\n'));
        ui->one->setPlainText(oneItem.join('\n'));
        ui->no->setPlainText(noItem.join('\n'));
        ui->output->setPlainText(items[i].join('\n'));
    });

    QObject::connect(ui->Option, &QComboBox::currentIndexChanged, [=](int i){
        ui->output->setPlainText(items[i].join('\n'));
    });
}

task5::~task5()
{
    delete ui;
}
