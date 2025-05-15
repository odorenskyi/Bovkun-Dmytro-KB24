#include "add_route.h"
#include <iostream>

void ScheduleSystem::addRoute() {
    BusRoute r;
    std::cout << "Номер рейсу (ID): ";
    std::cin >> r.id;
    std::cin.ignore();

    for (const auto& route : routes) {
        if (route.id == r.id) {
            std::cout << "Рейс з таким ID уже існує!\n";
            return;
        }
    }

    std::cout << "Маршрут: "; std::getline(std::cin, r.route);
    std::cout << "Періодичність: "; std::getline(std::cin, r.frequency);
    std::cout << "Період дії: "; std::getline(std::cin, r.period);
    std::cout << "Прибуття (початкова): "; std::getline(std::cin, r.startArrive);
    std::cout << "Відправлення (початкова): "; std::getline(std::cin, r.startDepart);
    std::cout << "Відправлення (кінцева): "; std::getline(std::cin, r.endDepart);
    std::cout << "Прибуття (кінцева): "; std::getline(std::cin, r.endArrive);

    routes.push_back(r);
    std::cout << "Рейс додано.\n";
}
