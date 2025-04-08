#include <iostream>
#include <vector>
#include "D:\lab 9\prj\libModulesBovkun.h"

int main() {
    using namespace Bovkun;

    // ���� ������ 9.1 - ���������� ��������
    try {
        std::vector<int> hours = {8, 9, 7, 10, 8};
        SalaryResult salary = calculateSalary(hours);
        std::cout << "=== ���� 9.1 ===\n"
                  << "������: [8, 9, 7, 10, 8]\n"
                  << "��������: " << salary.totalSalary << " ���\n"
                  << "�������: " << salary.taxes << " ���\n"
                  << "�� ������: " << salary.netSalary << " ���\n"
                  << "������: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== ���� 9.1 ===\n"
                  << "�������: " << e.what() << "\n"
                  << "������: FAILED\n\n";
    }

    // ���� ������ 9.2 - ����������� ������
    try {
        SizeResult size = convertSockSize(27);
        std::cout << "=== ���� 9.2 ===\n"
                  << "UA �����: 27\n"
                  << "��: " << size.euSize << "\n"
                  << "���: " << size.usSize << "\n"
                  << "������: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== ���� 9.2 ===\n"
                  << "�������: " << e.what() << "\n"
                  << "������: FAILED\n\n";
    }

    // ���� ������ 9.3 - ����� ���
    try {
        int result = analyzeBits(128);
        std::cout << "=== ���� 9.3 ===\n"
                  << "�����: 128\n"
                  << "���������: " << result << "\n"
                  << "������: PASSED\n\n";
    } catch (const std::exception& e) {
        std::cout << "=== ���� 9.3 ===\n"
                  << "�������: " << e.what() << "\n"
                  << "������: FAILED\n\n";
    }

    return 0;
}