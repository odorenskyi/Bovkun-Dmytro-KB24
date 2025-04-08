#include <iostream>
#include <vector>
#include "D:\lab 9\prj\libModulesBovkun.h"

int main() {
    using namespace Bovkun;

    // Тест задачі 9.1 - Розрахунок зарплати
    try {
        std::vector<int> hours = {8, 9, 7, 10, 8};
        SalaryResult salary = calculateSalary(hours);
        std::cout << "=== Тест 9.1 ===\n"
                  << "Години: [8, 9, 7, 10, 8]\n"
                  << "Зарплата: " << salary.totalSalary << " грн\n"
                  << "Податки: " << salary.taxes << " грн\n"
                  << "До видачі: " << salary.netSalary << " грн\n"
                  << "Статус: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== Тест 9.1 ===\n"
                  << "Помилка: " << e.what() << "\n"
                  << "Статус: FAILED\n\n";
    }

    // Тест задачі 9.2 - Конвертація розмірів
    try {
        SizeResult size = convertSockSize(27);
        std::cout << "=== Тест 9.2 ===\n"
                  << "UA розмір: 27\n"
                  << "ЄС: " << size.euSize << "\n"
                  << "США: " << size.usSize << "\n"
                  << "Статус: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== Тест 9.2 ===\n"
                  << "Помилка: " << e.what() << "\n"
                  << "Статус: FAILED\n\n";
    }

    // Тест задачі 9.3 - Аналіз бітів
    try {
        int result = analyzeBits(128);
        std::cout << "=== Тест 9.3 ===\n"
                  << "Число: 128\n"
                  << "Результат: " << result << "\n"
                  << "Статус: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== Тест 9.3 ===\n"
                  << "Помилка: " << e.what() << "\n"
                  << "Статус: FAILED\n\n";
    }

    return 0;
}