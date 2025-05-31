#pragma once  // ������ �� ��������� ���������

#ifndef TASK1_H
#define TASK1_H

#include <string>  // ��� std::string

// ����� ������� ����� std::string �� ����� �����
void string_replace_std(std::string& str, size_t pos, size_t len, const char* s);


// ����� ������� ����� � ���������� char-����� (��� std::string)
void string_replace_custom(char* str, size_t pos, size_t len, const char* s);

#endif