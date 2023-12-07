#include <iostream>
#include <unordered_map>

// Абстрактные продукты
class Widget {
public:
    virtual void draw() = 0;
    virtual Widget* clone() = 0;
    virtual ~Widget() = default;
};

class List : public Widget {
public:
    void draw() override {
        std::cout << "Drawing a List.\n";
    }

    Widget* clone() override {
        return new List(*this);
    }
};

class InputField : public Widget {
public:
    void draw() override {
        std::cout << "Drawing an InputField.\n";
    }

    Widget* clone() override {
        return new InputField(*this);
    }
};

class Button : public Widget {
public:
    void draw() override {
        std::cout << "Drawing a Button.\n";
    }

    Widget* clone() override {
        return new Button(*this);
    }
};

class Language : public Widget {
public:
    void draw() override {
        std::cout << "Drawing a Language.\n";
    }

    Widget* clone() override {
        return new Language(*this);
    }
};

// Абстрактная фабрика с прототипами
class GUIFactory {
private:
    std::unordered_map<std::string, Widget*> prototypes;

public:
    virtual Widget* createList() = 0;
    virtual Widget* createInputField() = 0;
    virtual Widget* createButton() = 0;
    virtual Widget* createLanguage() = 0;

    virtual ~GUIFactory() {
        // Удаление прототипов при уничтожении фабрики
        for (auto& pair : prototypes) {
            delete pair.second;
        }
        prototypes.clear();
    }

protected:
    void addPrototype(const std::string& key, Widget* prototype) {
        prototypes[key] = prototype;
    }

    Widget* getPrototype(const std::string& key) const {
        auto it = prototypes.find(key);
        if (it != prototypes.end()) {
            return it->second;
        }
        return nullptr;
    }
};

// Конкретная фабрика
class ConcreteGUIFactory : public GUIFactory {
public:
    ConcreteGUIFactory() {
        // Инициализация прототипов
        addPrototype("List", new List());
        addPrototype("InputField", new InputField());
        addPrototype("Button", new Button());
        addPrototype("Language", new Language());
    }

    Widget* createList() override {
        return getPrototype("List")->clone();
    }

    Widget* createInputField() override {
        return getPrototype("InputField")->clone();
    }

    Widget* createButton() override {
        return getPrototype("Button")->clone();
    }

    Widget* createLanguage() override {
        return getPrototype("Language")->clone();
    }
};

int main() {
    ConcreteGUIFactory factory;

    // Использование фабрики
    Widget* list = factory.createList();
    list->draw();
    delete list;

    Widget* inputField = factory.createInputField();
    inputField->draw();
    delete inputField;

    Widget* button = factory.createButton();
    button->draw();
    delete button;

    Widget* language = factory.createLanguage();
    language->draw();
    delete language;

    return 0;
}
