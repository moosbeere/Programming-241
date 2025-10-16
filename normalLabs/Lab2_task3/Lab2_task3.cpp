#include <iostream>

using namespace std;

void ssilki(int a, int b, int &s1, int &s2) {
    s1 = a + b;
    s2 = a * b;
}

int func(int n = 1) {
    if (n <= 0) {
        return 0;
    }
    else {
        int s = 0;
        for (int k = 1; k <= n; k++) { s += k; }
        return s;
    }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int sum = 0;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    cout << "Сумма двумерного массива: " << sum << endl;

    int arr[3] = { 0, 0, 0 };
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr[j] += matrix[i][j];
        }
    }
    cout << "Новый одномерный массив: ";
    for (int i = 0; i < 3; i++) { cout << arr[i] << " "; }

    float num = 20.84;
    float &first = num;
    float& second = num;
    cout << endl << "До: " << num << " " << first << " " << second;
    first = 13.2;
    cout << endl << "После: " << num << " " << first << " " << second << endl;
    
    cout << func(1) << endl;
    
    // 12, 13, 14
    int sum_res, prod_res;
    ssilki(2, 4, sum_res, prod_res);
    cout << "Ссылки в функции: " << sum_res << " " << prod_res << endl;

    int last = 0;
    for (int i = 1; i < 4; i++) {
        int error = 404;
        cout << i << ". Объявление в цикле переменной last: " << last << endl;
    }
    // cout << error;
}
