#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include "BovkunModules.h"

using namespace std;

// Допоміжні функції
void createTestFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

string readFileContent(const string& filename) {
    ifstream file(filename);
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

void logTestResult(ofstream& logFile, const string& testName, bool passed,
                  const string& details = "") {
    logFile << "[" << (passed ? "PASS" : "FAIL") << "] " << testName;
    if (!details.empty()) {
        logFile << " | " << details;
    }
    logFile << endl;
}

// Структури для тестових даних
struct TestCase10_1 {
    string name;
    string inputContent;
    int expectedParagraphs;
    bool expectUkraine;
    bool expectUniversity;
    bool expectNotebook;
};

struct TestCase10_2 {
    string name;
    string inputContent;
    int expectedDots;
};

struct TestCase10_3 {
    string name;
    double x, y, z;
    unsigned int b;
    double sMin, sMax;
    string expectedBinary;
};

// Тести для задачі 10.1
void runTask10_1Tests(ofstream& logFile) {
    logFile << "\n=== Тестування задачі 10.1 ===\n";

    vector<TestCase10_1> tests = {
        {"10.1.1 - Один абзац з ключовими словами",
         "Україна має гарні університети. Купіть блокнот.",
         1, true, true, true},
        {"10.1.2 - Два абзаци без ключових слів",
         "Перший абзац.\n\nДругий абзац.",
         2, false, false, false},
        {"10.1.3 - Порожній файл",
         "",
         0, false, false, false},
        {"10.1.4 - Великий текст з різними формами слів",
         "Україною пишаються. Університети найкращі. Блокноти корисні.",
         1, true, true, true},
        {"10.1.5 - Текст зі спецсимволами",
         "Україна! Університет? Блокнот, папір...",
         1, true, true, true},
        {"10.1.6 - Текст з частим входженням слів",
         "Україна Україна університет університет блокнот",
         1, true, true, true},
        {"10.1.7 - Текст з перенесенням слів",
         "Укра-їна має гарні універси-тети",
         1, false, false, false},
        {"10.1.8 - Текст зі словами у різних регістрах",
         "уКрАїНа УнІвЕрСиТеТ бЛоКнОт",
         1, true, true, true},
        {"10.1.9 - Текст з числами та символами",
         "123 Україна 45.6 університет блокнот!",
         1, true, true, true},
        {"10.1.10 - Довгий текст (500+ слів)",
         string(500, 'a') + " Україна " + string(500, 'b'),
         1, true, false, false}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& test = tests[i];
        string inputFile = "test_10.1_" + to_string(i + 1) + "_input.txt";
        string outputFile = "test_10.1_" + to_string(i + 1) + "_output.txt";

        createTestFile(inputFile, test.inputContent);

        try {
            BovkunModules::processTask10_1(inputFile, outputFile);
            string content = readFileContent(outputFile);

            bool paragraphsOK = content.find("Кількість абзаців у тексті: " +
                                          to_string(test.expectedParagraphs)) != string::npos;

            bool ukraineOK = content.find("Україна: " + string(test.expectUkraine ? "так" : "ні")) != string::npos;
            bool universityOK = content.find("Університет: " + string(test.expectUniversity ? "так" : "ні")) != string::npos;
            bool notebookOK = content.find("Блокнот: " + string(test.expectNotebook ? "так" : "ні")) != string::npos;

            bool allPassed = paragraphsOK && ukraineOK && universityOK && notebookOK;

            string details;
            if (!paragraphsOK) details += "Помилка в кількості абзаців; ";
            if (!ukraineOK) details += "Помилка в пошуку 'Україна'; ";
            if (!universityOK) details += "Помилка в пошуку 'університет'; ";
            if (!notebookOK) details += "Помилка в пошуку 'блокнот'; ";

            logTestResult(logFile, test.name, allPassed, details);
        } catch (const exception& e) {
            logTestResult(logFile, test.name, false, "Виняток: " + string(e.what()));
        }
    }
}

// Тести для задачі 10.2
void runTask10_2Tests(ofstream& logFile) {
    logFile << "\n=== Тестування задачі 10.2 ===\n";

    vector<TestCase10_2> tests = {
        {"10.2.1 - Текст з 3 крапками", "Текст. З трьома. Крапками.", 3},
        {"10.2.2 - Текст без крапок", "Текст без крапок", 0},
        {"10.2.3 - Порожній файл", "", 0},
        {"10.2.4 - Текст з багатьма крапками", "Текст... З... багатьма... крапками....", 7},
        {"10.2.5 - Крапки в числах", "Ціна 12.50 грн. Знижка 25.5%", 2},
        {"10.2.6 - Крапки у HTML-тегах", "<p>Текст.</p> <br/> Інший.", 2},
        {"10.2.7 - Крапки у цитатах", "Він сказав: 'Це важливо.' А потім...", 3},
        {"10.2.8 - Крапки після скорочень", "Текст і т.д. та ін.", 2},
        {"10.2.9 - Крапки у різних кодуваннях", "Текст. З крапками. Кирилиця.", 2},
        {"10.2.10 - Великий файл", string(1000, '.') + "текст" + string(1000, '.'), 2000}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& test = tests[i];
        string inputFile = "test_10.2_" + to_string(i + 1) + "_input.txt";
        createTestFile(inputFile, test.inputContent);

        try {
            BovkunModules::processTask10_2(inputFile);
            string content = readFileContent(inputFile);

            size_t pos = content.find("Кількість крапок у тексті: ");
            bool passed = false;
            string details;

            if (pos != string::npos) {
                int actualDots = stoi(content.substr(pos + 27));
                passed = (actualDots == test.expectedDots);
                if (!passed) {
                    details = "Очікувано: " + to_string(test.expectedDots) +
                             ", отримано: " + to_string(actualDots);
                }
            } else {
                details = "Не знайдено інформацію про крапки";
            }

            logTestResult(logFile, test.name, passed, details);
        } catch (const exception& e) {
            logTestResult(logFile, test.name, false, "Виняток: " + string(e.what()));
        }
    }
}

// Тести для задачі 10.3
void runTask10_3Tests(ofstream& logFile) {
    logFile << "\n=== Тестування задачі 10.3 ===\n";

    const double INF = numeric_limits<double>::infinity();
    const double NAN_VAL = numeric_limits<double>::quiet_NaN();

    vector<TestCase10_3> tests = {
        {"10.3.1 - Стандартні значення", 1.5, 2.0, 3.5, 5, 4.35, 4.37, "101"},
        {"10.3.2 - Нульові значення", 0.0, 0.0, 0.0, 0, 0.0, 0.0, "0"},
        {"10.3.3 - Великі числа", 1000, 2000, 3000, 255, 3741.65, 3741.67, "11111111"},
        {"10.3.4 - Негативні числа", -1, -2, -3, 10, 3.74, 3.76, "1010"},
        {"10.3.5 - Дробні числа", 0.1, 0.2, 0.3, 7, 0.37, 0.38, "111"},
        {"10.3.6 - Граничні значення", DBL_MAX, DBL_MAX, DBL_MAX, 1,
         DBL_MAX, INF, "1"},
        {"10.3.7 - Спеціальні значення", NAN_VAL, INF, -INF, 8, -INF, INF, "1000"},
        {"10.3.8 - Велике b (2³²-1)", 1, 1, 1, 4294967295U, 1.73, 1.74,
         "11111111111111111111111111111111"},
        {"10.3.9 - Різні комбінації", 1, 2, 3, 15, 3.74, 3.76, "1111"},
        {"10.3.10 - Випадкові значення", 5.5, 2.2, 3.3, 123, 6.68, 6.70, "1111011"}
    };

    for (size_t i = 0; i < tests.size(); ++i) {
        const auto& test = tests[i];
        string outputFile = "test_10.3_" + to_string(i + 1) + "_output.txt";

        try {
            BovkunModules::processTask10_3(outputFile, test.x, test.y, test.z, test.b);
            string content = readFileContent(outputFile);

            // Перевірка s_calculation
            bool sPassed = false;
            size_t sPos = content.find("s_calculation(");
            if (sPos != string::npos) {
                size_t eqPos = content.find("=", sPos);
                if (eqPos != string::npos) {
                    double sValue = stod(content.substr(eqPos + 1));
                    sPassed = (sValue >= test.sMin && sValue <= test.sMax) ||
                             (isnan(sValue) && isnan(test.sMin));
                }
            }

            // Перевірка двійкового представлення
            bool binaryPassed = content.find(test.expectedBinary) != string::npos;

            string details;
            if (!sPassed) details += "Помилка в s_calculation; ";
            if (!binaryPassed) details += "Помилка в двійковому представленні; ";

            logTestResult(logFile, test.name, sPassed && binaryPassed, details);
        } catch (const exception& e) {
            logTestResult(logFile, test.name, false, "Виняток: " + string(e.what()));
        }
    }
}

int main() {
    ofstream logFile("test_results.log");
    if (!logFile.is_open()) {
        cerr << "Не вдалося відкрити файл для логування результатів!" << endl;
        return 1;
    }

    logFile << "=== Початок тестування ===" << endl;

    runTask10_1Tests(logFile);
    runTask10_2Tests(logFile);
    runTask10_3Tests(logFile);

    logFile << "\n=== Тестування завершено ===" << endl;
    logFile.close();

    cout << "Тестування завершено. Результати збережено у test_results.log" << endl;
    return 0;
}
