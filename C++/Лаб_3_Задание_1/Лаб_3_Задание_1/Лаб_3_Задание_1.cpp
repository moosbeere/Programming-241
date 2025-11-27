#include <iostream>

using namespace std;

char s() {
	return ' ';
}

int main() {
	setlocale(LC_ALL, "Russian");

	int a = 30;
	int b[] = { 1, 2, 3 };
	int c = 5;
	int* pointer = &a;
	int* const pc = &c;

	cout << "Значение: |   Адрес:" << endl;
	cout << s() << *pointer << "       |    " << pointer << endl;
	*pointer = 23;
	cout << s() << *pointer << "       |    " << pointer << endl;

	for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
		cout << *(b + i) << s();
	}
	
	cout << "Значение: |   Адрес:" << endl;
	cout << s() << *pc << "       |    " << pc << endl;
	//pc = &a; expression must be a modifiable lvalue E0137
	*pc = 7;
	cout << s() << *pc << "       |    " << pc << endl;

}