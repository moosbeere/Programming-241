#include <iostream>
using namespace std;

float signChecker(float var = 1) {
	int sumVar = 0;
	if (var <= 0) {
		return 0;
	}
	else {
		for (int i = 0; i < var; i++) {
			sumVar += i;
		}
		return (sumVar+(var-int(var)));
	}
}
void funcRef(int var1, int var2, int& refvar1, int& refvar2) {
	refvar1 = var1 + var2;
	refvar2 = var1 * var2;
}

int main() {
	//..1
	setlocale(LC_ALL, "Russian");

	const int r1 = 2, c1 = 3;
	int sumArr1 = 0;
	int arr1[r1][c1] = {
		{ 5, 1, 2 },
		{ 9, 3, 6 }
	};

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			sumArr1 += arr1[i][j];
		}
	}
	cout << "Сумма двумерного массива размера 2х3: " << sumArr1 << endl;
	//--------------------------------------------------------

	//..2
	const int c2 = 3;
	int arr2[c2];
	for (int i = 0; i < c1; i++) {
		arr2[i] = arr1[0][i] + arr1[1][i];
	}
	for (int i = 0; i < c2; i++) {
		cout << arr2[i] << " ";
	}
	cout << "\n";
	//--------------------------------------------------------

	//..3
	float var1 = 20.84;
	float& refvar1{ var1 };
	float& refvar{ var1 };

	cout << "                      var1   refvar1   var1\nИзначальные значения: ";
	cout << var1 << "   " << refvar1 << "   " << refvar;
	refvar1 = 20.84 * 2;
	cout << endl << "Конечные значения:    ";
	cout << var1 << "   " << refvar1 << "   " << refvar << endl << "Напишите число: ";
	//--------------------------------------------------------

	//..4
	float var2;
	cin >> var2;
	cout << "Ответ: " << signChecker(var2);
	/*float signChecker(float var = 1) {
	int sumVar = 0;
	if (var <= 0) {
		return 0;
	}
	else {
		for (int i = 0; i < var; i++) {
			sumVar += i;
		}
		return (sumVar+(var-int(var)));
	}*/
	//--------------------------------------------------------

	//..5
	int var4, var5, refvar4, refvar5;
	cout << "\nНапишите 4 цифры: ";
	cin >> var4 >> var5 >> refvar4 >> refvar5;
	cout << "                      var1   var2   refvar1   refvar2\nИзначальные значения: ";
	cout << var4 << "   " << var5 << "   " << refvar4 << "   " << refvar5;
	funcRef(var4, var5, refvar4, refvar5);
	cout << endl << "Конечные значения:    ";
	cout << var4 << "   " << var5 << "   " << refvar4 << "   " << refvar5 << endl << "Напишите число: ";
	//--------------------------------------------------------
	char chair = 'c';
	cout << chair;
	for (int i = 0; i < 3; i++) {
		char iAmLosingMyMind = 'A';
		cout << chair;
		cout << iAmLosingMyMind;
	}
}