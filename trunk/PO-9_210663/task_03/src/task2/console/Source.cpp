#include <iostream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите размер массива: ";
    cin >> N;

    if (N <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    vector<int> arr(N);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < N; i++) {
        cout << "Элемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    if (N >= 3) {
        int firstElement = arr[0];
        for (int i = 1; i < N - 1; i++) {
            if (arr[i] % 2 == 0) {
                arr[i] += firstElement;
            }
        }
    }

    cout << "Преобразованный массив:\n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
