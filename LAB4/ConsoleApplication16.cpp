#include <iostream>
using namespace std;

// Прототипи функцій
void task1(); // Завдання 1: Перевірка положення точки в другій чи третій чверті
void task2(); // Завдання 2: Перевірка існування N-ї цифри в числі K
void task3(); // Завдання 3: Обчислення кількості відрізків B на відрізку A
bool isValidInput(double x, double y); // Допоміжна функція для завдання 1
bool isInSecondOrThirdQuadrant(double x, double y); // Допоміжна функція для завдання 1
bool digitExists(int K, int N); // Допоміжна функція для завдання 2
bool inputValues(int& A, int& B); // Допоміжна функція для завдання 3
int calculateSegments(int A, int B); // Допоміжна функція для завдання 3
void outputResult(int count); // Допоміжна функція для завдання 3

int main() {
    while (true) {
        // Меню вибору завдання
        cout << "Choose a task:\n";
        cout << "1. Check if a point lies in the second or third quadrant.\n";
        cout << "2. Check if the N-th digit exists in a number K.\n";
        cout << "3. Calculate the maximum number of segments B on segment A.\n";
        cout << "0. Exit.\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        // Вибір дії відповідно до вибору користувача
        switch (choice) {
        case 1:
            task1(); // Виконання завдання 1
            break;
        case 2:
            task2(); // Виконання завдання 2
            break;
        case 3:
            task3(); // Виконання завдання 3
            break;
        case 0:
            cout << "Exiting the program." << endl;
            return 0; // Завершення програми
        default:
            cout << "Invalid choice! Please choose 1, 2, 3, or 0 to exit." << endl;
        }
    }
}

// Завдання 1: Перевірка положення точки в другій чи третій чверті
void task1() {
    double x, y;

    // Введення координат
    cout << "Enter coordinates (x, y): ";
    cin >> x >> y;

    // Перевірка коректності введення
    if (!isValidInput(x, y)) {
        cout << "Invalid input! Coordinates must be finite numbers." << endl;
        return; // Завершення завдання у разі помилки
    }

    // Перевірка положення точки
    if (isInSecondOrThirdQuadrant(x, y)) {
        cout << "The point (" << x << ", " << y << ") lies in the second or third quadrant." << endl;
    }
    else {
        cout << "The point (" << x << ", " << y << ") does not lie in the second or third quadrant." << endl;
    }
}

// Завдання 2: Перевірка існування N-ї цифри в числі K
void task2() {
    int K, N;

    // Введення числа і позиції
    cout << "Enter a positive integer K (1 ≤ K < 1000): ";
    cin >> K;
    cout << "Enter a position N (0 < N ≤ 4): ";
    cin >> N;

    // Перевірка коректності введення
    if (K <= 0 || K >= 1000 || N <= 0 || N > 4) {
        cout << "Invalid input! Ensure 1 ≤ K < 1000 and 0 < N ≤ 4." << endl;
        return; // Завершення завдання у разі помилки
    }

    // Виклик функції для перевірки
    bool exists = digitExists(K, N);

    // Виведення результату
    cout << "Does the " << N << "-th digit exist in " << K << "? " << (exists ? "Yes" : "No") << endl;
}

// Завдання 3: Обчислення кількості відрізків B на відрізку A
void task3() {
    int A, B;

    // Введення значень
    if (!inputValues(A, B)) {
        cout << "Invalid input! A and B must be positive integers with A > B." << endl;
        return; // Завершення завдання у разі помилки
    }

    // Обчислення результату
    int count = calculateSegments(A, B);

    // Виведення результату
    outputResult(count);
}

// Допоміжні функції

// Функція для перевірки коректності введення координат
bool isValidInput(double x, double y) {
    return isfinite(x) && isfinite(y);
}

// Функція для перевірки, чи точка лежить у другій чи третій чверті
bool isInSecondOrThirdQuadrant(double x, double y) {
    return (x < 0 && y > 0) || (x < 0 && y < 0);
}

// Функція для перевірки існування N-ї цифри в числі K
bool digitExists(int K, int N) {
    // Перевірка коректності позиції
    if (N == 1) {
        return true; // Перша цифра завжди існує
    }
    if (K < 10) {
        return false; // Якщо залишилася лише одна цифра, але потрібна більша позиція
    }
    return digitExists(K / 10, N - 1); // Рекурсія: видаляємо останню цифру і зменшуємо N
}

// Функція введення для завдання 3
bool inputValues(int& A, int& B) {
    cout << "Enter two positive integers (A > B): ";
    cin >> A >> B;

    // Перевірка коректності введених даних
    return (A > 0 && B > 0 && A > B);
}

// Функція підрахунку кількості відрізків
int calculateSegments(int A, int B) {
    return A / B; // Кількість відрізків дорівнює цілочисельному діленню
}

// Функція виведення результату
void outputResult(int count) {
    cout << "The maximum number of segments of length B that can fit in length A: " << count << endl;
}

