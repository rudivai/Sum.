#pragma once  // Гарантує, що файл буде підключено лише один раз при компіляції

// Структура SegmentPoints призначена для зберігання координат трьох точок A, B, C на числовій осі,
// а також результату обчислення — добутку довжин відрізків AC і BC.
struct SegmentPoints {
    double A;        // Координата точки A
    double B;        // Координата точки B
    double C;        // Координата точки C (умовою задачі передбачено, що вона розташована між A і B)
    double product;  // Результат: добуток довжин відрізків AC і BC
};

// Функція CalculateSegmentProduct приймає посилання на структуру SegmentPoints,
// обчислює довжини відрізків AC та BC, множить їх і записує результат у поле product структури.
void CalculateSegmentProduct(SegmentPoints& sp);

// Функція RunSegmentTest використовується для тестування роботи CalculateSegmentProduct.
// Вона створює приклад об'єкта SegmentPoints, заповнює його даними,
// викликає функцію обчислення, а потім виводить результат.
void RunSegmentTest();
