#include <iostream>
#include <vector>

usingnamespace std;

class Employee {
private:
    int id;
    string name;
    string position;
    float salary;

public:
    Employee(int id, string name, string position, float salary)
        : id(id), name(name), position(position), salary(salary) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    float getSalary() const { return salary; }

    void setName(string newName) { name = newName; }
    void setPosition(string newPosition) { position = newPosition; }
    void setSalary(float newSalary) { salary = newSalary; }
};

class Department {
private:
    int id;
    string name;

public:
    Department(int id, string name)
        : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }

    void setName(string newName) { name = newName; }
};

class HRSystem {
private:
    vector<Employee> employees;
    vector<Department> departments;

public:
    void addEmployee(Employee employee);
    void removeEmployee(Employee employee);
    vector<Employee> listEmployees() const;

    void addDepartment(Department department);
    void removeDepartment(Department department);
    vector<Department> listDepartments() const;

    void assignEmployeeToDepartment(Employee employee, Department department);
};

int main() {
    Employee emp1(1, "Иван", "Менеджер", 50000.0);
    Employee emp2(2, "Мария", "Разработчик", 60000.0);

    Department dept1(101, "Отдел продаж");
    Department dept2(102, "Отдел разработки");

    HRSystem hrSystem;
    hrSystem.addEmployee(emp1);
    hrSystem.addEmployee(emp2);

    hrSystem.addDepartment(dept1);
    hrSystem.addDepartment(dept2);

    return 0;
}
