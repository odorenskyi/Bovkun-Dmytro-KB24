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
        cout << "����: x=" << test.x << ", z=" << test.z << endl;
        try {
            double result = Bovkun::s_calculation(test.x, test.z);
            bool isPassed = abs(result - test.expected) < 0.001;
            cout << "���������: " << result << " | ���������: " << test.expected
                 << " | ������: " << (isPassed ? "Passed" : "Failed") << endl;
        } catch (const exception& e) {
            cerr << "�������: " << e.what() << " | ������: Failed" << endl;
        }
        cout << "---------------------" << endl;
    }
}

int main() {
    vector<TestCase> tests = {
        {1.0, 2.0, 25.467},   // ������� ����-�����
        {0.5, 3.0, 42.891},   // ������� ��� ��������
        {-2.0, 1.0, 0.0}       // ���� �� �������
    };

    runTests(tests);
    return 0;
}
