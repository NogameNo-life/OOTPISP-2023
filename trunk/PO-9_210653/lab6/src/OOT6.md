```mermaid
classDiagram

    class Employee {
        - int employeeID
        - string name
        - string department
        - string position
        - double salary
        --
        + Employee(int id, string empName, string dept, string pos, double sal)
        + int getEmployeeID()
        + string getName()
        + string getDepartment()
        + string getPosition()
        + double getSalary()
    }

    class EmployeeDatabase {
        - vector<Employee> employees
        --
        + void addEmployee(Employee emp)
        + void removeEmployee(int employeeID)
        + Employee& findEmployeeByID(int employeeID)
    }

    class Payroll {
        --
        + double calculateSalary(Employee emp)
    }

    class HRDepartment {
        --
        + void hireEmployee(Employee emp)
        + void dismissEmployee(int employeeID)
    }

    class ReportGenerator {
        --
        + void generateEmployeeReport(Employee emp)
        + void generateDepartmentReport(string department)
    }

    Employee <-- EmployeeDatabase
    Employee <-- Payroll
    Employee <-- HRDepartment
    Employee <-- ReportGenerator
