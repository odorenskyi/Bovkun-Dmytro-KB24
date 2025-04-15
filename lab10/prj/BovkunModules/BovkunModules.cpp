#include "BovkunModules.h"
#include <fstream>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <vector>
#include <locale>
#include <clocale>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

namespace BovkunModules {
    const string AUTHOR_INFO = "Розробник: Дмитро Бовкун\n"
                             "Установа: ЦНТУ\n"
                             "Місто: Кропивницький\n"
                             "Країна: Україна\n"
                             "Рік розробки: 2025\n";

    void initUkrainianLocale() {
        #ifdef _WIN32
        SetConsoleOutputCP(1251);
        SetConsoleCP(1251);
        #endif
        setlocale(LC_ALL, "Ukrainian");
    }

    string getCurrentDateTime() {
        time_t now = time(nullptr);
        char buf[80];
        strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", localtime(&now));
        return buf;
    }

    string toBinaryString(unsigned int n) {
        if (n == 0) return "0";
        string binary;
        while (n > 0) {
            binary = (n % 2 ? "1" : "0") + binary;
            n /= 2;
        }
        return binary;
    }

    double s_calculation(double x, double y, double z) {
        if (isnan(x)) x = 0;
        if (isnan(y)) y = 0;
        if (isnan(z)) z = 0;
        return sqrt(x*x + y*y + z*z) + sin(x*y) + cos(y*z);
    }

    bool containsWord(const string& text, const string& word) {
        if (word.empty() || text.empty()) return false;

        vector<string> wordForms;
        string lowerWord = word;
        transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);
        wordForms.push_back(lowerWord);

        // Додаткові форми для українських слів
        if (lowerWord == "україна") {
            wordForms.push_back("україни");
            wordForms.push_back("україні");
            wordForms.push_back("україною");
        } else if (lowerWord == "університет") {
            wordForms.push_back("університету");
            wordForms.push_back("університети");
            wordForms.push_back("університетів");
        } else if (lowerWord == "блокнот") {
            wordForms.push_back("блокнота");
            wordForms.push_back("блокноти");
            wordForms.push_back("блокнотом");
        }

        string lowerText = text;
        transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);

        for (const auto& form : wordForms) {
            size_t pos = lowerText.find(form);
            while (pos != string::npos) {
                bool leftBoundary = (pos == 0) || !isalpha(lowerText[pos-1]);
                bool rightBoundary = (pos + form.length() >= lowerText.length()) ||
                                   !isalpha(lowerText[pos + form.length()]);

                if (leftBoundary && rightBoundary) {
                    return true;
                }
                pos = lowerText.find(form, pos + 1);
            }
        }
        return false;
    }

    int countParagraphs(const string& content) {
        if (content.empty()) return 0;

        int count = 0;
        bool inParagraph = false;

        for (size_t i = 0; i < content.length(); ++i) {
            if (content[i] == '\n') {
                if (i + 1 < content.length() && content[i+1] == '\n') {
                    if (inParagraph) {
                        count++;
                        inParagraph = false;
                    }
                }
            } else if (!isspace(content[i])) {
                inParagraph = true;
            }
        }

        if (inParagraph) count++;

        return max(1, count);
    }

    int countDots(const string& content) {
        return count(content.begin(), content.end(), '.');
    }

    void processTask10_1(const string& inputFile, const string& outputFile) {
        ifstream in(inputFile);
        if (!in.is_open()) throw runtime_error("Не вдалося відкрити вхідний файл");

        string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        in.close();

        ofstream out(outputFile);
        if (!out.is_open()) throw runtime_error("Не вдалося відкрити вихідний файл");

        out << AUTHOR_INFO << "\n";
        out << "Кількість абзаців у тексті: " << countParagraphs(content) << "\n";

        out << "Результати пошуку слів:\n"
            << "- Україна: " << (containsWord(content, "Україна") ? "так" : "ні") << "\n"
            << "- Університет: " << (containsWord(content, "університет") ? "так" : "ні") << "\n"
            << "- Блокнот: " << (containsWord(content, "блокнот") ? "так" : "ні") << "\n";

        out.close();
    }

    void processTask10_2(const string& inputFile) {
        fstream file(inputFile, ios::in | ios::out | ios::app);
        if (!file.is_open()) throw runtime_error("Не вдалося відкрити файл");

        file.seekg(0);
        string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

        file << "\n\nКількість крапок у тексті: " << countDots(content)
             << "\nДата та час дозапису: " << getCurrentDateTime();

        file.close();
    }

    void processTask10_3(const string& outputFile, double x, double y, double z, unsigned int b) {
        ofstream out(outputFile);
        if (!out.is_open()) throw runtime_error("Не вдалося відкрити вихідний файл");

        out << fixed << setprecision(2);
        out << "Результати обчислень:\n"
            << "s_calculation(" << x << ", " << y << ", " << z << ") = "
            << s_calculation(x, y, z) << "\n"
            << "Число " << b << " у двійковому коді: " << toBinaryString(b) << "\n";

        out.close();
    }
}
