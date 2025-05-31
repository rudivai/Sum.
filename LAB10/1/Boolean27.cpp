#include <iostream>
#include <cmath>
#include "Boolean27.h"
using namespace std;

/// ���������� ������� ������ ������ AC � BC.
/// �������: |C - A| * |C - B|
/// ����: ��������� SegmentPoints � ������������ A, B, C.
/// ��������� ���������� � ��� product.
void CalculateSegmentProduct(SegmentPoints& sp) {
    sp.product = abs(sp.C - sp.A) * abs(sp.C - sp.B);
}

/// �������, ��� ������ ����������� ������ ����� A, B, C.
/// ��������, �� C �� A � B, �� �� ������ � �� ������ �������� �����������.
/// ���� ����������� ���������� � ���������� ���������.
void RunSegmentTest() {
    SegmentPoints sp;

    cout << "\nEnter the coordinate of point A: ";
    cin >> sp.A;

    cout << "Enter the coordinate of point B: ";
    cin >> sp.B;

    cout << "Enter the coordinate of point C (between A and B): ";
    cin >> sp.C;

    // Calculating the product of segment lengths
    CalculateSegmentProduct(sp);

    // Outputting the result
    cout << "Product of segment lengths AC and BC = " << sp.product << endl;
}