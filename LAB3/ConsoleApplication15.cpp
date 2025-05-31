#include <iostream>
#include <cmath>
using namespace std;
//прототипи функції
void task_if18();
void task_geom32();
int main() {
    
    int menu;
    cout << "Task number:";
    cin >> menu;
    // перемикання між завданнями
    switch (menu)
    {
    case 1: task_if18(); break; // Завдання 1
    case 2: task_geom32(); break; // Завдання 2
    default: cout << "Wrong task! (Only 1,2)" << endl; //повідомлення про помилку
    }
    system("pause");
    return 0;
}


//пишу код для першої задачі
void task_geom32() {
    int x;
    int y;
    double radius;
    // Виписую дві константи щоб не було помилки при общисленні
    const double PI = 3.141592;
    const double half = 0.5;
    
   // Даю запит на введення змінних
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "Enter the x , y: ";
    cin >> x >> y;
    //Знаходжу  основу через теорему Піфагора 
    double base =  sqrt(pow(radius ,2) + pow(radius, 2));
    //Знаходжу площу маленького трикутника
    double small_triangle_area = (base * base) / 4;
    // Знаходжу площу для кола
    double circle_area = PI * radius * radius;
    //Знаходжу четверту частину кола
    double quarter_circle_area = circle_area / 4;
    //Формула площи великого трикутника
    double large_triangle_area = (base * base) / 2; 
    //Фомула знаходження коричневого еліпса
    double brown_ellipse_area = quarter_circle_area - small_triangle_area ;
    //Знаходження чистої площи  великого поморанчевого трикутника
    double remaining_area = large_triangle_area - brown_ellipse_area;
    //Формула пириметра маленького трикутника
    double small_triangle_p = base + radius + radius;
    //Формула гіпотенузи великого трикутника
    double large_triangle_gip = sqrt(pow(base, 2) + pow(base, 2));
    //Знаходження пиреметра великого трикутника
    double large_triangle_p = base + base + large_triangle_gip;
    // Перевірка на додатне значення
    if (brown_ellipse_area < 0) {
        cout << "Error: Brown ellipse area is negative. Please provide more accurate data." << endl;
        
    }
    //Превірка чи знаходить точка у площині чи виходить з неї
    
    double distance = sqrt(x * x * y * y);
    if (distance <= radius) {
        if (distance <= quarter_circle_area);
    }
    if (x = base) {

        cout << "in region  " << endl;
    }
    else {
        cout << "out region" << endl;
         }
    
        

   //Виведення усі площи та пириметри
    cout << "Area of the small orange triangle: " << small_triangle_area << endl;
    cout << "Area of the large orange triangle: " << large_triangle_area << endl;
    cout << "Remaining area after subtracting yellow ellipse: " << remaining_area << endl;
    cout << "Perimetr of small orange triangle:  " << small_triangle_p << endl;
    cout << "Perimetr of large triangle :  " << large_triangle_p << endl;
    
}
void task_if18()
{
    // Оголошуємо три цілочисельні змінні
    int a, b, c;

    // Виводимо запит на введення чисел
    cout << "Enter three integers: ";
    // Зчитуємо три числа з введення
    cin >> a >> b >> c;

    // Перевіряємо всі можливі комбінації, де одне число відрізняється від двох інших
    if (a != b && a != c) {
        cout << "Ordinal number of the perfect number: 1" << endl; // Якщо a відрізняється від b і дорівнює c
    }
    if (b != a && b != c) {
        cout << "Ordinal number of the perfect number: 2" << endl; // Якщо b відрізняється від a і дорівнює c
    }
    if (c != a && c != b) {
        cout << "Ordinal number of the perfect number: 3" << endl; // Якщо c відрізняється від a і дорівнює b
    } 
}
