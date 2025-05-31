#pragma once  // Захист від повторного включення файлу (альтернатива #ifndef)

// Початок класичного захисту від багаторазового включення
#ifndef TASK2_H
#define TASK2_H

#include <string>  // Підключення бібліотеки для роботи з типом std::string
using namespace std;
// --- Перевірка наявності хоча б двох пробілів у рядку ---
// Повертає true, якщо у рядку є мінімум два пробіли
bool has_spaces(const std::string& str);

// --- Повертає підрядок між першим і останнім пробілом у рядку ---
// Якщо пробіл лише один або жодного — повертає порожній рядок
string extract_between_spaces(const std::string& str);

// --- Обробляє текстовий файл пострічково ---
// Зчитує з файлу `inFile`, для кожного рядка викликає extract_between_spaces()
// Результати записує у файл `outFile`
void process_file_lines(const std::string& inFile, const std::string& outFile);

// Кінець класичного захисту
#endif