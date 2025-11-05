#include <iostream>
using namespace std;


void rec1(int n, int current = 1)
{
	if (current > n) return;
	else
	{
		cout << current << ' ';
		return rec1(n, current + 1);
	}
	cout << endl;
}

void rec2(int a, int b)
{

	if (a > b)
	{
		cout << a << ' ';
		return rec2(a-1, b);
	}
	else if (a < b)
	{
		cout << a << ' ';
		return rec2(a+1, b);
	}
	else
	{
		cout << a;
	}
}

int rec3(int n)
{
	if (n > 0) return n % 10 + rec3(n / 10);
	else return 0;
}

int isPrime(int n, int current = 2)
{
	if (current > sqrt(n)) return 1;
	else 
	{
		if (n % current != 0) return isPrime(n, current + 1);
		else return 0;
	}
}

void rec4(int n, int current = 2)
{
	if (current > n) return;
	else if (isPrime(current) == 1 && n % current == 0)
	{
		
		cout << current << ' ';
		return rec4(n, current + 1);
	}
	else return rec4(n, current + 1);
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0, b = 0, task = 0;
	cout << "Что нужно сделать?" << endl << "1. Вывести все числа от 1 до N" << endl << "2. Вывести все числа от A до B или от B до A" << endl << "3. Вывести сумму цифр числа N" << endl << "4. Вывести все простые делители числа N" << endl;
	cin >> task;
	switch (task)
	{
	case 1:
		cout << "Введите число N: ";
		cin >> n;
		
		rec1(n);
		break;
	case 2:
		cout << "Введите число A: ";
		cin >> n;

		cout << "Введите число B: ";
		cin >> b;

		rec2(n, b);
		break;
	case 3:
		cout << "Введите число N: ";
		cin >> n;

		cout << rec3(n);
		break;
	case 4:
		cout << "Введите число N: ";
		cin >> n;
		
		rec4(n);
		break;
	default:
		cout << "Такого номера действия нет";
		break;
	}
}