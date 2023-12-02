#include "AbstractFactory.h"

AbstractPrototypeFactory::AbstractPrototypeFactory(List* ls, InputField* ifl, Button* btn, Language* lng)
    : listPrototype(ls), inputFieldPrototype(ifl), buttonPrototype(btn), languagePrototype(lng) {}

AbstractPrototypeFactory::~AbstractPrototypeFactory() {
    delete listPrototype;
    delete inputFieldPrototype;
    delete buttonPrototype;
    delete languagePrototype;
}

List* AbstractPrototypeFactory::createList() const {
    return listPrototype->clone();
}

InputField* AbstractPrototypeFactory::createInputField() const {
    return inputFieldPrototype->clone();
}

Button* AbstractPrototypeFactory::createButton() const {
    return buttonPrototype->clone();
}

Language* AbstractPrototypeFactory::createLanguage() const {
    return languagePrototype->clone();
}

List* WindowsFactory::createList() const {
    return new WindowsList();
}

InputField* WindowsFactory::createInputField() const {
    return new WindowsInputField();
}

Button* WindowsFactory::createButton() const {
    return new WindowsButton();
}

Language* WindowsFactory::createLanguage() const {
    return new WindowsLanguage();
}

SingletonWindowsFactory::SingletonWindowsFactory() {}

SingletonWindowsFactory* SingletonWindowsFactory::getInstance() {
    if (instance == nullptr) {
        instance = new SingletonWindowsFactory();
    }
    return instance;
}

List* SingletonWindowsFactory::createList() const {
    return new WindowsList();
}

InputField* SingletonWindowsFactory::createInputField() const {
    return new WindowsInputField();
}

Button* SingletonWindowsFactory::createButton() const {
    return new WindowsButton();
}

Language* SingletonWindowsFactory::createLanguage() const {
    return new WindowsLanguage();
}

SingletonWindowsFactory* SingletonWindowsFactory::instance = nullptr;
