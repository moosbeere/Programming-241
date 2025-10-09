#include <iostream>
using namespace std;



// 10. Функция для вычисления суммы чисел от 1 до n
int sumToN(int n = 1) {  // 11. Значение по умолчанию = 1
    if (n <= 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// 12. Функция с параметрами по ссылке
void calculateSumAndProduct(int a, int b, int& sumRef, int& productRef) {
    // 13. Записываем сумму и произведение в ссылки
    sumRef = a + b;
    productRef = a * b;
}

int main() {
    setlocale(LC_ALL, "RU");
    // 1. Создание двумерного массива 2x3
    int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // 2. Вывод суммы всех чисел массива
    int totalSum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            totalSum += matrix[i][j];
        }
    }
    cout << "Сумма всех чисел массива: " << totalSum << "\n";

    // 3. Создание одномерного массива из 3-х элементов
    int columnSums[3] = { 0 }; // Инициализация нулями
    setlocale(LC_ALL, "RU");

    // 4. Запись сумм столбцов в одномерный массив
    for (int j = 0; j < 3; j++) {
        columnSums[j] = matrix[0][j] + matrix[1][j];
    }

    // 5. Вывод получившегося одномерного массива
    cout << "Суммы столбцов: ";
    for (int i = 0; i < 3; i++) {
        cout << columnSums[i] << " ";
    }
    cout << "\n\n";

    // 6. Создание переменной типа float
    float originalValue = 20.84f;

    // 7. Создание 2 ссылок на переменную
    float& ref1 = originalValue;
    float& ref2 = originalValue;

    cout << "До изменения:\n";
    cout << "originalValue: " << originalValue << "\n";
    cout << "ref1: " << ref1 << "\n";
    cout << "ref2: " << ref2 << "\n";

    // 8. Изменение значения через ссылку
    ref1 = 35.67f;

    // 9. Проверка, что все значения изменились
    cout << "\nПосле изменения ref1:\n";
    cout << "originalValue: " << originalValue << "\n";
    cout << "ref1: " << ref1 << "\n";
    cout << "ref2: " << ref2 << "\n\n";

    // 10-11. Тестирование функции sumToN
    cout << "sumToN(0): " << sumToN(0) << "\n";
    cout << "sumToN(-5): " << sumToN(-5) << "\n";
    cout << "sumToN(5): " << sumToN(5) << "\n";
    cout << "sumToN() с default: " << sumToN() << "\n\n";

    // 12-14. Тестирование функции с ссылками
    int x = 5, y = 7;
    int sumResult = 0, productResult = 0; 

    cout << "До вызова calculateSumAndProduct:\n";
    cout << "x: " << x << ", y: " << y << "\n";
    cout << "sumResult: " << sumResult << ", productResult: " << productResult << "\n";

    calculateSumAndProduct(x, y, sumResult, productResult);

    cout << "После вызова calculateSumAndProduct:\n";
    cout << "sumResult: " << sumResult << ", productResult: " << productResult << "\n\n";

    // 15. Создание переменной любого типа
    string message = "Hello, World!";
    cout << "15. Переменная message: " << message << "\n\n";

    // 16-18. Цикл с переменными
    cout << "16-18. Цикл:\n";
    for (int i = 0; i < 3; i++) {
        // 16. Вывод переменной из пункта 1 (matrix) 3 раза
        cout << "matrix[0][0] = " << matrix[0][0] << " ";

        // 17. Объявление переменной внутри цикла
        int innerVar = i * 10;

        // 18. Вывод переменной внутри цикла 3 раза
        cout << "innerVar = " << innerVar << "\n";
    }

    // Попытка вывести переменную innerVar за пределами цикла
    // cout << innerVar; // Эта строка вызовет ошибку компиляции

    return 0;
}