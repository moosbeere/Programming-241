#include <iostream>
using namespace std;

// 1) Дано натуральное число n.Выведите все числа от 1 до n.
void foo1(int n)
{
	if (n > 0)
	{
		foo1(n - 1);
		cout << n << " ";
	}
}

// 2) Дано натуральное число n>1. Выведите все простые делители этого числа в порядке возрастания.
void foo2(int n, int a)
{
	if (a > 0)
	{
		foo2(n, a-1);
		if (n%a == 0)
			cout << a << " ";
	}
}

// 3) Дано натуральное число N.Вычислите сумму его цифр.При решении этой задачи нельзя использовать строки, списки, массивы(ну и циклы, разумеется).
int foo3(int n)
{
	if (n == 0)
		return 0;
	return n % 10 + foo3(n / 10);
}

// 4) Даны два целых числа A и В(каждое в отдельной строке).Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае
void foo4(int A, int B)
{
	if (A == B)
		cout << A << " ";
	else if (A > B)
	{
		cout << A << " ";
		foo4(A-1, B);

	}
	else
	{
		foo4(A, B-1);
		cout << B << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int n, A, B, a, sum;
	cout << "Введите число N: ";
	cin >> n;
	a = n;
	
	foo1(n);
	cout << endl;
	
	foo2(n,a);
	cout << endl;

	cout << foo3(n) << endl;

	cout << "Введите число A: ";
	cin >> A;
	cout << "Введите число B: ";
	cin >> B;

	foo4(A, B);
	cout << endl;



}