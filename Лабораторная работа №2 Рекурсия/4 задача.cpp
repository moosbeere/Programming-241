#include <iostream>
#include <math.h>
using namespace std;

int delitely(int a, int b) {
	if (a == b) {
		return b;
	}
	else if (a % b == 0) {
		cout << b << ", ";
		return delitely(a, b + 1);
	}
	else return delitely(a, b + 1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬веди одно число больше 1: ";
	cin >> n;
	cout << delitely(n, 1);
}