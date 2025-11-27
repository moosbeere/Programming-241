#include <iostream>

using namespace std;

void sp() {
	cout << " ";
}

int sum(int first, int second) {
	return first + second;
}
int dif(int first, int second) {
	return first - second;
}

int (*charA(char a))(int, int) {
	if (a == '+') {
		return sum;
	}
	else if (a == '-') {
		return dif;
	}
}

int arrSum(int* first, int* last) {
	int sumA = 0;
	for (int* i = first; i < last; i++) {
		sumA = sum(sumA, *i);
	}
	return sumA;
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	cout << arrSum(begin(arr), end(arr));
	sp();
	cout << sum(arr[3], arr[4]);
	sp();
	cout << dif(arr[3], arr[4]) << endl;
	cout << charA('+');
	sp();
	int (*operation)(int, int) = charA('+');
	cout << operation(arr[3], arr[4]);
	float* dynamic = new float;
	*dynamic = 3.14;
	cout << *dynamic;
	delete dynamic;
}

