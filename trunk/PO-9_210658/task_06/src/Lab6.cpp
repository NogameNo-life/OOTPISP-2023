#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    std::vector<std::string> courses;

public:
    Student(const std::string& studentName) : name(studentName) {}

    void enrollCourse(const std::string& courseName) {
        courses.push_back(courseName);
        std::cout << name << " enrolled in " << courseName << std::endl;
    }

    void displayCourses() {
        std::cout << name << "'s courses: ";
        for (const auto& course : courses) {
            std::cout << course << ", ";
        }
        std::cout << std::endl;
    }

    const std::string& getName() const {
        return name;
    }
};

class Teacher {
private:
    std::string name;
    std::vector<std::string> courses;

public:
    Teacher(const std::string& teacherName) : name(teacherName) {}

    void addCourse(const std::string& courseName) {
        courses.push_back(courseName);
        std::cout << name << " added a new course: " << courseName << std::endl;
    }

    void displayCourses() {
        std::cout << name << "'s courses: ";
        for (const auto& course : courses) {
            std::cout << course << ", ";
        }
        std::cout << std::endl;
    }

    const std::string& getName() const {
        return name;
    }
};

class Group {
private:
    std::string name;
    Teacher* classTeacher;
    std::vector<Student*> students;

public:
    Group(const std::string& groupName, Teacher* teacher) : name(groupName), classTeacher(teacher) {}

    void addStudent(Student* student) {
        students.push_back(student);
        std::cout << "Added student " << student->getName() << " to group " << name << std::endl;
    }

    void displayStudents() {
        std::cout << "Students in group " << name << ":" << std::endl;
        for (const auto& student : students) {
            std::cout << student->getName() << std::endl;
        }
    }

    Teacher* getClassTeacher() const {
        return classTeacher;
    }
};

class Schedule {
private:
    std::vector<std::string> courses;
    std::vector<Teacher*> teachers;

public:
    void addCourse(const std::string& courseName) {
        courses.push_back(courseName);
        std::cout << "Added a new course to the schedule: " << courseName << std::endl;
    }

    void addTeacher(Teacher* teacher) {
        teachers.push_back(teacher);
        std::cout << "Added teacher " << teacher->getName() << " to the schedule" << std::endl;
    }

    void displaySchedule() {
        std::cout << "Schedule:" << std::endl;
        for (const auto& course : courses) {
            std::cout << course << " - ";
            if (!teachers.empty()) {
                std::cout << teachers.front()->getName();
                teachers.push_back(teachers.front());
                teachers.erase(teachers.begin());
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Schedule schedule;
    schedule.addCourse("Math");
    schedule.addCourse("Science");
    schedule.addCourse("History");
    std::cout << std::endl;
    Teacher mrSmith("Mr. Smith");
    Teacher msJohnson("Ms. Johnson");

    schedule.addTeacher(&mrSmith);
    schedule.addTeacher(&msJohnson);
    std::cout << std::endl;
    Group groupA("Group A", &mrSmith);
    Group groupB("Group B", &msJohnson);

    Student john("John");
    Student emily("Emily");
    Student michael("Michael");
    std::cout << std::endl;
    groupA.addStudent(&john);
    groupA.addStudent(&emily);
    groupB.addStudent(&michael);

    john.enrollCourse("Math");
    emily.enrollCourse("Science");
    michael.enrollCourse("History");

    std::cout << "\nClass Teachers:" << std::endl;
    std::cout << "Group A: " << groupA.getClassTeacher()->getName() << std::endl;
    std::cout << "Group B: " << groupB.getClassTeacher()->getName() << std::endl;

    std::cout << "Schedule:" << std::endl;
    schedule.displaySchedule();

    return 0;
}