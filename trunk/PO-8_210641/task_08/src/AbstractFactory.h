#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <iostream>

class List {
public:
    virtual void render() const = 0;
    virtual List* clone() = 0;
    virtual ~List() {}
};

class InputField {
public:
    virtual void render() const = 0;
    virtual InputField* clone() = 0;
    virtual ~InputField() {}
};

class Button {
public:
    virtual void render() const = 0;
    virtual Button* clone() = 0;
    virtual ~Button() {}
};

class Language {
public:
    virtual void display() const = 0;
    virtual Language* clone() = 0;
    virtual ~Language() {}
};

class WindowsList : public List {
public:
    void render() const override {
        std::cout << "Windows list" << std::endl;
    }

    List* clone() override {
        return new WindowsList();
    }
};

class WindowsInputField : public InputField {
public:
    void render() const override {
        std::cout << "Windows input field" << std::endl;
    }

    InputField* clone() override {
        return new WindowsInputField();
    }
};

class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Windows button" << std::endl;
    }

    Button* clone() override {
        return new WindowsButton();
    }
};

class WindowsLanguage : public Language {
public:
    void display() const override {
        std::cout << "English language" << std::endl;
    }

    Language* clone() override {
        return new WindowsLanguage();
    }
};

class AbstractFactory {
public:
    virtual List* createList() const = 0;
    virtual InputField* createInputField() const = 0;
    virtual Button* createButton() const = 0;
    virtual Language* createLanguage() const = 0;
    virtual ~AbstractFactory() {}
};

class AbstractPrototypeFactory : public AbstractFactory {
public:
    AbstractPrototypeFactory(List* ls, InputField* ifl, Button* btn, Language* lng);
    virtual ~AbstractPrototypeFactory();

    List* createList() const override;
    InputField* createInputField() const override;
    Button* createButton() const override;
    Language* createLanguage() const override;

private:
    List* listPrototype;
    InputField* inputFieldPrototype;
    Button* buttonPrototype;
    Language* languagePrototype;
};

class WindowsFactory : public AbstractFactory {
public:
    List* createList() const override;
    InputField* createInputField() const override;
    Button* createButton() const override;
    Language* createLanguage() const override;
};

class SingletonWindowsFactory : public AbstractFactory {
private:
    SingletonWindowsFactory();
    static SingletonWindowsFactory* instance;

public:
    static SingletonWindowsFactory* getInstance();
    List* createList() const override;
    InputField* createInputField() const override;
    Button* createButton() const override;
    Language* createLanguage() const override;
};

#endif // ABSTRACTFACTORY_H
