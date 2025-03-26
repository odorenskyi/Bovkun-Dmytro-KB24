#include "libModulesBovkun.h"
#include <cmath>
#include <stdexcept>

namespace Bovkun {
    double s_calculation(double x, double z) {
        if (x <= -1) {
            throw std::invalid_argument("x �� ���� ����� -1");
        }
        if (x == 0) {
            throw std::invalid_argument("x �� ���� ���� 0");
        }

        double numerator = sqrt(1 + x) - 3 * cos(x);
        double denominator = log(x * x) + 3 * sin(M_PI * x);

        if (denominator == 0) {
            throw std::runtime_error("ĳ����� �� ����");
        }

        double term2 = pow(sqrt(z * z * z) + 2, 2);
        return (numerator / denominator) + term2;
    }
}
