#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <bitset>
#include <map>
#include <cmath>
#include <algorithm>
#include "D:\lab 9\prj\libModulesBovkun.h"
#include <limits> // Для очищення вводу
#include <cstdlib> // Для system()
#ifdef _WIN32
#include <windows.h> // Для звукового сигналу на Windows
#endif

using namespace Bovkun;

// Функція для відтворення звукового сигналу
void playErrorSound() {
    #ifdef _WIN32
    Beep(1000, 300); // Генерує звук 1000 Гц протягом 300 мс на Windows
    #else
    std::cout << '\a'; // Виводить звуковий сигнал на інших платформах
    #endif
}

// Головна функція меню
void runMenu() {
    char choice;
    bool running = true;

    while (running) {
        std::cout << "\nОберіть дію:\n"
                  << "'v' - Виклик s_calculation()\n"
                  << "'n' - Задача 9.1 (Розрахунок зарплати)\n"
                  << "'m' - Задача 9.2 (Конвертація розмірів)\n"
                  << "'q' - Задача 9.3 (Аналіз бітів)\n"
                  << "'w' або 'N' - Вихід\n"
                  << "Ваш вибір: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищення буфера

        switch (choice) {
            case 'v': {
                double x, z;
                std::cout << "Введіть x та z для s_calculation: ";
                if (std::cin >> x >> z) {
                    double result = s_calculation(x, z);
                    std::cout << "Результат: " << result << std::endl;
                } else {
                    std::cout << "Помилка введення!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'n': {
                std::vector<int> hours(5);
                std::cout << "Введіть години за 5 днів (через пробіл): ";
                for (int i = 0; i < 5; ++i) {
                    std::cin >> hours[i];
                }
                try {
                    SalaryResult result = calculateSalary(hours);
                    std::cout << "Зарплата: " << result.totalSalary << " грн\n"
                              << "Податки: " << result.taxes << " грн\n"
                              << "До видачі: " << result.netSalary << " грн" << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "Помилка: " << e.what() << std::endl;
                }
                break;
            }
            case 'm': {
                int uaSize;
                std::cout << "Введіть український розмір: ";
                if (std::cin >> uaSize) {
                    try {
                        SizeResult result = convertSockSize(uaSize);
                        std::cout << "ЄС: " << result.euSize << "\nСША: " << result.usSize << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "Помилка введення!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'q': {
                int number;
                std::cout << "Введіть число (0-7483650): ";
                if (std::cin >> number) {
                    try {
                        int result = analyzeBits(number);
                        std::cout << "Результат: " << result << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "Помилка: " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "Помилка введення!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'w':
            case 'N':
                running = false;
                break;
            default:
                playErrorSound();
                std::cout << "Невірний вибір! Спробуйте ще раз." << std::endl;
        }

        // Очищення буфера після кожного вибору
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Додаткове запитання для виходу після помилки
        if (!running) break;

        std::cout << "\nПродовжити? (Будь-яка клавіша - так, 'w' або 'N' - вихід): ";
        char cont;
        std::cin >> cont;
        if (cont == 'w' || cont == 'N') {
            running = false;
        }
    }
}

int main() {
    runMenu();
    std::cout << "Програма завершена." << std::endl;
    return 0;
}
