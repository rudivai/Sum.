#include "String_replace.h"
#include <cstring> // Для strlen
using namespace std;
// Заміна частини рядка за допомогою стандартного методу std::string::replace
void string_replace_std(string& str, size_t pos, size_t len, const char* s) {
    str.replace(pos, len, s); // Просто викликаємо метод replace
}

// Власна реалізація заміни частини рядка у char-масиві без string
void string_replace_custom(char* str, size_t pos, size_t len, const char* s) {
    size_t orig_len = strlen(str);   // Поточна довжина вхідного рядка
    size_t rep_len = strlen(s);      // Довжина рядка, який вставляємо

    if (pos > orig_len) return;      // Якщо позиція більша за довжину — нічого не робимо

    // Якщо новий фрагмент довший — зсуваємо символи правіше
    if (rep_len > len) {
        for (int i = (int)orig_len; i >= (int)(pos + len); --i) {
            str[i + rep_len - len] = str[i]; // Зсув символів вправо
        }
    }
    // Якщо новий фрагмент коротший — стискаємо рядок
    else if (rep_len < len) {
        for (int i = (int)(pos + len); i <= (int)orig_len; ++i) {
            str[i + rep_len - len] = str[i]; // Зсув символів вліво
        }
    }

    // Копіюємо нові символи на місце заміни
    for (size_t i = 0; i < rep_len; ++i) {
        str[pos + i] = s[i];
    }

    // Символ '\0' автоматично переміщено при зсуві, тож рядок залишається коректним
}