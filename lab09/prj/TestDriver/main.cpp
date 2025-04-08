#include <iostream>
#include <vector>
#include <string>
#include "ModulesBovkun.h"

using namespace std;
using namespace Bovkun;

void testSalaryCalculation() {
    cout << "=== Тестування задачі 9.1 ===" << endl;

    vector<int> hours1 = {8, 8, 8, 8, 8}; // без премій
    vector<int> hours2 = {9, 9, 9, 9, 9}; // з преміями
    vector<int> hours3 = {8, 10, 7, 9, 8}; // мікс

    struct {
        vector<int> input;
        double expectedTotalSalary;
    } tests[] = {
        {hours1, 1600 - (1600 * 0.186)}, // базова
        {hours2, (1800 + 5 * 300) - ((1800 + 1500) * 0.186)}, // премії
        {hours3, (1700 + 2 * 300) - ((1700 + 600) * 0.186)} // мікс
    };

    for (int i = 0; i < 3; ++i) {
        auto res = calculateSalary(tests[i].input);
        cout << "Тест " << i+1 << ": години = ";
        for (int h : tests[i].input) cout << h << " ";
        cout << "\nОчікувано: " << tests[i].expectedTotalSalary
             << ", Отримано: " << res.totalSalary;
        cout << (abs(res.totalSalary - tests[i].expectedTotalSalary) < 0.1 ? " ✅ PASSED\n" : " ❌ FAILED\n");
    }
}

void testSockSizeConversion() {
    cout << "\n=== Тестування задачі 9.2 ===" << endl;

    struct {
        int uaSize;
        string expectedEU;
        int expectedUS;
    } tests[] = {
        {23, "37/38", 8},
        {27, "41/42", 9},
        {29, "43/44", 11}
    };

    for (int i = 0; i < 3; ++i) {
        auto res = convertSockSize(tests[i].uaSize);
        cout << "Тест " << i+1 << ": Вхід: " << tests[i].uaSize
             << " | Очікувано: " << tests[i].expectedEU << ", " << tests[i].expectedUS
             << " | Отримано: " << res.euSize << ", " << res.usSize;
        cout << ((res.euSize == tests[i].expectedEU && res.usSize == tests[i].expectedUS) ? " ✅ PASSED\n" : " ❌ FAILED\n");
    }
}

void testBitAnalysis() {
    cout << "\n=== Тестування задачі 9.3 ===" << endl;

    struct {
        int number;
        int expected;
    } tests[] = {
        {128, 7}, // D7 == 1, 01111111 — 7 нулів
        {130, 6}, // D7 == 1, 10000010 — 6 нулів
        {65, 2}   // D7 == 0, 1000001 — 2 одиниці
    };

    for (int i = 0; i < 3; ++i) {
        int result = analyzeBits(tests[i].number);
        cout << "Тест " << i+1 << ": Вхід: " << tests[i].number
             << " | Очікувано: " << tests[i].expected
             << " | Отримано: " << result;
        cout << (result == tests[i].expected ? " ✅ PASSED\n" : " ❌ FAILED\n");
    }
}

int main() {
    testSalaryCalculation();
    testSockSizeConversion();
    testBitAnalysis();
    return 0;
}
