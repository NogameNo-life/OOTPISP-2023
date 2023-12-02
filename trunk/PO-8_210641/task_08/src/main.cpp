#include "AbstractFactory.h"
#include "Builder.h"

int main() {
    AbstractFactory* windowsFactory = new WindowsFactory();

    List* list = windowsFactory->createList();
    InputField* inputField = windowsFactory->createInputField();
    Button* button = windowsFactory->createButton();
    Language* language = windowsFactory->createLanguage();

    list->render();
    inputField->render();
    button->render();
    language->display();

    delete windowsFactory;
    delete list;
    delete inputField;
    delete button;
    delete language;

    ConcreteRobotBuilder concreteBuilder;
    Director director;
    director.buildRobot(&concreteBuilder);
    Robot* robot = concreteBuilder.getRobot();

    std::cout << "Robot Information:" << std::endl;
    std::cout << "Head: " << robot->getHead()->getInfo() << std::endl;
    std::cout << "Body: " << robot->getBody()->getInfo() << std::endl;
    std::cout << "Engine: " << robot->getEngine()->getInfo() << std::endl;

    delete robot;

    return 0;
}