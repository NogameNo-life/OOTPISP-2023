
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

## Вариант 9 (19 % 10)

- Постройте UML диаграмму классов для системы управления учебным процессом в школе.

## Диаграмма

```mermaid
classDiagram

class Student {
  - Name
  - Surname
  - Age
  - Class
  - Subjects
  - Grades
  + GetInfo()
  + AddSubject()
  + AddGrade()
}

class Teacher {
  - Name
  - Surname
  - Age
  - Subjects
  - Classes
  - Students
  + AddStudent()
  + SetGrade()
  + ManageProcess()
}

class Subject {
  - Name
  - Grades
  - Students
  + AddStudent()
  + AddGrade()
}

class Classroom {
  - ClassName
  - Students
  - Subjects
  - Schedule
  + AddStudent()
  + AddSubject()
  + ManageSchedule()
}

class School {
  - SchoolName
  - Classes
  - Teachers
  + ManageClasses()
  + AddTeacher()
}

Student -- Teacher
Teacher -- Subject
Student -- Subject
Classroom -- Student
Classroom -- Subject
School -- Classroom
School -- Teacher
