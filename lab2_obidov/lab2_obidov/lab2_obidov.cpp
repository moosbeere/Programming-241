	#include <iostream>
using namespace std;
//
//int main()
//{
//    cout << "введите первое число:";
//    int a;
//    int b;
//    cin >> a; cout << "Введите второе число:";  cin >> b;
//    cout << "операция:";
//    char c;
//    cin >> c;
//
//    if (c == '*') {
//        cout << a * b;
//    }
//    
//    else if (c == '+') {
//        cout << a + b;
//    }
//    else if (c == '-') {
//        cout << a - b;
//    }
//    else if (c == '/') {
//        if (b != 0) {
//            cout << a / b;
//        }
//        else {
//            cout << "Ошибка: деление на ноль";
//        }
//    }
//    else {
//        cout << "Неизвестная операция";
//    }
//    switch (c)
//    {
//    case'*':
//         cout<<a * b;  
//        break;
//    case'/':
//        cout << a / b;
//        break;
//    case'-':
//        cout << a - b;
//        break;
//    case'+':
//        cout << a + b;
//        break;
//    default:
//        cout << "Введите только один из следующих символов:+,-,*,/";
//        break;
//    }
//
//}

//2

int main() {
	cout << "vvedite chislo";
	int a;
	cin >> a;
	int sum = 0;
	while (true) {
		if (a <= 0) {
			cout << "vvedite chislo";
			cin >> a;
		}
		else {
			break;
		}
		}
	
	for (int i = 1; i <= a; i++) {
		sum += i;
		cout << i;
		if (i < a) {
			cout << "+";
			
		}
	}
	cout <<"="<< sum;
}
