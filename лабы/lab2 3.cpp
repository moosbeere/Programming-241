#include <iostream>

using namespace std;

// Отдельная функция с переменной типа float
void myFunction() {
    float myFloat = 28.34f;
    
    // Создаём две ссылки на переменную myFloat
    float& ref1 = myFloat;
    float& ref2 = myFloat;
    
    cout << "Переменная типа float: " << myFloat << endl;
    cout << "Первая ссылка: " << ref1 << endl;
    cout << "Вторая ссылка: " << ref2 << endl;
    
    // Проверяем, что ссылки изменяют исходную переменную
    ref1 = 100.0f;
    cout << "После изменения через ref1: " << myFloat << endl;
}

// Функция, которая вычисляет сумму с параметром по умолчанию
void calculateSum(int number = 1) {
    if (number <= 0) {
        cout << "Результат: 0 (число должно быть положительным)" << endl;
        return;
    }
    
    int sum = 0;
    for (int i = 1; i <= number; i++) {
        sum += i;
    }
    
    cout << "Сумма чисел от 1 до " << number << " = " << sum << endl;
}

// Функция, которая принимает 4 значения (последние 2 по ссылке)
void processFourValues(int value1, int value2, int& ref1, int& ref2) {
    cout << "\nФункция processFourValues:" << endl;
    cout << "Первое значение (по значению): " << value1 << endl;
    cout << "Второе значение (по значению): " << value2 << endl;
    cout << "Третье значение (по ссылке) до изменения: " << ref1 << endl;
    cout << "Четвёртое значение (по ссылке) до изменения: " << ref2 << endl;
    
    // Записываем в первую ссылку сумму первых двух параметров
    ref1 = value1 + value2;
    // Записываем во вторую ссылку произведение первых двух параметров
    ref2 = value1 * value2;
    
    cout << "После изменения:" << endl;
    cout << "Первая ссылка (сумма " << value1 << " + " << value2 << "): " << ref1 << endl;
    cout << "Вторая ссылка (произведение " << value1 << " * " << value2 << "): " << ref2 << endl;
}

// Функция с переменной и циклом
void loopFunction() {
    int myVariable = 42; // переменная целого типа с любым значением
    
    cout << "\nФункция loopFunction:" << endl;
    cout << "Переменная myVariable: " << myVariable << endl;
    
    // Цикл, который выводит переменную 3 раза
    cout << "Вывод переменной в цикле:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Итерация " << (i + 1) << ": " << myVariable << endl;
        
        // Объявляем ещё одну переменную внутри цикла
        int innerVariable = i * 10 + 5; // любое значение, зависящее от итерации
        
        // Выводим её 3 раза
        cout << "  Внутренняя переменная выводится 3 раза: ";
        for (int j = 0; j < 3; j++) {
            cout << innerVariable << " ";
        }
        cout << endl;
    }
}

int main() {
    // Создаём двумерный массив 2x3
    int arr[2][3];
    
    // Заполняем массив числами по порядку с 4
    int number = 4;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = number;
            number++;
        }
    }
    
    // Выводим массив
    cout << "Двумерный массив 2x3:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    // Вычисляем сумму всех элементов
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += arr[i][j];
        }
    }
    
    cout << "Сумма всех элементов: " << sum << endl;
    
    // Создаём одномерный массив из трёх элементов
    int oneDimArray[3];
    
    // Заполняем одномерный массив суммами столбцов двумерного массива
    for (int j = 0; j < 3; j++) {
        int columnSum = 0;
        for (int i = 0; i < 2; i++) {
            columnSum += arr[i][j];
        }
        oneDimArray[j] = columnSum;
    }
    
    // Выводим одномерный массив
    cout << "Одномерный массив (суммы столбцов): ";
    for (int i = 0; i < 3; i++) {
        cout << oneDimArray[i] << " ";
    }
    cout << endl;
    
    // Вызываем отдельную функцию
    myFunction();
    
    // Вызываем функцию с параметром по умолчанию
    cout << "\nВызов функции без параметров (по умолчанию number = 1):" << endl;
    calculateSum();
    
    // Демонстрируем функцию с 4 параметрами (последние 2 по ссылке)
    int a = 5, b = 10;
    cout << "\nИсходные значения для демонстрации: a = " << a << ", b = " << b << endl;
    processFourValues(3, 7, a, b);
    cout << "После вызова функции: a = " << a << ", b = " << b << endl;
    
    // Вызываем функцию с циклом
    loopFunction();
    
    return 0;
}
