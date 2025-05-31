#include <iostream>
#include "Begin18.h"
using namespace std;

/// ��������, �� ����� ����������� � 2-� ��� 3-� ����������� �����.
/// II ������: x < 0, y > 0
/// III ������: x < 0, y < 0
/// �� ����� � x < 0, y ? 0 � ������������� ����.
void CheckQuadrant(Point& p) {
    p.isInSecondOrThird = (p.x < 0 && (p.y != 0));
}

/// ������� ������� ���������� �����, �������� �� ���������
/// � �������� True/False �������� �� ����� ������.
void RunPointTest() {
    Point p;

    cout << "\nEnter x coordinate: ";
    cin >> p.x;

    cout << "Enter y coordinate: ";
    cin >> p.y;

    // �������� ����������� �����
    CheckQuadrant(p);

    // ���� ����������
    cout << "Point belongs to the II or III quadrant: "
        << (p.isInSecondOrThird ? "True (True)" : "False (False)") << endl;
}