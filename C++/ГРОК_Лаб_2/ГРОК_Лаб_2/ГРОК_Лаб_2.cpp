#include <iostream>

using namespace std;

void outputter(int n1, int n2) {
	if (n2 > n1) {
		cout << n1 << " ";
		if (n1 == n2 - 1) {
			return;
		}
		outputter(n1 + 1, n2);
	}
	else {
		cout << n1 << " ";
		if (n1 == n2 + 1) {
			return;
		}
		outputter(n1 - 1, n2);
	}
}
int sum;
void summator(int n) {
	sum += n % 10;
	if (n == 0) {
		return;
	}
	summator(n / 10);
}

void divider(int n, int d = 2)
{
	if (n % d == 0)
	{
		cout << d << endl;
		n /= d;
	}

	if (d > n) {
		return;
	}

	divider(n, d + 1);
}

int main() {
	// Дано натуральное число n. Выведите все числа от 1 до n.
	int a;
	cin >> a;
	outputter(1, a);
	cout << endl << endl;

	// Даны два целых числа A и В (каждое в отдельной строке). 
	// Выведите все числа от A до B включительно, в порядке возрастания, 
	// если A < B, или в порядке убывания в противном случае
	int b;
	cin >> a >> b;
	outputter(a, b);
	cout << endl << endl;

	// Дано натуральное число N. Вычислите сумму его цифр. 
	cin >> a;
	summator(a);
	cout << sum;
	cout << endl << endl;

	// Дано натуральное число n>1. Выведите все простые делители этого числа 
	// в порядке возрастания. Алгоритм должен иметь сложность О(корень из n)
	cin >> a;
	divider(a);
}