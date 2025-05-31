#include "String_replace.h"
#include <cstring> // ��� strlen
using namespace std;
// ����� ������� ����� �� ��������� ������������ ������ std::string::replace
void string_replace_std(string& str, size_t pos, size_t len, const char* s) {
    str.replace(pos, len, s); // ������ ��������� ����� replace
}

// ������ ��������� ����� ������� ����� � char-����� ��� string
void string_replace_custom(char* str, size_t pos, size_t len, const char* s) {
    size_t orig_len = strlen(str);   // ������� ������� �������� �����
    size_t rep_len = strlen(s);      // ������� �����, ���� ����������

    if (pos > orig_len) return;      // ���� ������� ����� �� ������� � ����� �� ������

    // ���� ����� �������� ������ � ������� ������� ������
    if (rep_len > len) {
        for (int i = (int)orig_len; i >= (int)(pos + len); --i) {
            str[i + rep_len - len] = str[i]; // ���� ������� ������
        }
    }
    // ���� ����� �������� �������� � �������� �����
    else if (rep_len < len) {
        for (int i = (int)(pos + len); i <= (int)orig_len; ++i) {
            str[i + rep_len - len] = str[i]; // ���� ������� ����
        }
    }

    // ������� ��� ������� �� ���� �����
    for (size_t i = 0; i < rep_len; ++i) {
        str[pos + i] = s[i];
    }

    // ������ '\0' ����������� ��������� ��� ����, ��� ����� ���������� ���������
}