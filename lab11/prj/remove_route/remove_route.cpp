#include "remove_route.h"
#include <iostream>
#include <algorithm>

void ScheduleSystem::removeRoute() {
    int id;
    std::cout << "Введіть номер рейсу для видалення: ";
    std::cin >> id;
    std::cin.ignore();

    auto it = std::remove_if(routes.begin(), routes.end(), [id](const BusRoute& r) {
        return r.id == id;
    });

    if (it != routes.end()) {
        routes.erase(it, routes.end());
        std::cout << "Рейс видалено.\n";
    }
    else {
        std::cout << "Рейс не знайдено.\n";
    }
}
