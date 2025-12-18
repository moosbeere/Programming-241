#include <iostream>
#include <math.h>

#define maxiter 500
#define e 1e-5

using namespace std;

void sp(int n) {
    cout << ' ';
    for (int i = 0; i < n; i++) {
        cout << '-';
    }
    cout << endl;
}

float f(float x, int n) {
    float y = 0;
    switch (n) {
    case 1: y = pow(x, 3) - 4 * pow(x, 2) + 3 * x + 6; break;
    case 2: y = exp(x) - 3 * pow(x, 2); break;
    case 3: y = 3 * pow(x, 2) - 8 * x + 3; break;
    case 4: y = exp(x) - 6 * x; break;
    default: break;
    }
    return y;
}

float newton1(float x) {
    int iter = 0;
    cout << "\t\t\t\t x^3 - 4x^2 + 3x + 6 = 0 \n";
    sp(95);
    cout << "|\tx\t\t|\tf(x)\t\t|\tf`(x)\t\t|\tx-f(x)/f`(x)\t|\n";
    sp(95);
    while (true) {
        cout << "|\t" << round(x * 10000) / 10000 << "\t\t|\t" 
            << round(f(x, 1) * 10000) / 10000 << "\t\t|\t" << 
            round((f(x, 3)) * 10000) / 10000 << "\t\t|\t" << 
            round((x - f(x, 1) / f(x, 3))*10000)/10000 << "\t\t|" 
            << endl;
        x -= f(x, 1) / f(x, 3);
        if ((fabs(f(x, 1)) < e) or (iter >= maxiter)) break;
        iter++;
    }
    sp(95);
    return x;
}
float newton2(float x) {
    int iter = 0;
    cout << "\t\t\t\t\t e^x - 3x^2 = 0 \n";
    sp(95);
    cout << "|\tx\t\t|\tf(x)\t\t|\tf`(x)\t\t|\tx-f(x)/f`(x)\t|\n";
    sp(95);
    while (true) {
        cout << "|\t" << round(x * 10000) / 10000 << "\t\t|\t" << 
            round(f(x, 2) * 10000) / 10000 << "\t\t|\t" << 
            round((f(x, 4)) * 10000) / 10000 << "\t\t|\t" << 
            round((x - f(x, 2) / f(x, 4))*10000)/10000 << "\t\t|"
            << endl;
        x -= f(x, 2) / f(x, 4);
        if ((fabs(f(x, 2)) < e) or (iter >= maxiter)) break;
        iter++;
    }
    sp(95);
    return x;
}

int main()
{
    setlocale(LC_ALL, "russian");

    cout << "\n\tНайденный корень: " << newton1(0);;
    cout << "\n\n\n\n  ";
    sp(90);
    cout << "\n\n";
    cout << "\n\tНайденный корень: " << newton2(0);
    cout << "\n";
    cout << "\n\tНайденный корень: " << newton2(1);
    cout << "\n";
    cout << "\n\tНайденный корень: " << newton2(3) << "\n\n\n";
}
