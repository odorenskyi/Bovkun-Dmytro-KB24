#include <iostream>
#include <vector>
#include "libModulesBovkun.h"

using namespace std;

struct TestCase {
    double x;
    double z;
    double expected;
};

void runTests(const vector<TestCase>& tests) {
    for (const auto& test : tests) {
        cout << "Тест: x=" << test.x << ", z=" << test.z << endl;
        try {
            double result = Bovkun::s_calculation(test.x, test.z);
            bool isPassed = abs(result - test.expected) < 0.001;
            cout << "Результат: " << result << " | Очікувано: " << test.expected
                 << " | Статус: " << (isPassed ? "Passed" : "Failed") << endl;
        } catch (const exception& e) {
            cerr << "Помилка: " << e.what() << " | Статус: Failed" << endl;
        }
        cout << "---------------------" << endl;
    }
}

int main() {
    vector<TestCase> tests = {
        {1.0, 2.0, 25.467},   // Приклад тест-кейсу
        {0.5, 3.0, 42.891},   // Додайте свої значення
        {-2.0, 1.0, 0.0}       // Тест на виняток
    };

    runTests(tests);
    return 0;
}
