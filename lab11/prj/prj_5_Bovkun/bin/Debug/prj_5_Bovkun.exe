#include "constructor.h"
#include "add_route.h"
#include "remove_route.h"
#include "load_from_file.h"
#include "save_to_file.h"
#include "print_schedule.h"
#include "search_by_station.h"

int main() {
    ScheduleSystem system("routes.txt");

    int choice;
    do {
        std::cout << "\n1. Додати рейс\n"
                  << "2. Видалити рейс\n"
                  << "3. Завантажити з файлу\n"
                  << "4. Зберегти у файл\n"
                  << "5. Вивести розклад\n"
                  << "6. Пошук за станцією\n"
                  << "0. Вихід\n"
                  << "Виберіть опцію: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: system.addRoute(); break;
            case 2: system.removeRoute(); break;
            case 3: system.loadFromFile(); break;
            case 4: system.saveToFile(); break;
            case 5: system.printSchedule(); break;
            case 6: system.searchByStation(); break;
        }

    } while (choice != 0);

    return 0;
}
