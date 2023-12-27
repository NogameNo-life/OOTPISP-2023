import sys
from PyQt5.QtWidgets import (
    QTableWidgetItem, QApplication, QWidget, QVBoxLayout, QLineEdit, QPushButton, QLabel,
    QComboBox, QTableWidget, QHBoxLayout, QRadioButton, QButtonGroup, QFileDialog,
    QPlainTextEdit, QSplitter, QMessageBox
)
from PyQt5.QtCore import Qt, QDir
import random

class Task1(QWidget):
    def __init__(self):
        super(Task1, self).__init__()

        layout = QVBoxLayout(self)

        self.line_edit = QLineEdit()
        self.button = QPushButton("&Подтвердить")
        self.button.clicked.connect(self.perform_task)

        layout.addWidget(QLabel("Введите три числа"), alignment=Qt.AlignCenter)
        layout.addWidget(self.line_edit)
        layout.addWidget(self.button)

    def perform_task(self):
        values = list(map(int, self.line_edit.text().split()))
        min_index = values.index(min(values))
        max_index = values.index(max(values))
        values[3 - min_index - max_index] = values[max_index] - values[min_index]
        self.line_edit.setText(" ".join(map(str, values)))

class Task2(QWidget):
    def __init__(self):
        super(Task2, self).__init__()

        layout = QVBoxLayout(self)

        self.height_edit = QLineEdit()
        self.width_edit = QLineEdit()
        self.height_edit.setPlaceholderText("Введите высоту")
        self.width_edit.setPlaceholderText("Введите ширину")

        self.table = QTableWidget(10, 10)
        self.table.setColumnCount(10)
        self.table.setHorizontalHeaderLabels(map(str, range(1, 11)))

        self.button = QPushButton("&Перегенерировать")
        self.button.clicked.connect(self.generate_table)

        self.comboBox = QComboBox()
        self.comboBox.addItems(["Четные", "Нечетные"])
        self.info_label = QLabel()

        layout.addWidget(self.height_edit)
        layout.addWidget(self.width_edit)
        layout.addWidget(self.button)
        layout.addWidget(self.table)
        layout.addWidget(self.comboBox)
        layout.addWidget(self.info_label)

    def generate_table(self):
        height = int(self.height_edit.text())
        width = int(self.width_edit.text())
        self.table.setRowCount(height)
        self.table.setColumnCount(width)

        for i in range(height):
            for j in range(width):
                random_number = random.randint(0, 99)
                item = QTableWidgetItem(str(random_number))
                self.table.setItem(i, j, item)

    def calculate_sum(self, index):
        sum_value = 0
        for i in range(self.height):
            for j in range(index, self.width, 2):
                item = self.table.item(i, j)
                value = int(item.text())
                sum_value += value
        return sum_value

class Task3(QWidget):
    def __init__(self):
        super(Task3, self).__init__()

        layout = QVBoxLayout(self)

        self.list1_label = QLabel("1 список: ")
        self.list1 = QLabel()
        self.list2_label = QLabel("2 список: ")
        self.list2 = QLabel()

        self.head_button = QRadioButton("В начало")
        self.tail_button = QRadioButton("В конец")
        self.radio_group = QButtonGroup(self)
        self.radio_group.addButton(self.head_button)
        self.radio_group.addButton(self.tail_button)

        self.add_button = QPushButton("Добавить")
        self.value_line = QLineEdit()

        self.clone_button = QPushButton("Дублировать")
        self.comboBox = QComboBox()
        self.comboBox.addItems(["Первый", "Второй"])

        layout.addWidget(self.list1_label)
        layout.addWidget(self.list1)
        layout.addWidget(self.list2_label)
        layout.addWidget(self.list2)
        layout.addWidget(self.head_button)
        layout.addWidget(self.tail_button)
        layout.addWidget(self.add_button)
        layout.addWidget(self.value_line)
        layout.addWidget(self.clone_button)
        layout.addWidget(self.comboBox)

    def add_value(self):
        toogle_list = self.comboBox.currentIndex()
        value = self.value_line.text()
        if self.radio_group.checkedButton() == self.head_button:
            self.list_values[toogle_list].insert(0, value)
        else:
            self.list_values[toogle_list].append(value)

        if toogle_list == 0:
            self.list1.setText(" ".join(self.list_values[0]))
        else:
            self.list2.setText(" ".join(self.list_values[1]))

    def clone_list(self):
        toogle_list = self.comboBox.currentIndex()
        self.list_values[(toogle_list + 1) % 2] = self.list_values[toogle_list].copy()

        if toogle_list == 0:
            self.list2.setText(" ".join(self.list_values[0]))
        else:
            self.list1.setText(" ".join(self.list_values[1]))

class Task4(QWidget):
    st = []  

    def __init__(self):
        super(Task4, self).__init__()

        layout = QVBoxLayout(self)

        self.stack_values = QLabel[2]()
        self.query_values = QLabel[2]()

        self.generate_stack = QPushButton("Перегенерировать стек")
        self.generate_query = QPushButton("Перегенерировать очередь")

        fields = QHBoxLayout()

        labels = QVBoxLayout()
        values = QVBoxLayout()
        buttons = QVBoxLayout()

        buttons.addWidget(self.generate_stack)
        buttons.addWidget(self.generate_query)

        values.addWidget(self.stack_values[0])
        values.addWidget(self.stack_values[1])
        values.addWidget(self.query_values[0])
        values.addWidget(self.query_values[1])

        labels.addWidget(QLabel("Исходный стек"))
        labels.addWidget(QLabel("Модифицированный стек"))
        labels.addWidget(QLabel("Исходная очередь"))
        labels.addWidget(QLabel("Модифицированная очередь"))

        fields.addLayout(labels)
        fields.addLayout(values)
        fields.addLayout(buttons)

        layout.addWidget(QLabel("Стек и очередь"), alignment=Qt.AlignCenter)
        layout.addLayout(fields)

    def generate_stack(self):
        self.st.clear()
        self.st2.clear()
        for _ in range(10):
            random_number = random.randint(0, 99)
            self.st.push(str(random_number))

        self.stack_values[0].setText(" ".join(self.st))

        for elem in self.st:
            if elem.toInt() > 0:
                self.st2.push("1")
            elif elem.toInt() < 0:
                self.st2.push("-1")
            else:
                self.st2.push("0")
        self.stack_values[1].setText(" ".join(self.st2))

    def generate_queue(self):
        self.q.clear()
        self.q2.clear()
        MAX = 0
        for i in range(10):
            random_number = random.randint(0, 99)
            self.q.enqueue(str(random_number))
            MAX = max(MAX, random_number)
        for elem in self.q:
            self.q2.enqueue(str(elem.toInt() + MAX))

        self.query_values[0].setText(" ".join(self.q))
        self.query_values[1].setText(" ".join(self.q2))

class Task5(QWidget):
    def __init__(self):
        super(Task5, self).__init__()

        layout = QVBoxLayout(self)

        self.text = QPlainTextEdit()
        inner_layout = QHBoxLayout()
        adding_layout = QVBoxLayout()
        self.CB = QComboBox()
        self.CB.addItems(["Магазин1", "Магазин2", "Магазин3", "Товары"])
        self.product_line = QLineEdit()
        self.submit = QPushButton("Добавить")
        self.all_products = QPlainTextEdit("")
        self.at_least_products = QPlainTextEdit()
        self.no_one_products = QPlainTextEdit()

        self.all_products.setReadOnly(True)
        self.at_least_products.setReadOnly(True)
        self.no_one_products.setReadOnly(True)
        self.text.setReadOnly(True)
        splitter = QSplitter(Qt.Vertical)

        splitter.addWidget(QLabel("Продукты, находящиеся во всех магазинах"))
        splitter.addWidget(self.all_products)
        splitter.addWidget(QLabel("Продукты, находящиеся хотя бы в одном магазине"))
        splitter.addWidget(self.at_least_products)
        splitter.addWidget(QLabel("Продукты, не находящиеся ни в одном магазине"))
        splitter.addWidget(self.no_one_products)

        adding_layout.addWidget(self.CB)
        adding_layout.addWidget(self.product_line)
        adding_layout.addWidget(self.submit)
        adding_layout.addWidget(QLabel("Продукты"))
        adding_layout.addWidget(self.text)

        inner_layout.addLayout(adding_layout)
        inner_layout.addWidget(splitter)

        layout.addWidget(QLabel("Задание 5"), alignment=Qt.AlignCenter)
        layout.addLayout(inner_layout)

    def add_product(self):
        index = self.CB.currentIndex()
        product = self.product_line.text()
        if product not in self.products[index]:
            self.products[index].append(product)

        all_products, at_least_products, no_one_products = [], [], []
        for curr_product in self.products[3]:
            count = sum(curr_product in self.products[j] for j in range(3))
            if count == 0:
                no_one_products.append(curr_product)
            elif count in [1, 2]:
                at_least_products.append(curr_product)
            elif count == 3:
                all_products.append(curr_product)

        self.all_products.setPlainText("\n".join(all_products))
        self.at_least_products.setPlainText("\n".join(at_least_products))
        self.no_one_products.setPlainText("\n".join(no_one_products))
        self.text.setPlainText("\n".join(self.products[index]))

class Task6(QWidget):
    def __init__(self):
        super(Task6, self).__init__()

        layout = QVBoxLayout(self)

        self.src = QPlainTextEdit()
        self.dst = QPlainTextEdit()

        splitter = QSplitter(Qt.Horizontal)
        splitter.addWidget(self.src)
        splitter.addWidget(self.dst)

        self.submit = QPushButton("Выбрать файл")
        self.submit.clicked.connect(self.process_file)

        layout.addWidget(QLabel("Файлы"), alignment=Qt.AlignCenter)
        layout.addWidget(splitter)
        layout.addWidget(self.submit)

    def process_file(self):
        result = []
        file_name, _ = QFileDialog.getOpenFileName(self, "Open document", QDir.currentPath(), "Text documents (*.txt)")

        with open(file_name, 'r') as file:
            values = list(map(int, file.read().split()))
            length = len(values)

            i = 0
            while i < length:
                max_value = max(values[i:i+5])
                result.append(str(max_value))
                i += 5

        self.src.setPlainText(" ".join(map(str, values)))
        self.dst.setPlainText(" ".join(result))

class MainWidget(QWidget):
    def __init__(self):
        super(MainWidget, self).__init__()

        layout = QVBoxLayout(self)

        self.line = QLineEdit()
        self.button = QPushButton("&Подтвердить")
        self.button.clicked.connect(self.select_task)

        layout.addWidget(QLabel("Введите номер задания"))
        layout.addWidget(self.line)
        layout.addWidget(self.button)

    def select_task(self):
        try:
            number = int(self.line.text())
            if number == 1:
                task1 = Task1()
                task1.show()
            elif number == 2:
                task2 = Task2()
                task2.show()
            elif number == 3:
                task3 = Task3()
                task3.show()
            elif number == 4:
                task4 = Task4()
                task4.show()
            elif number == 5:
                task5 = Task5()
                task5.show()
            elif number == 6:
                task6 = Task6()
                task6.show()
            else:
                QMessageBox.warning(self, "Ошибка", "Введите корректный номер задания (1-6)")
        except ValueError:
            QMessageBox.warning(self, "Ошибка", "Введите корректный номер задания (1-6)")


def main():
    app = QApplication(sys.argv)
    main_widget = MainWidget()
    main_widget.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
