#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Прототипи функцій
void calculateSeries(); // Завдання 1: Обчислення ряду
void checkInputData();  // Завдання 2: Перевірка коректності вхідних даних
void countPointsInTriangle(); // Завдання 3: Кількість точок у трикутнику
bool isPointInTriangle(double x, double y, double r); // Допоміжна функція для завдання 3

// Головне меню
int main() {
    int choice;

    do {
        // Виведення меню
        cout << "\nProgram menu:\n";
        cout << "1. Calculation of the series\n";
        cout << "2. Checking the correctness of the input data\n";
        cout << "3. The number of points in the triangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Виконання вибраної задачі
        switch (choice) {
        case 1:
            calculateSeries();
            break;
        case 2:
            checkInputData();
            break;
        case 3:
            countPointsInTriangle();
            break;
        case 4:
            cout << "The program is over." << endl;
            break;
        default:
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 4); // Повторювати меню, поки не обрано вихід

    return 0;
}

// Функція для обчислення ряду (Завдання 1)
void calculateSeries() {
    // Вхідні дані
    double x, epsilon, g;
    int maxIterations = 1000;

    cout << "\nSeries calculation:\n";
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter epsilon (precision, 0 < epsilon < 1): ";
    cin >> epsilon;
    cout << "Enter g (discrepancy threshold, g > 1): ";
    cin >> g;

    // Перевірка коректності
    if (epsilon <= 0 || epsilon >= 1 || g <= 1) {
        cout << "Invalid input data. Try again." << endl;
        return;
    }

    double sum = 0.0;
    for (int k = 1; k <= maxIterations; ++k) {
        double term = pow(x - k, k + 1) / tgamma(k + 1); // tgamma(k+1) для факторіала
        sum += term;

        if (fabs(term) < epsilon) {
            cout << "The series converges for k = " << k << ".Sum: " << sum << endl;
            return;
        }
        if (fabs(term) > g) {
            cout << "The series diverges at k = " << k << ". Sum: " << sum << endl;
            return;
        }
    }
    cout << "The maximum number of iterations has been reached. Sum: " << sum << endl;
}

// Функція для перевірки коректності вхідних даних (Завдання 2)
void checkInputData() {
    double epsilon, g;

    cout << "\nChecking the correctness of input data:\n";
    cout << "Enter epsilon (precision, 0 < epsilon < 1): ";
    cin >> epsilon;
    cout << "Enter g (discrepancy threshold, g > 1): ";
    cin >> g;

    if (epsilon > 0 && epsilon < 1 && g > 1) {
        cout << "The data is correct." << endl;
    }
    else {
        cout << "The data is incorrect." << endl;
    }
}

// Функція для визначення кількості точок у трикутнику (Завдання 3)
void countPointsInTriangle() {
    int n;       // Кількість точок
    double r;    // Радіус кола

    cout << "\nThe number of points in the triangle:\n";
    cout << "Enter the number of points (n): ";
    cin >> n;
    cout << "Enter the radius of the circle (r): ";
    cin >> r;

    vector<pair<double, double>> points(n);

    // Введення координат точок
    for (int i = 0; i < n; ++i) {
        cout << "Enter the coordinates of the point " << i + 1 << " (x y): ";
        cin >> points[i].first >> points[i].second;
    }

    int count = 0;
    for (const auto& point : points) {
        if (isPointInTriangle(point.first, point.second, r)) {
            count++;
        }
    }

    cout << "Number of points in the triangle: " << count << endl;
}

// Допоміжна функція для перевірки, чи точка в трикутнику
bool isPointInTriangle(double x, double y, double r) {
    // Перевіряємо, чи точка знаходиться в оранжевій зоні (див. рисунок)
    return (x >= 0 && y >= 0 && y <= x && x * x + y * y <= r * r);
}
