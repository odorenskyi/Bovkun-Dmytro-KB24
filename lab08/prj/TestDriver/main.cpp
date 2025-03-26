#include <iostream>
#include <clocale>
#include "libModulesBovkun.h" // Підключення заголовочного файлу

using namespace std;

int main() {
    setlocale(LC_ALL, "ukr");
    cout << "=========================================" << endl;
    cout << " Bovkun Dmutro, projectpat6542@gmail.com " << endl;
    cout << " Бовкун Дмитро, projectpat6542@gmail.com  " << endl;
    cout << "==========(c)All Rights Reserved=========" << endl;

    double x, z;
    cout << "Введіть x та z: ";
    cin >> x >> z;

    try {
        double S = Bovkun::s_calculation(x, z); // Виклик функції з простору імен
        cout << "S = " << S << endl;
    } catch (const exception& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
