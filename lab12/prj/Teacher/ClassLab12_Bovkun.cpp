#include "ClassLab12_Bovkun.h"

bool ClassLab12_Bovkun::validateSide(double value) {
    return value > 0;
}

ClassLab12_Bovkun::ClassLab12_Bovkun(double a, double b) {
    if (!validateSide(a)) throw std::invalid_argument("Side A must be positive");
    if (!validateSide(b)) throw std::invalid_argument("Side B must be positive");
    sideA = a;
    sideB = b;
}

double ClassLab12_Bovkun::getSideA() const {
    return sideA;
}

double ClassLab12_Bovkun::getSideB() const {
    return sideB;
}

void ClassLab12_Bovkun::setSideA(double value, bool skipValidation) {
    if (!skipValidation && !validateSide(value)) {
        throw std::invalid_argument("Side A must be positive");
    }
    sideA = value;
}

void ClassLab12_Bovkun::setSideB(double value, bool skipValidation) {
    if (!skipValidation && !validateSide(value)) {
        throw std::invalid_argument("Side B must be positive");
    }
    sideB = value;
}

double ClassLab12_Bovkun::calculateArea() const {
    return sideA * sideB;
}