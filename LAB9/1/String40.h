#pragma once  // ������ �� ���������� ��������� ����� (������������ #ifndef)

// ������� ���������� ������� �� �������������� ���������
#ifndef TASK2_H
#define TASK2_H

#include <string>  // ϳ��������� �������� ��� ������ � ����� std::string
using namespace std;
// --- �������� �������� ���� � ���� ������ � ����� ---
// ������� true, ���� � ����� � ����� ��� ������
bool has_spaces(const std::string& str);

// --- ������� ������� �� ������ � ������� ������� � ����� ---
// ���� ����� ���� ���� ��� ������� � ������� ������� �����
string extract_between_spaces(const std::string& str);

// --- �������� ��������� ���� ���������� ---
// ����� � ����� `inFile`, ��� ������� ����� ������� extract_between_spaces()
// ���������� ������ � ���� `outFile`
void process_file_lines(const std::string& inFile, const std::string& outFile);

// ʳ���� ���������� �������
#endif