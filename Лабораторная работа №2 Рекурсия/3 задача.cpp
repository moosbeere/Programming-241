#include <iostream>
using namespace std;

int summaCifr(int a, int b = 0) {
	if (a == 0) {
		return b;
	}
	b += a % 10;
	return summaCifr(a / 10, b);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "����� 1 �����: ";
	cin >> n;
	cout << "����� ���� ����� " << n << " = " << summaCifr(n);
}