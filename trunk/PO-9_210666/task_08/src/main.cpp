#include <iostream>

#include "AbstractFactory.h"


int main() {
    AbstractFactory* linuxFactory = new LinuxFactory();

    List* list = linuxFactory->createList();
    InputField* inputField = linuxFactory->createInputField();
    Button* button = linuxFactory->createButton();
    Language* language = linuxFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();
    
    return 0;
}
