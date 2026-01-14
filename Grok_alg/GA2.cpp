#include <iostream>
using namespace std;

void First(int n) {
    if (n == 0) return;
    First(n - 1);    
    cout << n << " ";
}

void Second(int A, int B) {
    cout << A << " ";
    if (A == B) return;
    if (A < B)
        Second(A + 1, B);
    else
        Second(A - 1, B);
}

int Third(int n) {
    if (n == 0) return 0;
    return n % 10 + Third(n / 10);
}

void Fourth(int n, int d = 2) {
    if (n == 1) return;

    if (d * d > n) {
        cout << n << " ";
        return;
    }

    if (n % d == 0) {
        cout << d << " ";
        Fourth(n / d, d);
    } else {
        Fourth(n, d + 1);
    }
}


int main() {
    int n;
    cout << "Введите n для первого задания: ";
    cin >> n;
    First(n);
    cout << endl;
    
    int A, B;
    cout << "Введите A и B для второго задания: ";
    cin >> A >> B;
    Second(A, B);
    cout << endl;
    
    cout << "Введите n для третьего задания: ";
    cin >> n;
    cout << Third(n);
    cout << endl;
    
    cout << "Введите n для четвертого задания: ";
    cin >> n;
    Fourth(n);
    cout << endl;
    
    return 0;
}

