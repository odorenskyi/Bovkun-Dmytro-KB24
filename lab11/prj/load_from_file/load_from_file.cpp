#include "load_from_file.h"
#include <iostream>
#include <fstream>
#include <sstream>

void ScheduleSystem::loadFromFile() {
    std::cout << "Спроба відкрити файл: " << filename << "\n";
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Не вдалося відкрити файл: " << filename << "\n";
        return;
    }

    routes.clear();
    std::string line;
    int lineNumber = 0;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
        lineNumber++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string field;
        BusRoute r;

        try {
            if (!std::getline(ss, field, ';') || field.empty()) throw std::runtime_error("Неправильний ID");
            r.id = std::stoi(field);
            if (!std::getline(ss, r.route, ';') || r.route.empty()) throw std::runtime_error("Неправильний маршрут");
            if (!std::getline(ss, r.frequency, ';') || r.frequency.empty()) throw std::runtime_error("Неправильна періодичність");
            if (!std::getline(ss, r.period, ';') || r.period.empty()) throw std::runtime_error("Неправильний період");
            if (!std::getline(ss, r.startArrive, ';') || r.startArrive.empty()) throw std::runtime_error("Неправильне прибуття (початкова)");
            if (!std::getline(ss, r.startDepart, ';') || r.startDepart.empty()) throw std::runtime_error("Неправильне відправлення (початкова)");
            if (!std::getline(ss, r.endDepart, ';') || r.endDepart.empty()) throw std::runtime_error("Неправильне відправлення (кінцева)");
            if (!std::getline(ss, r.endArrive, ';') || r.endArrive.empty()) throw std::runtime_error("Неправильне прибуття (кінцева)");

            routes.push_back(r);
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << lineNumber << ": " << e.what() << "\n";
        }
    }
    fin.close();
    std::cout << "Зчитано " << routes.size() << " рейсів.\n";
}
