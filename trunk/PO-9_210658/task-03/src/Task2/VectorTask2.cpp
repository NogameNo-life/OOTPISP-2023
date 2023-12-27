#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    vector<int> v1;
    cout << "Найдем сумму чисел от n до m оптимизировав метод\nВведите n и m: ";
    int n, m;
    cin >> n >> m;
    if (m <= n) {
        cout << "Try again!";
        main();
    }
    for (; n < m+1; ++n) {
        v1.push_back(n);
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (i < v1.size() - 2) {
            replace(v1.begin(), v1.end(), v1[i+1], v1[i] + v1[i + 1]);
        }
        else {
            cout << "Sum: " << v1[i] + v1[i + 1];
            break;
        }
    }
}