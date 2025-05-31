#include "String40.h"
#include <fstream>  // ��� ������ � ������� (ifstream, ofstream)
using namespace std;
// ������� ��������, �� ����� �� ���� � ��� ������
bool has_spaces(const string& str) {
    // ������� true, ���� ������ � ������� ������ ����������� � ����� �����
    return str.find(' ') != string::npos && str.rfind(' ') != str.find(' ');
}

// ������� ������� �������, ���� ����������� �� ������ � ������� ������� � �����
std::string extract_between_spaces(const std::string& str) {
    size_t first = str.find(' ');       // ������ ������� ������
    size_t last = str.rfind(' ');       // ������ ���������� ������

    // ���� �������� ��� ��� ������
    if (first != string::npos && last != string::npos && first != last)
        // ��������� ������� �� ����
        return str.substr(first + 1, last - first - 1);

    // ���� ����� ���� ��� ������ ���� � ��������� ������� �����
    return "";
}

// ������� ���� ����� � �������� �����, �������� ����� ����� � ������ ��������� � �������� ����
void process_file_lines(const string& inFile, const string& outFile) {
   ifstream fin(inFile);          // ³�������� ���� ��� �������
    ofstream fout(outFile);        // ³�������� ���� ��� ������
    string line;

    // ������� ���� ����� �� ������
    while (getline(fin, line)) {
        // ���� � ����� � ���� � ��� ������
        if (has_spaces(line)) {
            // �������� ������� �� �������� �� �������� � �������� ����
            fout << extract_between_spaces(line) << '\n';
        }
        else {
            // ���� ����������� ������ � �������� �����������
            fout << "[NO VALID SUBSTRING]" << '\n';
        }
    }

    // ��������� �����
    fin.close();
    fout.close();
}