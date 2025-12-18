#include <iostream>
using namespace std; // пока используем здесь

// Функция с одним параметром и статической переменной
void printSumWithStatic(int num) {
    static int staticVar = 0; // статическая переменная
    cout << "Сумма: " << num + staticVar << endl;
    staticVar = num; // обновляем значение статической переменной
}

int main() {
    printSumWithStatic(5);  // 5 + 0 = 5
    printSumWithStatic(10); // 10 + 5 = 15
    printSumWithStatic(3);  // 3 + 10 = 13
    return 0;
}
