#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

using ll = long long;

void print1toN(ll n) {
    if (n == 0) return;
    print1toN(n - 1);
    cout << n << " ";
}

void printAtoB(ll a, ll b) {
    cout << a << " ";
    if (a == b) return;
    if (a < b) printAtoB(a + 1, b);
    else printAtoB(a - 1, b);
}

ll sumDigits(ll n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    return n % 10 + sumDigits(n / 10);
}

void printPrimeDivisors(ll n, ll d = 2) {
    if (n <= 1) return;

    if (d > n / d) {
        cout << n << " ";
        return;
    }

    if (n % d == 0) {
        cout << d << " ";
        printPrimeDivisors(n / d, d);
    }
    else {
        if (d == 2) printPrimeDivisors(n, 3);
        else printPrimeDivisors(n, d + 2);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    system("chcp 65001 > nul");

    srand(time(0));

    ll n = rand() % 15 + 1;
    ll A = rand() % 20 - 10;
    ll B = rand() % 20 - 10;
    ll N = rand() % 10000 + 1;
    ll M = rand() % 200 + 2;

    cout << "Случайные значения:\n";
    cout << "n = " << n << "\n";
    cout << "A = " << A << ", B = " << B << "\n";
    cout << "N = " << N << "\n";
    cout << "M = " << M << "\n\n";

    cout << "1) Числа от 1 до n:\n";
    print1toN(n);
    cout << "\n\n";

    cout << "2) Числа от A до B:\n";
    printAtoB(A, B);
    cout << "\n\n";

    cout << "3) Сумма цифр N:\n";
    cout << sumDigits(N) << "\n\n";

    cout << "4) Простые делители M:\n";
    printPrimeDivisors(M);
    cout << "\n";

    return 0;
}
