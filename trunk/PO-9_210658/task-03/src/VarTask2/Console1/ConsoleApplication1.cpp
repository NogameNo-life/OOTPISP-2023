#include <iostream>
#include <vector>
#include <cctype>
#include <string>
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
    std::string input;
    std::vector<int> array;
    std::cout << "Fill the array\n:";

    while (true) {
        std::cin >> input;
        bool isNumeric = true;
        for (char ch : input) {
            if (!isdigit(ch)) {
                isNumeric = false;
                break;
            }
        }
        if (isNumeric) {
            array.push_back(stoi(input));
        }
        else {
            break;
        }
    }
    cout << "\n___________Initial array___________\n";
    PrintVector(array);
    for (int i = 1; i < array.size()-1; ++i) {
        if (i % 2 != 0) {
            array[i] = array[i] + array[0];
        }
    }
    cout << "\n___________Converted array___________\n";
    PrintVector(array);
    return 0;
}
