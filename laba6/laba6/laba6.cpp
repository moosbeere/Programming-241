
#include <iostream>
using namespace ::std;


int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "Введите число 1 2 или 3: ";
    int number;
    cin >> number;

    switch (number) {
        case 1:
            cout << "Один" << "\n";
            break;
        case 2:
            cout << "Два" << "\n";
            break;  
        case 3:
            cout << "Три" << "\n";
            break;  
        default:
            throw invalid_argument("Некорректное значение");
    }

    cout << "Введите год рождения: ";
        
}

