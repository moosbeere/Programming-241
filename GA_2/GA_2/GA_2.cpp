////ЗАДАНИЕ 1
//#include <iostream>
//using namespace std;
// 
//int main() {
//	setlocale(LC_ALL, "ru");
//
//	int n;
//	cout << "Ведите число: ";
//	cin >> n;
//	cout << "Числа от 1 до n: ";
//
//	for (int i = 1; i <= n; i++) {
//		cout << i << " ";
//	}
// 
//	return 0;
//}





////ЗАДАНИЕ 2
//#include <iostream>
//using namespace std;
//
//int main(){
//	setlocale(LC_ALL, "ru");
//	
//	int A;
//	cout << "Введите число A: ";
//	cin >> A;
//
//	int B;
//	cout << "Введите число B: ";
//	cin >> B;
//
//	cout << "Числа от A до B: ";
//
//	if (A < B) {
//		for (int i = A; i <= B; i++) {
//			cout << i << " ";
//		}
//	}
//
//	else {
//		for (int i = A; i >= B; i--) {
//			cout << i << " ";
//		}
//	}
//
//	return 0;
//}





////ЗАДАНИЕ 3
//#include <iostream>
//using namespace std;
//
//int sum_digits(int N) {
//	if (N == 0)
//		return 0;
//	return N % 10 + sum_digits(N / 10);
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	int N;
//	cout << "Введите число N: ";
//	cin >> N;
//	cout << "Сумма цифр числа N: ";
//	cout << sum_digits(N);
//
//	return 0;
//}





//ЗАДАНИЕ 4
#include <iostream>        
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Ввведите число: ";
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            bool isProstoe = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isProstoe = false;
                    break;
                }
            }

            if (isProstoe) {
                cout << "Простые делители: ";
                cout << i << " ";
            }
        }
    }

    cout << endl;
    return 0;
}
