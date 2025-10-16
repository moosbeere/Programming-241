#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    int num;
    cout << "Введите целое положительное число: ";
    cin >> num;
    while (true) {
        if (num > 0) {
            break;
        }
        else { 
            cout << "Введите целое положительное число: ";
            cin >> num; 
        }
    }
    int sum = 0;
    for (int i = 1; i <= num; i++) {
        sum += i;
        cout << " " << i << " ";
        if (i != num) { cout << "+"; }
    }
    cout << " = " << sum << endl;
    vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9 };
    for (int i = 0; i < 10; i++) { cout << vec[i] << " "; }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            cout << vec[i] << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        if (i % 2 != 0) {
            cout << vec[i] << " ";
        }
    }
}