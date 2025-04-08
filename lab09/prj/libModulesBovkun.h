#ifndef LIBMODULESBOVKUN_H
#define LIBMODULESBOVKUN_H

#include <vector>
#include <stdexcept>
#include <map>

namespace Bovkun {
    // ������ 9.1: ��������� ��� ���������� ���������� ��������
    struct SalaryResult {
        double totalSalary;
        double taxes;
        double netSalary;
    };
    SalaryResult calculateSalary(const std::vector<int>& hours);

    // ������ 9.2: ��������� ��� ������ ���������
    struct SizeResult {
        std::string euSize;
        int usSize;
    };
    SizeResult convertSockSize(int uaSize);

    // ������ 9.3: ������� ������ ���
    int analyzeBits(int n);

    // ���� ������� (��� ����������)
    double s_calculation(double x, double z);
}

#endif // LIBMODULESBOVKUN_H
