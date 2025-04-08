#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <bitset>
#include <map>
#include <cmath>
#include <algorithm>
#include "D:\lab 9\prj\libModulesBovkun.h"
#include <limits> // ��� �������� �����
#include <cstdlib> // ��� system()
#ifdef _WIN32
#include <windows.h> // ��� ��������� ������� �� Windows
#endif

using namespace Bovkun;

// ������� ��� ���������� ��������� �������
void playErrorSound() {
    #ifdef _WIN32
    Beep(1000, 300); // ������ ���� 1000 �� �������� 300 �� �� Windows
    #else
    std::cout << '\a'; // �������� �������� ������ �� ����� ����������
    #endif
}

// ������� ������� ����
void runMenu() {
    char choice;
    bool running = true;

    while (running) {
        std::cout << "\n������ ��:\n"
                  << "'v' - ������ s_calculation()\n"
                  << "'n' - ������ 9.1 (���������� ��������)\n"
                  << "'m' - ������ 9.2 (����������� ������)\n"
                  << "'q' - ������ 9.3 (����� ���)\n"
                  << "'w' ��� 'N' - �����\n"
                  << "��� ����: ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������

        switch (choice) {
            case 'v': {
                double x, z;
                std::cout << "������ x �� z ��� s_calculation: ";
                if (std::cin >> x >> z) {
                    double result = s_calculation(x, z);
                    std::cout << "���������: " << result << std::endl;
                } else {
                    std::cout << "������� ��������!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'n': {
                std::vector<int> hours(5);
                std::cout << "������ ������ �� 5 ��� (����� �����): ";
                for (int i = 0; i < 5; ++i) {
                    std::cin >> hours[i];
                }
                try {
                    SalaryResult result = calculateSalary(hours);
                    std::cout << "��������: " << result.totalSalary << " ���\n"
                              << "�������: " << result.taxes << " ���\n"
                              << "�� ������: " << result.netSalary << " ���" << std::endl;
                } catch (const std::exception& e) {
                    std::cerr << "�������: " << e.what() << std::endl;
                }
                break;
            }
            case 'm': {
                int uaSize;
                std::cout << "������ ���������� �����: ";
                if (std::cin >> uaSize) {
                    try {
                        SizeResult result = convertSockSize(uaSize);
                        std::cout << "��: " << result.euSize << "\n���: " << result.usSize << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "�������: " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "������� ��������!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'q': {
                int number;
                std::cout << "������ ����� (0-7483650): ";
                if (std::cin >> number) {
                    try {
                        int result = analyzeBits(number);
                        std::cout << "���������: " << result << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "�������: " << e.what() << std::endl;
                    }
                } else {
                    std::cout << "������� ��������!" << std::endl;
                    std::cin.clear();
                }
                break;
            }
            case 'w':
            case 'N':
                running = false;
                break;
            default:
                playErrorSound();
                std::cout << "������� ����! ��������� �� ���." << std::endl;
        }

        // �������� ������ ���� ������� ������
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // ��������� ��������� ��� ������ ���� �������
        if (!running) break;

        std::cout << "\n����������? (����-��� ������ - ���, 'w' ��� 'N' - �����): ";
        char cont;
        std::cin >> cont;
        if (cont == 'w' || cont == 'N') {
            running = false;
        }
    }
}

int main() {
    runMenu();
    std::cout << "�������� ���������." << std::endl;
    return 0;
}
