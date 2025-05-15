#include "print_schedule.h"
#include <iostream>

void ScheduleSystem::printSchedule() const {
    std::cout << "Кількість рейсів: " << routes.size() << "\n";
    if (routes.empty()) {
        std::cout << "Розклад порожній або не завантажено.\n";
        return;
    }

    for (const auto& r : routes) {
        std::cout << "ID: " << r.id << "\n"
            << "Маршрут: " << r.route << "\n"
            << "Періодичність: " << r.frequency << "\n"
            << "Період дії: " << r.period << "\n"
            << "Прибуття (початкова): " << r.startArrive << "\n"
            << "Відправлення (початкова): " << r.startDepart << "\n"
            << "Відправлення (кінцева): " << r.endDepart << "\n"
            << "Прибуття (кінцева): " << r.endArrive << "\n"
            << "------------------------------------\n";
    }
}
