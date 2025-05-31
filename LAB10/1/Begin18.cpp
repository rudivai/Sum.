#include <iostream>
#include "Begin18.h"
using namespace std;

/// Перевіряє, чи точка знаходиться у 2-й або 3-й координатній чверті.
/// II чверть: x < 0, y > 0
/// III чверть: x < 0, y < 0
/// Всі точки з x < 0, y ? 0 — задовольняють умові.
void CheckQuadrant(Point& p) {
    p.isInSecondOrThird = (p.x < 0 && (p.y != 0));
}

/// Функція вводить координати точки, перевіряє її положення
/// і виводить True/False відповідно до умови задачі.
void RunPointTest() {
    Point p;

    cout << "\nEnter x coordinate: ";
    cin >> p.x;

    cout << "Enter y coordinate: ";
    cin >> p.y;

    // Перевірка координатної чверті
    CheckQuadrant(p);

    // Вивід результату
    cout << "Point belongs to the II or III quadrant: "
        << (p.isInSecondOrThird ? "True (True)" : "False (False)") << endl;
}