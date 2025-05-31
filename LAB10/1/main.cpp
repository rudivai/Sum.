#include <iostream>
#include "Param59.h"
#include "Begin18.h"
#include "Boolean27.h"
using namespace std;

/// Вивід текстового меню для користувача
void ShowMenu() {
    cout << "\n========== MENU ==========\n";
    cout << "1. Leap year check (Task 1)\n";
    cout << "2. Calculate product of segments AC and BC (Task 2A)\n";
    cout << "3. Coordinate quadrant check (II or III) (Task 2B)\n";
    cout << "0. Exit\n";
    cout << "==========================\n";
    cout << "Your choice: ";
}

int main() {
    int choice;

    // Main menu loop: runs until user selects 0
    do {
        ShowMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "\n--- Task 1: Leap Year ---\n";
            RunLeapYearTest();
            break;

        case 2:
            std::cout << "\n--- Task 2A: Segments AC and BC ---\n";
            RunSegmentTest();
            break;

        case 3:
            std::cout << "\n--- Task 2B: Coordinate Quadrant ---\n";
            RunPointTest();
            break;

        case 0:
            std::cout << "Program terminated.\n";
            break;

        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
    