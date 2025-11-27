#include <iostream>
using namespace std;

int sumRange(int* begin, int* end) {
    int sum = 0;
    while (begin != end) {
        sum += *begin;
         begin++;
    }
    return sum;
}

int pl(int a, int b) {
    return a + b;
}

int mi(int a, int b) {
    return a - b;
}

int (*chooseFunc(char c))(int, int) {
    if (c == '+')
        return pl;
    if (c == '-')
        return mi;

    return nullptr;
}

int main() {
    setlocale(LC_ALL, "RU");

    int arr[] = { 5, 10, 15, 20 };
    int result = sumRange(arr, arr + 4);
    cout << "Сумма массива: " << result << endl;

    char p = '+';
    int (*func)(int, int) = chooseFunc(p);
    if (func != nullptr) {
        cout << "Результат операции: " << func(7, 3) << endl;
    }

    float* pf = new float(3.14f);

    cout << "Динамическое значение: " << *pf << endl;
    delete pf;

    return 0;
}
