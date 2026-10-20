	// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void hello() {
	cout << "Hello, world!" << endl;
}

void print(string str) {
	cout << str << endl;
}
void print(float f) {
	cout << f << endl;
}
int sum(int a, int b, bool isPrint = false);
void mult(int x) {
	x *= 2;
}
void multRef(int& x) {
	x *= 2;
}
void divWithRemainder(int& a, int& b) {
	int div = a / b;
	int rem = a % b;
	a = div;
	b = rem;
}
int multToConst(const int x) {
	//x *= 2; это ошибка, так как переменная постоянная внутри функции изменена быть не может
	int y = x * 2;
	return y;

}

int y = 10;

void print() {
	int z = 19;
	cout << z << endl;
	cout << y << endl;
	//cout << x << endl; ошибка вызова локальной переменной
}
void test() {
	static int x = 0;
	x++;
	cout << x << endl;
}

int main()
{
	//область видимости
	int x = 17;
	cout << y << endl;
	print();
	if (true) {
		int a = 10;
	}
	//cout << a << endl;// ошибка вызова локальной переменной условия
	test();
	test();
	test();


	//функции и ссылки

	//int x = 10;
	////mult(x);
	//multRef(x);
	//cout << x << endl;


	//int n1 = 14;
	//int n2 = 4;
	//divWithRemainder(n1, n2);
	//cout << "n1 = " << n1 << endl;
	//cout << "n2 = " << n2 << endl;
	//cout << multToConst(10) << endl;

	//функции
	/*hello();
	print("Hello");
	print(7.7);
	int x = 10;
	int y = 12;
	cout << sum(x, y) << endl;
	int s = sum(x, y, true);*/

	//ссылки
	//int x = 10;
	//int& y = x;
	//cout << y << endl;
	//y = 15;
	//cout << x << endl;


	// многомерные массивы
	
	//int arr[3][2] = { {1,2}, {3,4}, {5,6} };
	//cout << arr[0][1] << endl;

	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		cout << arr[i][j] << ", ";
	//	}
	//	cout << endl;
	//}

	//for (auto& a : arr) {
	//	for (auto i : a) {
	//		cout << i << ", ";
	//	}
	//	cout << endl;
	//}

	//массивы
	//int numbers[5];
	//numbers[0] = 1;
	//numbers[1] = 2;
	//numbers[2] = 3;
	//numbers[3] = 4;
	//numbers[4] = 5;

	//for (int i = 0; i < 5; i++) {
	//	cout << numbers[i] << ", ";
	//}
	//cout << endl;

	//int arr[] = { 1,2,3,4,5 };
	//int length = sizeof(arr) / sizeof(arr[0]);
	//for (int i = 0; i < length; i++) cout << arr[i] << ", ";
	//cout << endl;

	//int sum = 0;
	//for (int a : arr) { // в случае, когда неизвестен тип данных элемента массива можно использовать автоматическое определение типа auto
	//	//cout << a << ", ";
	//	sum += a;
	//}
	//cout << sum << endl;



	//for (int i = 0; i < 10; i++) { //i++ (i = i + 1) (i +=i) 
	//	cout << i << ",";
	//}
	//cout << endl;

	//int i = 0;
	//while (i <= 10) {
	//	cout << i << ",";
	//	i++;
	//}
	//cout << endl;
	//i = 0;
	//do {
	//	cout << i << ",";
	//	i--;
	//} while (i > 0);
	//cout << endl;


	//int i = 0;
	//while (i < 7) {
	//	i++;
	//	if (i == 3) continue;
	//	if (i == 6) break;
	//	cout << i << endl;
	//}


	/*int a;
	cout << "Enter number: ";
	cin >> a;
	switch (a)
	{
	case 1: {
		cout << "Your's number: 1\n";
		break;
	}
	case 2: {
		cout << "Your's number: 2\n";
		break;
	}
	case 3: {
		cout << "Your's number: 3\n";
		break;
	}
	default: cout << "ok\n";
		break;
	}*/




	//if (a > 10) {
	//	a = a * 2;
	//}
	//else {
	//	a = a * 4;
	//}
	//a = (a > 10) ? (a * 2) : (a * 4);

	/*if (a > 10) {
		a = a * 2;
	}
	else if (a < 0){
		a = a * (-4);
	}
	else {
		a = a * 4;
	}*/
	//cout << a << endl;




	//a = a * 2;
	//cout << a << endl;

	/*string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << name << endl;*/

}

int sum(int a, int b, bool isPrint)
{
	int s = a + b;
	if (isPrint) print(s);
	return s;
}
