#include <iostream>

using namespace std;

int summ(int n) {
    if (n <= 0) return 0;
    return n % 10 + summ(n / 10);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int N;
    cout << "Введите натуральное число N: ";
    cin >> N;
    cout << summ(N);
}