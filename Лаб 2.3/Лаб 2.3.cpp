#include <iostream>
using namespace std;

int sum1(int n = 1) {
    if (n <= 0) return 0;
    int s = 0;
    for (int i = 1; i <= n; i++) s += i;
    return s;
}

void compute(int a, int b, int& sum, int& prod) {
    sum = a + b;
    prod = a * b;
}

int main() {
        setlocale(LC_ALL, "RU");

    int m[2][3] = { {1,2,3},{4,5,6} };

    int sum_arr = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            sum_arr += m[i][j];
    cout << "Сумма элементов: " << sum_arr << endl;

    int cols[3];

    for (int i = 0; i < 3; i++)
        cols[i] = m[0][i] + m[1][i];

    cout << "Суммы столбцов: ";
    for (int i = 0; i < 3; i++) cout << cols[i] << " ";
    cout << endl;

    float x = 20.84;

    float& r1 = x;
    float& r2 = x;

    r1 = 55.5;

    cout << x << " " << r1 << " " << r2 << endl;

    cout << "sum1() = " << sum1() << endl;

    int A = 3, B = 4, S, P;
    compute(A, B, S, P);
    cout << "S=" << S << ", P=" << P << endl;

    int x = 100;
    cout << x << endl;

    for (int i = 0; i < 3; i++) {
        cout << x << endl;

        int inside = 777;
        cout << inside << endl << inside << endl << inside << endl;
    }
    return 0;
}