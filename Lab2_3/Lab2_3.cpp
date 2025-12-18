#include <iostream>
#include <locale>
using namespace std;
void enableRussian() {
    setlocale(LC_ALL, "");
}
// Пункт 10 и 11: функция суммы чисел от 1 до n
int sumUpTo(int n = 1) {
    if (n <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
// Пункт 12-14: функция с передачей по ссылке
void sumAndProduct(int a, int b, int& sumRef, int& prodRef) {
    sumRef = a + b;
    prodRef = a * b;
}

int main() {
    enableRussian(); // включаем поддержку русского языка

    // 1. Создание 2x3 массива
    int arr2D[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // 2. Сумма всех чисел массива
    int totalSum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            totalSum += arr2D[i][j];
        }
    }
    cout << "Сумма всех чисел 2D массива: " << totalSum << endl;

    // 3. Создание одномерного массива из 3 элементов
    int colSum[3];

    // 4. Сумма по столбцам
    for (int j = 0; j < 3; j++) {
        colSum[j] = arr2D[0][j] + arr2D[1][j];
    }

    // 5. Вывод одномерного массива
    cout << "Суммы по столбцам: ";
    for (int j = 0; j < 3; j++) {
        cout << colSum[j] << " ";
    }
    cout << endl;

    // 6. Создание float переменной
    float myFloat = 20.84;

    // 7. Создание двух ссылок
    float& ref1 = myFloat;
    float& ref2 = myFloat;

    // 8. Изменение значения через ссылку
    ref1 = 50.5;

    // 9. Проверка изменения переменной и другой ссылки
    cout << "myFloat = " << myFloat << ", ref2 = " << ref2 << endl;

    // 10-11. Проверка функции sumUpTo
    cout << "sumUpTo(5) = " << sumUpTo(5) << endl;
    cout << "sumUpTo() = " << sumUpTo() << " (значение по умолчанию)" << endl;

    // 12-14. Проверка функции sumAndProduct
    int x = 3, y = 4, sumRes, prodRes;
    sumAndProduct(x, y, sumRes, prodRes);
    cout << "sumRes = " << sumRes << ", prodRes = " << prodRes << endl;

    // 15. Любая переменная
    string myVar = "Привет, мир!";
    cout << myVar << endl;

    // 16-18. Цикл с выводом переменных
    for (int i = 0; i < 3; i++) {
        cout << "arr2D[0][0] = " << arr2D[0][0] << endl;

        int innerVar = 100;  // объявление переменной внутри цикла
        cout << "innerVar = " << innerVar << endl;
    }

    // Попытка вывести innerVar за пределами цикла (раскомментировать для ошибки)
    // cout << innerVar << endl; // Ошибка: переменная не видна за пределами цикла

    return 0;
}
