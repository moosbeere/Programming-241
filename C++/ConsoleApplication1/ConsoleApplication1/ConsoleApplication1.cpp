#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    float a = 2.3, b = 3.3;
    int n;
    cin >> n;
    float h = (b - a) / n;
    int nt = 0;
    float y, c = 0;
    float x = a;
    cout << "x       y\n";
    while (x <= b) {
        y = 1 / sqrt(pow(x, 2) - 3);
        if (nt == 0 or nt >= n) {
            c += y / 2; 
        }
        else c += y;
        cout << fixed << setprecision(3) << x << "   " << setprecision(5) << y << " " << nt << endl;
        x += h;
        nt++;
    }
    c *= h;
    cout << endl << c;
}

