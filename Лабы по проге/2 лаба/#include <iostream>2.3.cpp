#include <iostream>
#include <string>
using namespace std;

int sum_upto(int n = 1) {
    if (n <= 0) return 0;
    int s = 0;
    for (int i = 1; i <= n; ++i) s += i;
    return s;
}

void calculate(int a, int b, int& sum, int& prod) {
    sum = a + b;
    prod = a * b;
}

int main() {
    // 1. Двумерный массив 2x3
    int arr2d[2][3] = { {1, 4, 7}, {2, 5, 8} };

    // 2. Сумма всех чисел массива
    int sum_all = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            sum_all += arr2d[i][j];
    cout << "Сумма всех чисел двумерного массива: " << sum_all << endl;

    // 3. Одномерный массив из 3-х элементов
    int arr1d[3];

    // 4. Суммы столбцов двумерного массива
    for (int j = 0; j < 3; ++j) {
        arr1d[j] = arr2d[0][j] + arr2d[1][j];
    }

    // 5. Вывод одномерного массива
    cout << "Суммы по столбцам: ";
    for (int j = 0; j < 3; ++j)
        cout << arr1d[j] << " ";
    cout << endl;

    // 6. Переменная float
    float fval = 20.84;

    // 7. Две ссылки на переменную
    float& ref1 = fval;
    float& ref2 = fval;

    // 8. Изменение значения через ссылку
    ref1 = 42.77;

    // 9. Проверка изменений
    cout << "fval: " << fval << endl;
    cout << "ref1: " << ref1 << endl;
    cout << "ref2: " << ref2 << endl;

    // 10-11. Функция с параметром по умолчанию
    cout << "sum_upto(5): " << sum_upto(5) << endl;
    cout << "sum_upto(): " << sum_upto() << endl;

    // 12-14. Функция с ссылками
    int x = 3, y = 4, s = 0, p = 0;
    calculate(x, y, s, p);
    cout << "Сумма: " << s << ", Произведение: " << p << endl;

    // 15. Переменная любого типа
    string str = "Пример строки";
    cout << str << endl;

    // 16-18. Цикл с переменными
    for (int i = 0; i < 3; ++i) {
        int inside_val = i * 10; 
        cout << "arr1d[0] внутри цикла: " << arr1d[0] << endl;
        for (int k = 0; k < 3; ++k)
            cout << "inside_val: " << inside_val << endl;
    }

    // 19. Попытка доступа к переменной вне цикла (ошибка)
    // cout << inside_val << endl;

    return 0;
}

