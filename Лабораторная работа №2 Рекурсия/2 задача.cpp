#include <iostream>
using namespace std;

int printpoloj(int x, int y) {
	if (x > y) {
		return -1;
	}
	cout << x << ", ";
	printpoloj(x + 1, y);
}

int printotric(int x, int y) {
	if (x < y) {
		return -1;
	}
	cout << x << ", ";
	printotric(x - 1, y);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a;
	cout << "¬веди 1 число: ";
	cin >> a;
	int b;
	cout << "¬веди 2 число: ";
	cin >> b;
	if (a < b) {
		cout << printpoloj(a, b);
	}
	if (a > b) {
		cout << printotric(a, b);
	}
}