# Лабораторная работа № 6

## Тема

Изучение UML. Диаграмма классов.

## Цель работы

Освоить построение диаграммы классов.

## Порядок выполнения

1. Изучить теоретический материал из [документации](https://mermaid.js.org/intro/getting-started.html).
2. Выбрать свой вариант.
3. Нарисовать каждый класс отдельно с методами и полями.
4. Оформить отчет.

## Вариант 14(4).

 Постройте UML диаграмму классов для системы управления персоналом.

## Диаграмма

```mermaid
classDiagram
    class Employee {
        - id: int
        - name: string
        - position: string
        - salary: float
        + Employee(id: int, name: string, position: string, salary: float)
        + getId(): int
        + getName(): string
        + getPosition(): string
        + getSalary(): float
        + setName(name: string): void
        + setPosition(position: string): void
        + setSalary(salary: float): void
    }

    class Department {
        - id: int
        - name: string
        + Department(id: int, name: string)
        + getId(): int
        + getName(): string
        + setName(name: string): void
    }

    class HRSystem {
        - employees: List<Employee>
        - departments: List<Department>
        + addEmployee(employee: Employee): void
        + removeEmployee(employee: Employee): void
        + listEmployees(): List<Employee>
        + addDepartment(department: Department): void
        + removeDepartment(department: Department): void
        + listDepartments(): List<Department>
        + assignEmployeeToDepartment(employee: Employee, department: Department): void
    }

    Employee -- Department : belongs to
    HRSystem o-- Employee : contains
    HRSystem o-- Department : contains

