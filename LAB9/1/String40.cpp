#include "String40.h"
#include <fstream>  // Для роботи з файлами (ifstream, ofstream)
using namespace std;
// Функція перевіряє, чи рядок має хоча б два пробіли
bool has_spaces(const string& str) {
    // Повертає true, якщо перший і останній пробіли знаходяться в різних місцях
    return str.find(' ') != string::npos && str.rfind(' ') != str.find(' ');
}

// Функція повертає підрядок, який знаходиться між першим і останнім пробілом у рядку
std::string extract_between_spaces(const std::string& str) {
    size_t first = str.find(' ');       // Індекс першого пробілу
    size_t last = str.rfind(' ');       // Індекс останнього пробілу

    // Якщо знайдено два різні пробіли
    if (first != string::npos && last != string::npos && first != last)
        // Повертаємо підрядок між ними
        return str.substr(first + 1, last - first - 1);

    // Якщо пробіл один або взагалі немає — повертаємо порожній рядок
    return "";
}

// Функція читає рядки з вхідного файлу, обробляє кожен рядок і записує результат у вихідний файл
void process_file_lines(const string& inFile, const string& outFile) {
   ifstream fin(inFile);          // Відкриваємо файл для читання
    ofstream fout(outFile);        // Відкриваємо файл для запису
    string line;

    // Зчитуємо файл рядок за рядком
    while (getline(fin, line)) {
        // Якщо в рядку є хоча б два пробіли
        if (has_spaces(line)) {
            // Витягуємо підрядок між пробілами та записуємо у вихідний файл
            fout << extract_between_spaces(line) << '\n';
        }
        else {
            // Якщо недостатньо пробілів — записуємо повідомлення
            fout << "[NO VALID SUBSTRING]" << '\n';
        }
    }

    // Закриваємо файли
    fin.close();
    fout.close();
}