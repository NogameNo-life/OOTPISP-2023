# Лабораторная работа №8

## Паттерны проектирования

## Вариант 16

## Цель лабораторной работы

Отработка умений и навыков применения паттернов проектирования.

## Задание №1

-   Применить паттерн абстрактная фабрика при построении интерфейса пользователя.
    Продукты фабрики: список, поле ввода, кнопка, язык отображения.

    Применить паттерн проектирования “Prototype” совместно с абстрактной фабрикой,
    то есть внести изменения в проект “Порождающие паттерны.
    Абстрактная фабрика”, чтобы абстрактная фабрика параметризировалась прототипами.

    Применить паттерн проектирования “Singleton” совместно с абстрактной фабрикой.

-   Применить паттерн “Строитель” для построения Отчета по частям.

    Части: Head, Body, Ending.

    ConcreteBuilder выбрать самостоятельно

    Применить паттерн “Фабричный метод” при создании конкретного строителя
    и передачи его клиенту.

## Ход работы

### Продукты фабрики

```python
class UIList(ABC):
    @abstractmethod
    def display(self):
        pass

class UIInputField(ABC):
    @abstractmethod
    def interact(self):
        pass

class UIButton(ABC):
    @abstractmethod
    def click(self):
        pass

class Language(ABC):
    @abstractmethod
    def set_language(self):
        pass
```

### Абстрактная фабрика

```python
class UIFactory(ABC):
    @abstractmethod
    def create_list(self):
        pass

    @abstractmethod
    def create_input_field(self):
        pass

    @abstractmethod
    def create_button(self):
        pass

    @abstractmethod
    def create_language(self):
        pass
```

### Конкретные продукты

```python
class WindowsUIList(UIList):
    def display(self):
        print("Windows style list")

class WindowsUIInputField(UIInputField):
    def interact(self):
        print("Windows style input field")

class WindowsUIButton(UIButton):
    def click(self):
        print("Windows style button")

class EnglishLanguage(Language):
    def set_language(self):
        print("English language")
```

### Конкретная фабрика

```python
class WindowsUIFactory(UIFactory):
    def create_list(self):
        return WindowsUIList()

    def create_input_field(self):
        return WindowsUIInputField()

    def create_button(self):
        return WindowsUIButton()

    def create_language(self):
        return EnglishLanguage()
```

## Вывод

Я реализовал паттерны проектирования.
