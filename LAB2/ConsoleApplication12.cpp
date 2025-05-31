#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, num, denom, logx, y;
    cout << "Enter the value x: ";
    cin >> x;

    num = tan(2 * pow(x, 2) + 5 * x) - log10((x - 2, 5) / log10(5));
    logx = log10((pow(x, 2) - 2, 5)) / log10(5);
    denom = sqrt(abs(pow(sin(x), 4) * pow(x, 3) + logx));
    y = num / denom;

    cout << "y= " << y << endl;


    return 0;

}

