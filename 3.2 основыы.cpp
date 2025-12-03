#include<iostream>
using namespace std;

void func1(int* pa, const int* ps)
{
	//cout << *pa << endl << *(pa+1);

	int sum = 0;
	for (int i = 0; i < *ps; ++i)
	{
		sum = sum + *(pa + i);
	}
	cout << "сумма элементов массива: " << sum << endl;
}


int func2(int a, int b)
{
	cout << a << b;
	return a + b;
}
int func3(int a, int b)
{

	return a - b;
}

int (*func4(char operation))(int, int) {
	if (operation == '+') {
		return &func2;
	}
	else if (operation == '-') {
		return &func3;
	}
	return nullptr;
}

int main()
{
	setlocale(LC_ALL, "RU");
	const int size = 5;
	int arr[size]{ 23,12,76,22,-16 };
	int* pa = arr;
	const int* ps = &size;

	func1(pa, ps);
	char sym;
	cout << "введите знак операции (+) или (-) : ";
	cin >> sym;

	int (*operation)(int, int) = func4(sym);

	if (operation != nullptr)
	{
		int result = operation(10, 5);
		cout << "результат операции: " << result << endl;
	}
	else
		cout << "неизвестная операция!" << endl;

	float* px = new float;
	*px = 12.12;
	cout << endl << "динамический указатель: " << *px << endl;
	delete px;
	return 0;
}