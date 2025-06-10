#include "libModulesBovkun.h"
#include <stdexcept>

// Конструктор
ClassLab12_Bovkun::ClassLab12_Bovkun(double w, double h) {{
    if (w <= 0 || h <= 0) throw std::invalid_argument("Width and height must be positive");
    width = w;
    height = h;
}}

// Гетери
double ClassLab12_Bovkun::getWidth() const {{
    return width;
}}

double ClassLab12_Bovkun::getHeight() const {{
    return height;
}}

// Сетери
void ClassLab12_Bovkun::setWidth(double w) {{
    if (w <= 0) throw std::invalid_argument("Width must be positive");
    width = w;
}}

void ClassLab12_Bovkun::setHeight(double h) {{
    if (h <= 0) throw std::invalid_argument("Height must be positive");
    height = h;
}}

// Обчислення площі
double ClassLab12_Bovkun::calculateArea() const {{
    return width * height;
}}