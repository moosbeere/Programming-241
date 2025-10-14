#include <iostream>
using namespace std;

int print(int y, int x) {
	if (y > x) {
		return -1;
	}
	cout << y << ", ";
	print(y + 1, x);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "¬веди 1 число: ";
	cin >> a;
	cout << print(1, a);
}