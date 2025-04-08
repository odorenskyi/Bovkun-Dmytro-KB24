#include "D:\lab 9\prj\libModulesBovkun.h"

namespace Bovkun {

// ======= ЗАДАЧА 9.1 =======

SalaryResult calculateSalary(const std::vector<int>& hours) {
    const int baseRate = 40;
    const int bonusPerDay = 300;
    const int regularHoursPerDay = 8;

    double totalBase = 0;
    double totalBonus = 0;

    for (int dayHours : hours) {
        totalBase += dayHours * baseRate;
        if (dayHours > regularHoursPerDay) {
            totalBonus += bonusPerDay;
        }
    }

    double totalGross = totalBase + totalBonus;

    // Податки
    double taxIncome = 0.15 * totalGross;
    double taxPension = 0.02 * totalGross;
    double taxUnemployment = 0.006 * totalGross;
    double taxDisability = 0.01 * totalGross;

    double totalTax = taxIncome + taxPension + taxUnemployment + taxDisability;
    double totalNet = totalGross - totalTax;

    return SalaryResult{
        totalGross,
        taxIncome,
        taxPension,
        taxUnemployment,
        taxDisability,
        totalNet
    };
}

// ======= ЗАДАЧА 9.2 =======

SizeResult convertSockSize(int uaSize) {
    SizeResult result = {-1, -1}; // за замовчуванням - невірне значення

    switch (uaSize) {
        case 23: result.euSize = 37; result.usSize = 8; break;
        case 25: result.euSize = 39; result.usSize = 9; break;
        case 27: result.euSize = 41; result.usSize = 10; break;
        case 29: result.euSize = 43; result.usSize = 11; break;
        case 31: result.euSize = 45; result.usSize = 12; break;
    }

    return result;
}

// ======= ЗАДАЧА 9.3 =======

int analyzeBits(int N) {
    int count = 0;
    if ((N >> 7) & 1) { // якщо 7-й біт == 1
        for (int i = 0; i < 8; ++i) {
            if (((N >> i) & 1) == 0) ++count; // рахуємо нулі
        }
    } else {
        for (int i = 0; i < 8; ++i) {
            if ((N >> i) & 1) ++count; // рахуємо одиниці
        }
    }
    return count;
}

} // namespace Bovkun
