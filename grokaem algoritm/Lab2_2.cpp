#include <iostream>
#include <string>

using namespace std;

string straightRecursion(int first, int second) {
	if (first == second) { return to_string(second); }
	return to_string(first) + " " + straightRecursion(first + 1, second);

}

string reverseRecursion(int first, int second) {
	if (first == second) { return to_string(second); }
	return to_string(first) + " " + reverseRecursion(first - 1, second);

}

int main() {
	setlocale(LC_ALL, "Ru");
	int A, B;
	cout << "Введите значения A и B: ";
	cin >> A >> B;
	if (A < B) {
		cout << "Рекурсия в порядке возрастания: " << straightRecursion(A, B);
	}
	else {
		cout << "Рекурсия в порядке убывания: " << reverseRecursion(A, B);
	}
}