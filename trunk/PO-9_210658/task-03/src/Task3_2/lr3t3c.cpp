#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> linkedList;

    srand(time(nullptr));
    for (int i = 0; i < 10; ++i) {
        int randomData = rand() % 100;
        linkedList.push_back(randomData);
    }

    std::cout << "Initial list: ";
    for (const auto& element : linkedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    linkedList.sort(std::greater<int>());

    std::cout << "Sorted list: ";
    for (const auto& element : linkedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}