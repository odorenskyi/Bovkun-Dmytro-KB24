#ifndef LIBMODULESBOVKUN_H
#define LIBMODULESBOVKUN_H

#include <vector>
#include <stdexcept>
#include <map>

namespace Bovkun {
    // Задача 9.1: Структура для результатів розрахунку зарплати
    struct SalaryResult {
        double totalSalary;
        double taxes;
        double netSalary;
    };
    SalaryResult calculateSalary(const std::vector<int>& hours);

    // Задача 9.2: Структура для розмірів шкарпеток
    struct SizeResult {
        std::string euSize;
        int usSize;
    };
    SizeResult convertSockSize(int uaSize);

    // Задача 9.3: Функція аналізу бітів
    int analyzeBits(int n);

    // Інша функція (вже реалізована)
    double s_calculation(double x, double z);
}

#endif // LIBMODULESBOVKUN_H
