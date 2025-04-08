#include <cmath>
#include "D:\lab 9\prj\libModulesBovkun.h"

namespace Bovkun {

    SalaryResult calculateSalary(const std::vector<int>& hours) {
        SalaryResult result;
        const double rate = 40.0;
        const double bonus = 300.0;

        int totalHours = 0;
        int bonusDays = 0;

        for (int h : hours) {
            totalHours += h;
            if (h > 8) bonusDays++;
        }

        double baseSalary = totalHours * rate;
        double totalBonuses = bonusDays * bonus;
        result.totalAccrued = baseSalary + totalBonuses;

        // Податки
        double taxes = result.totalAccrued * (
            0.15 + // прибуток
            0.02 + // пенсійний
            0.006 + // безробіття
            0.01   // тимчасова втрата працездатності
        );

        result.taxes = taxes;
        result.totalSalary = result.totalAccrued - taxes;

        return result;
    }

    SizeResult convertSockSize(int uaSize) {
        SizeResult result;
        result.uaSize = uaSize;

        if (uaSize == 23) {
            result.euSize = "37/38";
            result.usSize = 8;
        } else if (uaSize == 25) {
            result.euSize = "39/40";
            result.usSize = 8;
        } else if (uaSize == 27) {
            result.euSize = "41/42";
            result.usSize = 9;
        } else if (uaSize == 29) {
            result.euSize = "43/44";
            result.usSize = 11;
        } else if (uaSize == 31) {
            result.euSize = "45/46";
            result.usSize = 12;
        } else {
            result.euSize = "Невідомий";
            result.usSize = -1;
        }

        return result;
    }

    int analyzeBits(int number) {
        bool d7 = (number >> 7) & 1; // D7 — восьмий біт з кінця
        int count = 0;

        while (number > 0) {
            if (d7) {
                if ((number & 1) == 0) count++; // нулі
            } else {
                if ((number & 1) == 1) count++; // одиниці
            }
            number >>= 1;
        }

        return count;
    }

}
