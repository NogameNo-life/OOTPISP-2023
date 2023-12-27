from PyQt5.QtCore import QCoreApplication, QMetaObject
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QTableView, QComboBox, QVBoxLayout, QHBoxLayout,
    QLabel, QLineEdit, QPushButton, QWidget, QTimeEdit, QAbstractItemView
)
from PyQt5.QtSql import QSqlDatabase, QSqlQueryModel, QSqlTableModel, QSqlQuery


class DatabaseWindow(QMainWindow):
    def __init__(self, parent=None):
        super(DatabaseWindow, self).__init__(parent)
        self.ui = Ui_DatabaseWindow()
        self.ui.setupUi(self)
        self.ui.comboBox.currentTextChanged.connect(self.on_comboBox_currentTextChanged)
        self.ui.pushButton.clicked.connect(self.on_pushButton_clicked)
        self.ui.pushButton_2.clicked.connect(self.on_pushButton_2_clicked)
        self.ui.pushButton_3.clicked.connect(self.on_pushButton_3_clicked)

        db = QSqlDatabase.addDatabase("QSQLITE")
        db.setDatabaseName("database.sqlite")
        self.on_comboBox_currentTextChanged("machine")

    def on_pushButton_clicked(self):
        in_text = self.ui.lineIn.text()
        out_text = self.ui.lineOut.text()
        result = []

        if in_text:
            result.append(f"states.state1 = '{in_text}'")
        if out_text:
            result.append(f"states.state5 = '{out_text}'")

        if result:
            query_text = (
                "SELECT machine.nom as 'number', states.state1, states.state2, states.state3, states.state4, states.state5, "
                "reys.t_out, reys.t_in, reys.t_all "
                "FROM machine"
                "INNER JOIN states ON machine.id = states.id "
                "INNER JOIN reys ON machine.nom = reys.id "
                f"WHERE {' and '.join(result)};"
            )

            model = QSqlQueryModel()
            query = QSqlQuery()
            query.exec(query_text)
            model.setQuery(query)
            self.ui.comboBox.setCurrentIndex(3)
            self.ui.tableView.setModel(model)

    def on_pushButton_2_clicked(self):
        in_text = self.ui.timeIn.text()
        out_text = self.ui.timeOut.text()
        all_text = self.ui.timeAll.text()
        result = []

        if in_text != "00:00":
            result.append(f"reys.t_in = '{in_text}'")
        if out_text != "00:00":
            result.append(f"reys.t_out = '{out_text}'")
        if all_text != "00:00":
            result.append(f"reys.t_all = '{all_text}'")

        if result:
            query_text = (
                "SELECT machine.nom as 'number', states.state1, states.state2, states.state3, states.state4, states.state5, "
                "reys.t_out, reys.t_in, reys.t_all "
                "FROM machine "
                "INNER JOIN states ON machine.id = states.id "
                "INNER JOIN reys ON machine.nom = reys.id "
                f"WHERE {' and '.join(result)};"
            )

            model = QSqlQueryModel()
            query = QSqlQuery()
            query.exec(query_text)
            model.setQuery(query)
            self.ui.comboBox.setCurrentIndex(3)
            self.ui.tableView.setModel(model)

    def on_pushButton_3_clicked(self):
        state = self.ui.lineState.text()
        query_text = (
            "SELECT machine.nom as 'number', states.state1, states.state2, states.state3, states.state4, states.state5, "
            "reys.t_out, reys.t_in, reys.t_all "
            "FROM machine "
            "INNER JOIN states ON machine.id = states.id "
            "INNER JOIN reys ON machine.nom = reys.id "
            f"WHERE states.state1 = '{state}' OR states.state2 = '{state}' OR "
            f"states.state3 = '{state}' OR states.state4 = '{state}' OR states.state5 = '{state}'"
        )

        model = QSqlQueryModel()
        query = QSqlQuery()
        query.exec(query_text)
        model.setQuery(query)
        self.ui.comboBox.setCurrentIndex(3)
        self.ui.tableView.setModel(model)

    def on_comboBox_currentTextChanged(self, arg):
        if arg == "queries":
            return
        model = QSqlTableModel()
        model.setTable(arg)
        model.setEditStrategy(QSqlTableModel.OnFieldChange)
        model.select()
        self.ui.tableView.setModel(model)


class Ui_DatabaseWindow(object):
    def setupUi(self, DatabaseWindow):
        DatabaseWindow.setObjectName("DatabaseWindow")
        DatabaseWindow.resize(818, 482)
        self.centralwidget = QWidget(DatabaseWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tableView = QTableView(self.centralwidget)
        self.tableView.setGeometry(30, 20, 671, 301)
        self.tableView.setObjectName("tableView")
        self.tableView.setEditTriggers(QAbstractItemView.NoEditTriggers)
        self.comboBox = QComboBox(self.centralwidget)
        self.comboBox.setGeometry(710, 20, 82, 28)
        self.comboBox.setObjectName("comboBox")
        self.comboBox.addItem("machine")
        self.comboBox.addItem("reys")
        self.comboBox.addItem("states")
        self.comboBox.addItem("queries")
        self.verticalLayoutWidget = QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(30, 330, 781, 145)
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout_4 = QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.verticalLayout_6 = QVBoxLayout()
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.verticalLayout = QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QLabel(self.verticalLayoutWidget)
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.label_2 = QLabel(self.verticalLayoutWidget)
        self.label_2.setObjectName("label_2")
        self.verticalLayout.addWidget(self.label_2)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.verticalLayout_4.addLayout(self.horizontalLayout_2)
        self.lineOut = QLineEdit(self.verticalLayoutWidget)
        self.lineOut.setObjectName("lineOut")
        self.verticalLayout.addWidget(self.lineOut)
        self.lineIn = QLineEdit(self.verticalLayoutWidget)
        self.lineIn.setObjectName("lineIn")
        self.verticalLayout.addWidget(self.lineIn)
        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_6 = QLabel(self.verticalLayoutWidget)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_3.addWidget(self.label_6)
        self.lineState = QLineEdit(self.verticalLayoutWidget)
        self.lineState.setObjectName("lineState")
        self.horizontalLayout_3.addWidget(self.lineState)
        self.verticalLayout_4.addLayout(self.horizontalLayout_3)
        self.pushButton_3 = QPushButton(self.verticalLayoutWidget)
        self.pushButton_3.setObjectName("pushButton_3")
        self.verticalLayout_4.addWidget(self.pushButton_3)
        self.horizontalLayout_ = QHBoxLayout()
        self.horizontalLayout_.setObjectName("horizontalLayout")
        self.verticalLayout_3 = QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.label_3 = QLabel(self.verticalLayoutWidget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_3.addWidget(self.label_3)
        self.label_5 = QLabel(self.verticalLayoutWidget)
        self.label_5.setObjectName("label_5")
        self.verticalLayout_3.addWidget(self.label_5)
        self.label_4 = QLabel(self.verticalLayoutWidget)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_3.addWidget(self.label_4)
        self.horizontalLayout_.addLayout(self.verticalLayout_3)
        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.timeOut = QTimeEdit(self.verticalLayoutWidget)
        self.timeOut.setObjectName("timeOut")
        self.verticalLayout_2.addWidget(self.timeOut)
        self.timeIn = QTimeEdit(self.verticalLayoutWidget)
        self.timeIn.setObjectName("timeIn")
        self.verticalLayout_2.addWidget(self.timeIn)
        self.timeAll = QTimeEdit(self.verticalLayoutWidget)
        self.timeAll.setObjectName("timeAll")
        self.verticalLayout_2.addWidget(self.timeAll)
        self.horizontalLayout_.addLayout(self.verticalLayout_2)
        self.verticalLayout_4.addLayout(self.horizontalLayout_)
        self.pushButton = QPushButton(self.verticalLayoutWidget)
        self.pushButton.setObjectName("pushButton")
        self.verticalLayout_4.addWidget(self.pushButton)
        self.pushButton_2 = QPushButton(self.verticalLayoutWidget)
        self.pushButton_2.setObjectName("pushButton_2")
        self.verticalLayout_4.addWidget(self.pushButton_2)
        self.horizontalLayout_4.addLayout(self.verticalLayout_4)
        self.verticalLayout_5 = QVBoxLayout()
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.verticalLayout_7 = QVBoxLayout()
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.verticalLayout_5.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setObjectName("horizontalLayout_5")
        self.horizontalLayout_5.addLayout(self.verticalLayout_5)
        self.horizontalLayout_5.setStretch(0, 1)
        self.centralwidget.setLayout(self.horizontalLayout_5)
        DatabaseWindow.setCentralWidget(self.centralwidget)

        self.retranslateUi(DatabaseWindow)
        QMetaObject.connectSlotsByName(DatabaseWindow)

    def retranslateUi(self, DatabaseWindow):
        _translate = QCoreApplication.translate
        DatabaseWindow.setWindowTitle(_translate("DatabaseWindow", "DatabaseWindow"))
        self.label.setText(_translate("DatabaseWindow", "Откуда"))
        self.label_2.setText(_translate("DatabaseWindow", "Куда"))
        self.pushButton.setText(_translate("DatabaseWindow", "Найти по маршруту"))
        self.label_3.setText(_translate("DatabaseWindow", "Время отправления"))
        self.label_5.setText(_translate("DatabaseWindow", "Время прибытия"))
        self.label_4.setText(_translate("DatabaseWindow", "Общее время в пути"))
        self.pushButton_2.setText(_translate("DatabaseWindow", "Найти по времени"))
        self.label_6.setText(_translate("DatabaseWindow", "Станция"))
        self.pushButton_3.setText(_translate("DatabaseWindow", "Проходящие через станцию"))


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    main_window = DatabaseWindow()
    main_window.show()
    sys.exit(app.exec_())
