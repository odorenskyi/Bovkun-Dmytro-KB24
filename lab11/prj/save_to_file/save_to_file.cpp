#include "save_to_file.h"
#include <iostream>
#include <fstream>

void ScheduleSystem::saveToFile() const {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Не вдалося зберегти файл: " << filename << "\n";
        return;
    }
    for (const auto& r : routes) {
        fout << r.id << ";" << r.route << ";" << r.frequency << ";" << r.period << ";"
            << r.startArrive << ";" << r.startDepart << ";" << r.endDepart << ";" << r.endArrive << "\n";
    }
    fout.close();
    std::cout << "Дані збережено у файл: " << filename << "\n";
}
