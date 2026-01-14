#include <iostream>
using namespace std;

// 10-11. Функция для суммы чисел от 1 до n 
int sumUpTo(int n = 1) {
    if (n <= 0) return 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

// 12-14. Функция с двумя ссылками 
void sumAndProduct(int a, int b, int &sumR, int &prodR) {
    sumR = a + b;
    prodR = a * b;
}

int main() {
    // 1. Двумерный массив 2x3
    int arr2d[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // 2. Сумма всех чисел двумерного массива
    int totalSum = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            totalSum += arr2d[i][j];
    cout << "Сумма всех чисел двумерного массива: " << totalSum << endl;

    // 3-5. Одномерный массив с суммами по столбцам
    int arr1d[3] = {0};
    for (int j = 0; j < 3; ++j) {
        arr1d[j] = arr2d[0][j] + arr2d[1][j];
    }
    cout << "Суммы по столбцам: ";
    for (int i = 0; i < 3; ++i) cout << arr1d[i] << " ";
    cout << endl;

    // 6-9. Ссылки на float =====
    float num = 20.84;
    float &ref1 = num;
    float &ref2 = num;

    ref1 = 50.5; // изменение через ссылку

    cout << "num = " << num << ", ref2 = " << ref2 << endl; // обе обновились

    // 10-11. Проверка функции sumUpTo
    cout << "sumUpTo(5) = " << sumUpTo(5) << endl;
    cout << "sumUpTo() = " << sumUpTo() << " (значение по умолчанию)" << endl;

    // 12-14. Проверка функции sumAndProduct
    int sumR, prodR;
    sumAndProduct(3, 4, sumR, prodR);
    cout << "Сумма = " << sumR << ", Произведение = " << prodR << endl;

    // 15. Переменная любого типа
    string message = "Привет, мир!";
    cout << message << endl;

    // 16-18. Цикл с переменными
    for (int i = 0; i < 3; ++i) {
        // вывод переменной из пункта 6 (num)
        cout << "num внутри цикла: " << num << endl;

        // переменная внутри цикла
        int tempVar = 100;
        for (int j = 0; j < 3; ++j) {
            cout << "tempVar внутри внутреннего цикла: " << tempVar << endl;
        }
    }

    // cout << tempVar << endl; // <- ошибка

    return 0;
}

