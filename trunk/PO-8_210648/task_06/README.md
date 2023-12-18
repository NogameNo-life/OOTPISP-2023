# Лабораторная работа № 6 #

## Тема ##

Изучение UML. Диаграмма классов.

## Цель работы ##

Освоить построение диаграммы классов.

## Порядок выполнения ##

1. Изучить теоретический материал из [документации](https://mermaid.js.org/intro/getting-started.html).
2. Выбрать свой вариант.
3. Нарисовать каждый класс отдельно с методами и полями.
4. Оформить отчет.

## Вариант 4  ##

- Постройте UML диаграмму классов для системы управления персоналом.

## Диаграмма ##

```mermaid
classDiagram
class Worker {
- string Name
- string Surname
- int Age
- vector ~Work~ Works
+ AddWork()
  }
+ 
  class Director {
- string Name
- string Surname
- int Age
+ ManageWorker()
  }
  class Work {
- string Name
- int Difficult
+ GetData()
  }

  class WorkPlace {
- string Name
- vector Director Director
- vector ~Worker~ Workers
+ ManageWorker()
+ SetDirector()
+ AddGroup()
  }
  WorkPlace -- Director
  WorkPlace -- Worker
  Worker--Work
```

### Вывод ###

Освоил построение диаграммы классов.
