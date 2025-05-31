#pragma once  // �������, �� ���� ���� ��������� ���� ���� ��� ��� ���������

// ��������� SegmentPoints ���������� ��� ��������� ��������� ����� ����� A, B, C �� ������� ��,
// � ����� ���������� ���������� � ������� ������ ������ AC � BC.
struct SegmentPoints {
    double A;        // ���������� ����� A
    double B;        // ���������� ����� B
    double C;        // ���������� ����� C (������ ������ �����������, �� ���� ����������� �� A � B)
    double product;  // ���������: ������� ������ ������ AC � BC
};

// ������� CalculateSegmentProduct ������ ��������� �� ��������� SegmentPoints,
// �������� ������� ������ AC �� BC, ������� �� � ������ ��������� � ���� product ���������.
void CalculateSegmentProduct(SegmentPoints& sp);

// ������� RunSegmentTest ��������������� ��� ���������� ������ CalculateSegmentProduct.
// ���� ������� ������� ��'���� SegmentPoints, �������� ���� ������,
// ������� ������� ����������, � ���� �������� ���������.
void RunSegmentTest();
