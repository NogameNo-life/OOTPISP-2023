from abc import ABC, abstractmethod

# Продукты фабрики
class UIList(ABC):
    @abstractmethod
    def display(self):
        pass

class UIInputField(ABC):
    @abstractmethod
    def interact(self):
        pass

class UIButton(ABC):
    @abstractmethod
    def click(self):
        pass

class Language(ABC):
    @abstractmethod
    def set_language(self):
        pass

# Абстрактная фабрика
class UIFactory(ABC):
    @abstractmethod
    def create_list(self):
        pass

    @abstractmethod
    def create_input_field(self):
        pass

    @abstractmethod
    def create_button(self):
        pass

    @abstractmethod
    def create_language(self):
        pass

# Конкретные продукты
class WindowsUIList(UIList):
    def display(self):
        print("Windows style list")

class WindowsUIInputField(UIInputField):
    def interact(self):
        print("Windows style input field")

class WindowsUIButton(UIButton):
    def click(self):
        print("Windows style button")

class EnglishLanguage(Language):
    def set_language(self):
        print("English language")

# Конкретная фабрика
class WindowsUIFactory(UIFactory):
    def create_list(self):
        return WindowsUIList()

    def create_input_field(self):
        return WindowsUIInputField()

    def create_button(self):
        return WindowsUIButton()

    def create_language(self):
        return EnglishLanguage()


if __name__ == "__main__":
    windows_factory = WindowsUIFactory()

    windows_list = windows_factory.create_list()
    windows_list.display()

    windows_input_field = windows_factory.create_input_field()
    windows_input_field.interact()

    windows_button = windows_factory.create_button()
    windows_button.click()

    english_language = windows_factory.create_language()
    english_language.set_language()
