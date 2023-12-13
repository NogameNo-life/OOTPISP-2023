#include <iostream>
#include <vector>

class Employee {
private:
    int employeeID;
    std::string name;
    std::string department;
    std::string position;
    double salary;

public:
    Employee(int id, const std::string& empName, const std::string dept, const std::string pos, double sal)
        : employeeID(id), name(empName), department(dept), position(pos), salary(sal) {}

    int getEmployeeID() const { return employeeID; }
    std::string getName() const { return name; }
    std::string getDepartment() const { return department; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
};

class EmployeeDatabase {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const Employee& emp) { employees.push_back(emp); }
    void removeEmployee(int employeeID);
    Employee& findEmployeeByID(int employeeID);
};

class Payroll {
public:
    double calculateSalary(const Employee& emp) {
        return emp.getSalary();
    }
};

class HRDepartment {
public:
    void hireEmployee(const Employee& emp);
    void dismissEmployee(int employeeID);
};

class ReportGenerator {
public:
    void generateEmployeeReport(const Employee& emp);
    void generateDepartmentReport(const std::string& department);
};

void EmployeeDatabase::removeEmployee(int employeeID) {
}

Employee& EmployeeDatabase::findEmployeeByID(int employeeID) {
}

void HRDepartment::hireEmployee(const Employee& emp) {
}

void HRDepartment::dismissEmployee(int employeeID) {
}

void ReportGenerator::generateEmployeeReport(const Employee& emp) {
}

void ReportGenerator::generateDepartmentReport(const std::string& department) {
}

//А вдруг теперь заработает ?
