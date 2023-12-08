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

    void AddSubject(const std::string& subject) {
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
    int age = 0;

public:
    explicit Teacher(int teacherAge) : age(teacherAge) {}

    void ManageProcess() {
        std::cout << "Teacher " << name << " " << surname << " is managing the educational process." << std::endl;
    }
};

class Subject {
private:
    std::string name = "";
    std::vector<int> grades;
    std::vector<Student> students;

public:
    explicit Subject(const std::string& subjectName) : name(subjectName) {}

    void AddStudent(const Student& student) {
        students.push_back(student);
    }

    void AddGrade(int grade) {
        grades.push_back(grade);
    }
};

class Classroom {
private:
    std::string className = "";
    std::vector<Student> students;
    std::vector<Subject> subjects;
    std::string schedule = "";

public:
    explicit Classroom(const std::string& name) : className(name) {}

    void AddStudent(const Student& student) {
        students.push_back(student);
    }

    void AddSubject(const Subject& subject) {
        subjects.push_back(subject);
    }

    void ManageSchedule() {
        std::cout << "Managing schedule for class " << className << std::endl;
    }
};

class School {
private:
    std::string schoolName = "";
    std::vector<Classroom> classes;
    std::vector<Teacher> teachers;

public:
    explicit School(const std::string& name) : schoolName(name) {}

    void AddTeacher(const Teacher& teacher) {
        teachers.push_back(teacher);
    }

    void AddClass(const Classroom& classroom) {
        classes.push_back(classroom);
    }

    void ManageClasses() {
        std::cout << "Managing classes in " << schoolName << std::endl;
    }
};

int main() {
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
