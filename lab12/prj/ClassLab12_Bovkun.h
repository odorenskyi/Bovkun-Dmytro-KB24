#ifndef CLASS_LAB12_BOVKUN_H
#define CLASS_LAB12_BOVKUN_H

#include <stdexcept>

class ClassLab12_Bovkun {
private:
    double sideA;
    double sideB;
    bool validateSide(double value);

public:
    ClassLab12_Bovkun(double a = 1.0, double b = 1.0);
    double getSideA() const;
    double getSideB() const;
    void setSideA(double value, bool skipValidation = false);
    void setSideB(double value, bool skipValidation = false);
    double calculateArea() const;
};

#endif // CLASS_LAB12_BOVKUN_H