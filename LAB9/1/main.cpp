#include <iostream>      // Для вводу/виводу в консоль
#include <string>        // Для використання std::string
#include <cstring>       // Для роботи з C-рядками (strcpy_s)
#include "String_replace.h"  // Заголовок з функціями заміни рядків
#include "String40.h"        // Заголовок з функціями обробки рядків з пробілами

using namespace std;

// Завдання 1: Заміна підрядка у рядку
void run_task1() {
    string str1;  // Вхідний рядок від користувача
    cout << "Enter string: ";
    getline(cin, str1);  // Зчитуємо повністю весь рядок (з пробілами)

    char str2[1024];  // Статичний C-style рядок
    strcpy_s(str2, str1.c_str());  // Копіюємо string у char-масив

    size_t pos, len;  // Початкова позиція та довжина підрядка для заміни
    string replacement;  // Рядок, яким замінюємо

    // Введення позиції з перевіркою
    cout << "Enter position to replace: ";
    while (!(cin >> pos)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        string dummy;
        getline(cin, dummy);
    }

    // Введення довжини
    cout << "Enter length to replace: ";
    while (!(cin >> len)) {
        cout << "Invalid input. Enter a number: ";
        cin.clear();
        string dummy;
        getline(cin, dummy);
    }

    cin.ignore();  // Очищення буфера після cin

    // Введення тексту заміни
    cout << "Enter replacement text: ";
    getline(cin, replacement);

    // Заміна в std::string
    string str1_copy = str1;
    string_replace_std(str1_copy, pos, len, replacement.c_str());
    cout << "Result using std::string::replace: " << str1_copy << "\n";

    // Заміна в C-style рядку
    string_replace_custom(str2, pos, len, replacement.c_str());
    cout << "Result using custom replace: " << str2 << "\n";
}

// Завдання 2: Витяг підрядка між першим і останнім пробілом + запис у файл
void run_task2() {
    string str;
    cout << "Enter string with spaces: ";
    getline(cin, str);

    // Виведення підрядка між пробілами або повідомлення про помилку
    if (has_spaces(str)) {
        cout << "Substring between first and last space: "
            << extract_between_spaces(str) << "\n";
    }
    else {
        cout << "Not enough spaces to extract substring.\n";
    }

    // Обробка рядків з файлу input.txt і запис результату у output.txt
    process_file_lines("input.txt", "output.txt");
    cout << "File processed. Check output.txt.\n";
}

// Головне меню програми
int main() {
    int choice;

    do {
        cout << "\nMenu:\n"
            << "1. Task 1 - Replace substring\n"
            << "2. Task 2 - Substring between spaces\n"
            << "0. Exit\n"
            << "Your choice: ";
        cin >> choice;
        cin.ignore();  // Очистка буфера після вводу числа

        switch (choice) {
        case 1:
            run_task1();
            break;
        case 2:
            run_task2();
            break;
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}