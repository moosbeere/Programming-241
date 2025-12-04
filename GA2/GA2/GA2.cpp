// GA2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void printFrom1ToN(int n) {
    if (n == 0) return;          // базовый случай
    printFrom1ToN(n - 1);        // рекурсивный вызов
    cout << n << " ";            // вывод после возврата
}

void printFromAtoB(int A, int B) {
    cout << A << " ";
    if (A == B) return;                 // базовый случай
    if (A < B) printFromAtoB(A + 1, B);
    else       printFromAtoB(A - 1, B);
}


int sumDigits(int n) {
    if (n == 0) return 0;             // базовый случай
    return (n % 10) + sumDigits(n / 10);
}

bool isPrime(int x, int i = 2) {
    if (x < 2) return false;
    if (i * i > x) return true;
    if (x % i == 0) return false;
    return isPrime(x, i + 1);
}

void printPrimeDivisors(int n, int i = 2) {
    if (i > n) return;
    if (n % i == 0 && isPrime(i))
        cout << i << " ";
    printPrimeDivisors(n, i + 1);
}
    
int main() {
    int n;
    cin >> n;
    printFrom1ToN(n);

    int A, B;
    cin >> A >> B;
    printFromAtoB(A, B);

    int n;
    cin >> n;
    cout << sumDigits(n);

    int n;
    cin >> n;
    printPrimeDivisors(n);


    return 0;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
