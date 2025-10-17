#include <iostream>
using namespace std;

// 1 
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


                         //2-2.2

//int main() {
//	cout << "vvedite chislo";
//	int a;
//	cin >> a;
//	int sum = 0;
//	while (true) {
//		if (a <= 0) {
//			cout << "vvedite chislo";
//			cin >> a;
//		}
//		else {
//			break;
//		}
//		}
//	
//	for (int i = 1; i <= a; i++) {
//		sum += i;
//		cout << i;
//		if (i < a) {
//			cout << "+";
//			
//		}
//	}
//	cout <<"="<< sum;
//}

//2.3-2.6
//int numbers[] = {1,2,3,4,5,6,7,8,9,10};
//int sum = 0; 
//int main() {
//	2.3-2.4
//	for (int i = 0; i < 10; i++ ) {
//		cout << "2.1-2.3" << endl << numbers[i]<<endl;
//	}
//	
//	
//	for (int j = 0; j < 10; j++) */{
//	 2.5
//		if (numbers[j] % 2 == 0) {
//			cout << numbers[j];
//		}

//2.6
//		if (numbers[j] % 2 == 1) {
//			sum += numbers[j];
//			
//		}
//
//	}
//	cout << sum;
//}


//chast 3
//3.1-3.2
//int massive[2][3] = {{ 1,2,3 },{ 4, 5, 6 }};

//int main() {
	//int sum = 0;
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 3; j++) {
	//		sum += massive[i][j];
	//	}

	//}
	//cout << "Summa stolbcov 2-mernogo massiva=" << sum << endl;

	//3.2-3.5
	//int odno[3];
	//for (int l ; l < 3; l++) {
	//	odno[l] = 0;
	//	for (int k = 0; k < 2; k++) {
	//		odno[l] += massive[k][l];
	//
	//	}
	//	if (l > 0) {
	//		cout << " ";
	//		cout << odno[l] << " ";
	//	}


	//3.6-3.9
		//float x = 20.84;
		//float& t = x;

		//float& chisl = x;
		//chisl = 14;
		//cout << chisl;
	//prinimaem();

//}




//3.10
//int calculateSum(int number) {
//	if (number <= 0) {
//		return 0;
//	}
//
//	int sum = 0;
//	for (int i = 1; i <= number; i++) {
//		sum += i;
//	}
//	return sum;
//}
//
//int main() {
//
//	int num;
//
//	cout << "Введите число: ";
//	cin >> num;
//
//	int result = calculateSum(num);
//	cout << "Результат: " << result << endl;
//
//	return 1;
//}

//3.12-3.14
//int ssilki() {
//
//	int a = 2;
//	int b = 3;
//	int d = a + b;
//	int aa = a * b;
//	int &c = d;
//	int& e = aa;
//	cout << "Сумма:" << c << endl << "Произведение:" << e;
//	return 0;
//}

//3.14-3.18

//3.18
//int mas() {
//	int luboe = 5;
//	for (int i = 1; i < 4; i++) {
//		cout << luboe;
//		
//	}
//	return 0;
//}

//int main() {
//	ssilki();
//	return 0;
//	mas();
//}

//chast4
//4.1-4.3


//void static_func(int a) {
//	static int x = 0;
//	cout << x + a << endl;
//	x = a;  
//}
//
//int main() {
//	static_func(4);
//	static_func(10);	
//
//	
//#define suuma(a, b) ((a) + (b))
//
//
//	int konec = suuma(5, 3);
//	cout << "Результат макроса: " << konec << endl;
//
//	return 0;
//}



