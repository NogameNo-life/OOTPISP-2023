# Лабораторная работа № 6 #

## UML - диаграммы ##

## Вариант 12 ##

```mermaid
---
title: UML
---
classDiagram
  class t1 {
    +lineEditX: QLineEdit
    +lineEditY: QLineEdit
    +lineEditZ: QLineEdit
    +sortButton: QPushButton
    +sortVariables(): void
  }

  class t2 {
    +processArray(const QVector<int>&): void
    +processMatrix(const QVector<QVector<int>>&): void
  }

  class t3 {
    -list1: QList<int>
    -list2: QList<int>
    +onDoItButtonClicked(): void
    +listToString(const QList<int>&, const QString&): QString
    +updateOutputText(const QString&): void
  }

  class t4 {
    +concatElements(const Container&): QString
    +onRunButtonClicked(): void
  }

  class t5 {
    -Shop
    -Product
    +onRunButtonClicked(): void
  }

  class t6 {
    +processFile(const QString&, const QString&): void
    +onRunButtonClicked(): void
  }

  class QApplication

  t1 --|> QWidget
  t2 --|> QWidget
  t3 --|> QWidget
  t4 --|> QWidget
  t5 --|> QWidget
  t6 --|> QWidget
  t3 -- QList<int>
  t3 -- QString
  t5 --|> t3
  t6 --|> t3
  t5 --|> t4
  t6 --|> t4
  t5 --|> t1
  t6 --|> t1
  t2 --|> t1
  QApplication --|> QObject
```
