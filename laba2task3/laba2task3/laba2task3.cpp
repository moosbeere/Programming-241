#include <iostream>
#include <string>
#include <locale>

using namespace std;

int sumSequence(int n = 1) {
    if (n <= 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
void calculateSumAndProduct(int a, int b, int& sumRef, int& productRef) {
    sumRef = a + b;
    productRef = a * b;
}

int main() {
    setlocale(LC_ALL, "Russian");


    int twoDimArray[2][3] = { {2, 4, 6}, {3, 5, 7} };

  
    int totalSum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            totalSum += twoDimArray[i][j];
        }
    }
    cout << "Сумма всех чисел массива: " << totalSum << endl;

    int oneDimArray[3];

    for (int j = 0; j < 3; j++) {
        oneDimArray[j] = twoDimArray[0][j] + twoDimArray[1][j];
    }

    cout << "Одномерный массив сумм столбцов: ";
    for (int i = 0; i < 3; i++) {
        cout << oneDimArray[i] << " ";
    }
    cout << endl;

    float originalVar = 20.84f;

    float& ref1 = originalVar;
    float& ref2 = originalVar;

 
    ref1 = 35.67f;

    cout << "originalVar: " << originalVar << endl;
    cout << "ref1: " << ref1 << endl;
    cout << "ref2: " << ref2 << endl;

    cout << "sumSequence(0): " << sumSequence(0) << endl;
    cout << "sumSequence(-5): " << sumSequence(-5) << endl;
    cout << "sumSequence(5): " << sumSequence(5) << endl;
    cout << "sumSequence() без параметра: " << sumSequence() << endl;

    int x = 5, y = 7;
    int sumResult = 0, productResult = 0; 

    cout << "До вызова функции: x=" << x << ", y=" << y << endl;
    cout << "sumResult=" << sumResult << ", productResult=" << productResult << endl;

    calculateSumAndProduct(x, y, sumResult, productResult);

    cout << "После вызова функции: x=" << x << ", y=" << y << endl;
    cout << "sumResult=" << sumResult << ", productResult=" << productResult << endl;

    string message = "Привет, мир!";
    cout << "Сообщение: " << message << endl;

    cout << "Цикл с выводом элементов массива:" << endl;
    for (int i = 0; i < 3; i++) {
        
        cout << "Элемент twoDimArray[0][" << i << "] = " << twoDimArray[0][i] << endl;

       
        int cycleVar = i * 10;

        cout << "cycleVar = " << cycleVar << endl;
    }

    return 0;
}   