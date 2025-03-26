#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "libModulesBovkun.h"

using namespace std;

// 8.2.1: Виведення інформації про розробника
void SW_Developer() {
    cout << "Bovkun Dmutro ©, projectpat6542@gmail.com" << endl;
    cout << "Бовкун Дмитро ©, projectpat6542@gmail.com" << endl;
}

// 8.2.2: Перевірка логічного виразу
bool check_expression(char a, char b) {
    return (a + 7) < abs(b - 5);
}

// 8.2.3: Виведення значень x, y, z та обчислення S
void calculate(double x, double y, double z) {
    cout << "x: " << fixed << setprecision(2) << x << " | hex: 0x" << hex << (int)x << endl;
    cout << "y: " << fixed << setprecision(2) << y << " | hex: 0x" << hex << (int)y << endl;
    cout << "z: " << fixed << setprecision(2) << z << " | hex: 0x" << hex << (int)z << endl;
}

double s_calculation(double x, double z) {
    if (x <= -1) {
        throw invalid_argument("x має бути більше -1");
    }
    if (x == 0) {
        throw invalid_argument("x не може дорівнювати 0");
    }

    double numerator = sqrt(1 + x) - 3 * cos(x);
    double denominator = log(x * x) + 3 * sin(M_PI * x);

    if (denominator == 0) {
        throw runtime_error("Ділення на нуль");
    }

    double secondTerm = pow(sqrt(z * z * z) + 2, 2);
    return (numerator / denominator) + secondTerm;
}

int main() {
    // 8.2.1: Виведення інформації про розробника
    SW_Developer();

    // 8.2.2: Перевірка логічного виразу
    char a, b;
    cout << "Введіть символи a та b: ";
    cin >> a >> b;
    cout << "Результат логічного виразу: " << boolalpha << check_expression(a, b) << endl;

    // 8.2.3: Виведення значень x, y, z та обчислення S
    double x, y, z;
    cout << "Введіть значення x, y, z: ";
    cin >> x >> y >> z;

    calculate(x, y, z);

    try {
        double S = s_calculation(x, z);
        cout << "S = " << S << endl;
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
