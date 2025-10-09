
#include <iostream>
#include <cmath>
using namespace ::std;

void f(int n, int t = 1) 
{
    if (t > n)
        return;
    cout << t << "\n";
    f(n, t + 1);

}

void f2(int a, int b)
{
    if (a < b)
    {
        cout << a << "\n";
        f2(a + 1, b);
    }
    else if (a > b)
    {
        cout << a << "\n";
        f2(a - 1, b);
    }
    else
    {
        if (a == b)
            cout << a << "\n";
        return;
    }
    
}

int f3(int n, int suma = 0)
{
    if (n % 10 == 0 and suma != 0)
        return suma;
    return f3(n / 10, suma + n % 10);
}

void f4(int n, int div, int& new_n) {
    if (n % div != 0) {
        new_n = n;
        return;
    }
    f4(n / div, div, new_n);
}

void f5(int n, int i = 2) {
    if (n == 1) return;
    if (i * i > n) {
        if (n > 1) cout << n << " ";
        return;
    }
    if (n % i == 0) {
        cout << i << " ";
        int q;
        f4(n, i, q);
        f5(q, i + 1);
    }
    else {
        f5(n, i + 1);
    }
}


int main()
{
    int n = 10;
    f(n);
    
    int a, b;
    cin >> a;
    cin >> b;
    f2(a, b);
    cin >> n;
    int suma = f3(n);
    cout << suma;
    
    int p;
    cin >> p;
    f5(p);
    return 0;
}


