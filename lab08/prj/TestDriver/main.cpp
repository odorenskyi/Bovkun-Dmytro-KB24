#include <iostream>
#include <clocale>
#include "libModulesBovkun.h" // ϳ��������� ������������� �����

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Bovkun Dmutro, projectpat6542@gmail.com " << endl;
    cout << " ������ ������, projectpat6542@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

    double x, z;
    cout << "������ x �� z: ";
    cin >> x >> z;

    try {
        double S = Bovkun::s_calculation(x, z); // ������ ������� � �������� ����
        cout << "S = " << S << endl;
    } catch (const exception& e) {
        cerr << "�������: " << e.what() << endl;
    }

    return 0;
}
