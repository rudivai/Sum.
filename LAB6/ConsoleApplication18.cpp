#include <iostream>
#include <vector>
using namespace std;

// Прототипи функцій
void task1(); // Завдання 1: Виведення масиву у зворотному порядку
void task2(); // Завдання 2: Перестановка підмасиву у зворотному порядку
void inputArray(vector<int>& arr, int& n); // Функція для введення масиву
void outputArray(const vector<int>& arr); // Функція для виведення масиву
void reverseSubarray(vector<int>& arr, int k, int l); // Функція для перестановки підмасиву

int main() {
    while (true) {
        // Меню вибору завдання
        cout << "Choose a task (1 or 2). Enter 0 to exit: ";
        int choice;
        cin >> choice;

        // Перевірка вибору користувача
        if (choice == 0) {
            cout << "Exiting the program." << endl;
            break; // Завершення програми
        }

        // Виконання вибраного завдання
        switch (choice) {
        case 1:
            task1(); // Виконати завдання 1
            break;
        case 2:
            task2(); // Виконати завдання 2
            break;
        default:
            cout << "Invalid choice! Please choose 1, 2, or 0 to exit." << endl;
        }
    }
    return 0; // Успішне завершення програми
}

// Завдання 1: Виведення масиву у зворотному порядку
void task1() {
    int n;
    vector<int> arr;

    // Виклик функції для введення масиву
    inputArray(arr, n);

    // Виведення початкового масиву
    cout << "Original array:" << endl;
    outputArray(arr);

    // Виведення масиву у зворотному порядку
    cout << "Array in reverse order:" << endl;
    for (int i = n - 1; i >= 0; --i) {
        cout << arr[i] << " "; // Виведення елемента
    }
    cout << endl;
}

// Завдання 2: Перестановка підмасиву у зворотному порядку
void task2() {
    int n, k, l;
    vector<int> arr;

    // Виклик функції для введення масиву
    inputArray(arr, n);

    // Виведення початкового масиву
    cout << "Original array:" << endl;
    outputArray(arr);

    // Введення значень K і L
    cout << "Enter K and L (1 ≤ K < L ≤ N): ";
    cin >> k >> l;

    // Перевірка коректності введених значень
    if (k < 1 || l < 1 || k >= l || l > n) {
        cout << "Invalid values for K and L. Ensure that 1 ≤ K < L ≤ N." << endl;
        return; // Завершення функції у разі помилки
    }

    // Виклик функції для перестановки підмасиву
    reverseSubarray(arr, k, l);

    // Виведення зміненого масиву
    cout << "Modified array:" << endl;
    outputArray(arr);
}

// Функція для введення масиву
void inputArray(vector<int>& arr, int& n) {
    cout << "Enter the size of the array (N): ";
    cin >> n; // Введення розміру масиву

    // Перевірка розміру масиву
    if (n <= 0) {
        cout << "The size of the array must be greater than 0!" << endl;
        exit(1); // Завершення програми у разі помилки
    }

    // Зміна розміру вектора
    arr.resize(n);
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // Введення елементів масиву
    }
}

// Функція для виведення масиву
void outputArray(const vector<int>& arr) {
    for (int elem : arr) { // Ітерація по всіх елементах масиву
        cout << elem << " "; // Виведення елемента
    }
    cout << endl;
}

// Функція для перестановки підмасиву у зворотному порядку
void reverseSubarray(vector<int>& arr, int k, int l) {
    // Приведення K і L до індексів масиву
    int start = k - 1; // Початковий індекс
    int end = l - 1;   // Кінцевий індекс

    // Перестановка елементів
    while (start < end) {
        swap(arr[start], arr[end]); // Обмін місцями елементів
        ++start; // Зміщення початкового індексу
        --end;   // Зміщення кінцевого індексу
    }
}