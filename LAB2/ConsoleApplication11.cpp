#include <iostream>
using namespace std;

int main() {
    int A, B;

    // Введення даних
    cout << "Enter the length of segment A (A > B): ";
    cin >> A;
    cout << "Enter the length of segment B: ";
    cin >> B;

    // Перевірка умови A > B
    if (A <= B) {
        cout << "Error: A must be greater than B!" << endl;
        return 1; // Завершення програми з кодом помилки
    }

    // Обчислення кількості відрізків B на відрізку A
    int count = A / B;

    // Виведення результату
    cout << "The maximum number of segments of length B that can be placed on segment A: " << count << endl;

    return 0;
}