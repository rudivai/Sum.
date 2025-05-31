#pragma once  // Захищає від подвійного включення

#ifndef TASK1_H
#define TASK1_H

#include <string>  // Для std::string

// Заміна частини рядка std::string на новий текст
void string_replace_std(std::string& str, size_t pos, size_t len, const char* s);


// Заміна частини рядка у звичайному char-масиві (без std::string)
void string_replace_custom(char* str, size_t pos, size_t len, const char* s);

#endif