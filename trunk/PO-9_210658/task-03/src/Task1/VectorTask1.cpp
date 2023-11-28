#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

void PrintVector(const vector<int>& vec) {
    int iterator = 0, size = vec.size();
    cout << "Vector contains: {";
    for (auto& el : vec) {
        ++iterator;
        cout << el;
        if (iterator > size - 1) {

        }
        else {
            cout << ", ";
        }
    }
    cout << "}\n";
}

int main()
{
    srand(time(0));
    vector<int> vector1{ 1, 2, 3, 4, 5 };

    vector<int> vector2;
    vector2.push_back(6);
    vector2.push_back(7);
    vector2.push_back(8);
    vector2.push_back(9);
    vector2.push_back(10);

    vector<int> vector3;
    for (int i = 11; i < 16; ++i) {
        vector3.push_back(i);
    }

    vector<int> vector4;
    for (int i = 0; i < 5; ++i) {
        vector4.push_back(rand() % 20);
    }

    vector<int> vector5;
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; ++i) {
        int input = int(_getch()) - 48;
        if (i != 0) {
            cout << ", " << input;
        }
        else { cout << input; }
        vector5.push_back(input);
    }
    cout << endl;
    cout << "\n---------------First---------------\n";
    PrintVector(vector1);
    cout << "-----------------------------------\n";
    cout << "\n---------------Second---------------\n";
    PrintVector(vector2);
    cout << "------------------------------------\n";
    cout << "\n---------------Third---------------\n";
    PrintVector(vector3);
    cout << "-----------------------------------\n";
    cout << "\n---------------Fourth---------------\n";
    PrintVector(vector4);
    cout << "------------------------------------\n";
    cout << "\n---------------Fifth---------------\n";
    PrintVector(vector5);
    cout << "-----------------------------------\n";
}
