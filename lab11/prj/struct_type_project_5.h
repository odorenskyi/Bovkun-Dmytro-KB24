#ifndef STRUCT_TYPE_PROJECT_5_H_INCLUDED
#define STRUCT_TYPE_PROJECT_5_H_INCLUDED

#include <string>
using namespace std;

// Структура для зберігання інформації про рейс автобуса
struct BusSchedule {
    int routeNumber;               // Номер рейсу (унікальний)
    string departureStop;          // Станція відправлення
    string arrivalStop;            // Станція прибуття
    string frequency;              // Частота руху (наприклад, "Щодня", "Парні дні", "Непарні дні")
    string departureTime;          // Час відправлення (формат "HH:MM")
    string arrivalTime;            // Час прибуття (формат "HH:MM")

    // Конструктор за замовчуванням
    BusSchedule()
        : routeNumber(0), departureStop(""), arrivalStop(""),
          frequency(""), departureTime(""), arrivalTime("") {}

    // Конструктор з параметрами
    BusSchedule(int rn, const string &dep, const string &arr, const string &freq,
                const string &depTime, const string &arrTime)
        : routeNumber(rn), departureStop(dep), arrivalStop(arr),
          frequency(freq), departureTime(depTime), arrivalTime(arrTime) {}
};

// Вузол однозв’язного списку, що містить запис про автобусний рейс
struct Node {
    BusSchedule record; // Запис розкладу
    Node* next;         // Вказівник на наступний вузол

    // Конструктор вузла
    Node(const BusSchedule &rec)
        : record(rec), next(nullptr) {}
};

#endif // STRUCT_TYPE_PROJECT_5_H_INCLUDED
