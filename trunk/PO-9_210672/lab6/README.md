
# Лабораторная работа №6

## Изучение UML. Диаграмма классов

## Вариант 23

## Цель лабораторной работы

Освоить построение диаграммы классов.

## Задание

Постройте UML диаграмму классов для системы управления медицинской клиникой.

## Ход работы

```mermaid
classDiagram
    class Patient {
        +getName(): string
        +getAge(): int
        +getAddress(): string
    }

    class Doctor {
        +getName(): string
        +getSpecialization(): string
    }

    class Appointment {
        +getPatient(): Patient
        +getDoctor(): Doctor
        +getDate(): string
    }

    class MedicalRecord {
        +getPatient(): Patient
    }

    class MedicalClinic {
        +scheduleAppointment(patient: Patient, doctor: Doctor, date: string): void
    }

    Patient --|> MedicalRecord : has
    Appointment --|> Patient : involves
    Appointment --|> Doctor : involves
    MedicalClinic --|> Appointment : schedules
    MedicalClinic --|> Patient : manages
    MedicalClinic --|> Doctor : manages

```
