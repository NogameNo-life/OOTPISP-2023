#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <random>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    list<int> myList;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    // Заполнение списка случайными элементами
    for (int i = 0; i < 10; ++i) {
        myList.push_back(dis(gen));
    }

    // Вывод содержимого списка до сортировки
    cout << "Список до сортировки:\n";
    for (auto const& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    // Сортировка списка по убыванию
    myList.sort(greater<int>());

    // Вывод содержимого списка после сортировки
    cout << "Список после сортировки:\n";
    for (auto const& item : myList) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}