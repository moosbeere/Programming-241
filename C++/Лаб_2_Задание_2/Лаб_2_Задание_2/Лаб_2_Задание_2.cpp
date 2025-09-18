#include <iostream>
#include <list>
using namespace std;
int var1;
int sumVar = 0;

int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };

int main() {
	setlocale(LC_ALL, "Russian");
	while (true) {
		cout << "Введите целое положительное число: ";
		cin >> var1;
		if (var1 > 0) break;
	}
	for (int i = 0; i <= var1 ; i++) {
		sumVar += i;
	}
	cout << "Сумма всех чисел до целого положительного: " << sumVar << "\n";

	for (int i = 0; i<(sizeof(arr)/sizeof(arr[i])); i++) {
		cout << arr[i] << " ";
	}
	
	cout << endl;

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[i])); i++) {
		if (i % 2 == 0) {
			cout << arr[i] << " ";
		}
	}

	cout << endl;
	int sumArr = 0;

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[i])); i++) {
		if (i % 2 == 1) {
			sumArr += arr[i];
		}
	}
	cout << sumArr;

}