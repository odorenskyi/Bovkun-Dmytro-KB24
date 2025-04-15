#ifndef BOVKUNMODULES_H
#define BOVKUNMODULES_H

#include <string>
#include <fstream>
#include <ctime>
#include <bitset>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace BovkunModules {
    // Основні функції
    void processTask10_1(const std::string& inputFile, const std::string& outputFile);
    void processTask10_2(const std::string& inputFile);
    void processTask10_3(const std::string& outputFile, double x, double y, double z, unsigned int b);

    // Допоміжні функції
    std::string getCurrentDateTime();
    std::string toBinaryString(unsigned int n);
    double s_calculation(double x, double y, double z);
    bool containsWord(const std::string& text, const std::string& word);
    int countParagraphs(const std::string& content);
    int countDots(const std::string& content);
}

#endif // BOVKUNMODULES_H
