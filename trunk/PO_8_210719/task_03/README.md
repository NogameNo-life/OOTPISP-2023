# Отчет по лабораторной работе №3

## Контейнеры в Qt5

## Реализация/ход работы

# Окно приложения:
```Python
class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setGeometry(650, 200, 300, 200)
        self.setWindowTitle('Задание')
        self.numberLabel = QLabel('Введите номер задания', self)
        self.numberLabel.move(30, 20)
        self.numberEntry = QLineEdit(self)
        self.numberEntry.move(30, 70)
        self.numberEntry.resize(240, 30)
        self.number_button = QPushButton('Подтвердить', self)
        self.number_button.move(80, 120)
        self.number_button.clicked.connect(self.validate_and_execute)
        self.first_exercise = None
        self.second_exercise = None
        self.third_exercise = None
        self.fourth_exercise = None
        self.fifth_exercise = None
        self.sixth_exercise = None
```
# Меню
```Python
    def validate_and_execute(self):
        user_input = self.numberEntry.text()
        if user_input == '1':
            if not self.first_exercise:
                self.first_exercise = FirstExercise()
            self.first_exercise.show()
        elif user_input == '2':
            if not self.second_exercise:
                self.second_exercise = SecondExercise()
            self.second_exercise.show()
        elif user_input == '3':
            if not self.third_exercise:
                self.third_exercise = ThirdExercise()
            self.third_exercise.show()
        elif user_input == '4':
            if not self.fourth_exercise:
                self.fourth_exercise = FourthExercise()
            self.fourth_exercise.show()
        elif user_input == '5':
            if not self.fifth_exercise:
                self.fifth_exercise = FifthExercise()
            self.fifth_exercise.show()
        elif user_input == '6':
            if not self.sixth_exercise:
                self.sixth_exercise = SixthExercise()
            self.sixth_exercise.show()

        else:
            print("Invalid input. Please enter '1' or '2'.")
```

#Классы заданий 1-6
```Python
class FirstExercise(QMainWindow):
  pass
class SecondExercise(QMainWindow):
  pass
class ThirdExercise(QMainWindow):
  pass
class FourthExercise(QMainWindow):
  pass
class FifthExercise(QMainWindow):
  pass
class SixthExercise(QMainWindow):
  pass
```











