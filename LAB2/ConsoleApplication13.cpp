#include <iostream>
using namespace std;

int main() {
    double x, y;

    // Введення даних
    cout << "Enter the x coordinate: ";
    cin >> x;
    cout << "Enter the y coordinate: ";
    cin >> y;

    // Перевірка, чи знаходяться координати в другій або третій чверті
    bool isInSecondOrThirdQuadrant = (x < 0 && y > 0) || (x < 0 && y < 0);

    // Виведення результату
    if (isInSecondOrThirdQuadrant) {
        cout << "Coordinates (" << x << ", " << y << ") lie in the second or third coordinate quarter." << endl;
    }
    else {
        cout << "Coordinates (" << x << ", " << y << ") do not lie in the second or third coordinate quarter." << endl;

    }
    return 0;

}
