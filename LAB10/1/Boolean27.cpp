#include <iostream>
#include <cmath>
#include "Boolean27.h"
using namespace std;

/// Обчислення добутку довжин відрізків AC і BC.
/// Формула: |C - A| * |C - B|
/// Вхід: структура SegmentPoints з координатами A, B, C.
/// Результат зберігається в полі product.
void CalculateSegmentProduct(SegmentPoints& sp) {
    sp.product = abs(sp.C - sp.A) * abs(sp.C - sp.B);
}

/// Функція, яка запитує користувача ввести точки A, B, C.
/// Перевірку, що C між A і B, ми не робимо — за умовою довіряємо користувачу.
/// Потім викликається обчислення і виводиться результат.
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