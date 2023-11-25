# Отчет по лабораторной работе №7 #

## Паттерны проектирования ##

## Вариант №3 ##

Применить паттерн абстрактная фабрика при построении логической структуры лабиринта. Продукты фабрики: комната, дверь.

Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой. То есть теперь в проекте абстрактная фабрика должна параметризоваться прототипами.

Применить паттерн проектирования  “Singleton” совместно с абстрактной фабрикой.

Применить паттерн “Строитель” для построения:

- Представления лица героя в ролевой игровой программе

- Части: Eyes  - параметры (Color, Figure), Nose (Color , Figure), Mouth (Color, Figure), Ears (Color, Figure), Hair (Color, Figure)

- ConcreteBuilder: UglyFaceBuilder, GoodFaceBuilder, SmileFaceBuilder

Применить паттерн  “Фабричный метод” при создании конкретного строителя и передачи его клиенту.  Самостоятельно продумать контекст в каркасе для вызова шаблонного метода.

## Код программы ##

[mazeFactory.h](./src/mazefactory.h)

[mazeFactory.cpp](./src/mazefactory.cpp)

[builder.h](./src/builder.h)

## Результат работы программы ##

![img_1](./images/img_1.png)

![img_2](./images/img_2.png)