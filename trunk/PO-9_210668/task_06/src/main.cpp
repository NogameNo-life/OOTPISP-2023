#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name = "KTO-TO";
    std::string surname = "KTOSTY";
    int age = 18;
    int grade = 5;
    std::vector<std::string> subjects;
    std::vector<int> grades;

public:
    void GetInfo() {
        std::cout << "Name: " << name << " " << surname << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Grade: " << grade << std::endl;
    }

    void AddSubject(std::string subject) {
        subjects.push_back(subject);
    }

    void AddGrade(int grade) {
        grades.push_back(grade);
    }
};

class Teacher {
private:
    std::string name = "Tek";
    std::string surname = "New";
    int age = 0; // Инициализация значения по умолчанию
    std::vector<std::string> subjects;

public:
    // Конструктор класса Teacher
    Teacher(int teacherAge) : age(teacherAge) {}

    void ManageProcess() {
        std::cout << "Teacher " << name << " " << surname << " is managing the educational process." << std::endl;
    }
};

class Subject {
private:
    std::string name = ""; // Инициализация значения по умолчанию
    std::vector<int> grades;
    std::vector<Student> students;

public:
    // Конструктор класса Subject
    Subject(std::string subjectName) : name(subjectName) {}

    void AddStudent(Student student) {
        students.push_back(student);
    }

    void AddGrade(int grade) {
        grades.push_back(grade);
    }
};

class Classroom {
private:
    std::string className = ""; // Инициализация значения по умолчанию
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::string schedule = ""; // Инициализация значения по умолчанию

public:
    // Конструктор класса Classroom
    Classroom(std::string name) : className(name) {}

    void AddStudent(Student student) {
        students.push_back(student);
    }

    void AddSubject(Subject subject) {
        subjects.push_back(subject);
    }

    void ManageSchedule() {
        std::cout << "Managing schedule for class " << className << std::endl;
    }
};

class School {
private:
    std::string schoolName = ""; // Инициализация значения по умолчанию
    std::vector<Classroom> classes;
    std::vector<Teacher> teachers;

public:
    // Конструктор класса School
    School(std::string name) : schoolName(name) {}

    void AddTeacher(Teacher teacher) {
        teachers.push_back(teacher);
    }

    void AddClass(Classroom classroom) {
        classes.push_back(classroom);
    }

    void ManageClasses() {
        std::cout << "Managing classes in " << schoolName << std::endl;
    }
};

int main() {
    // Используем конструкторы для инициализации объектов
    School mySchool("My School");
    Teacher teacher(30);
    Student student;
    Subject subject("Math");
    Classroom classroom("Class A");

    mySchool.AddTeacher(teacher);
    mySchool.AddClass(classroom);
    classroom.AddStudent(student);
    classroom.AddSubject(subject);

    teacher.ManageProcess();
    student.GetInfo();

    return 0;
}
