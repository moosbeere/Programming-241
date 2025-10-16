#include <iostream>
using namespace std;

int main() {
	int* pointer;
	int a = 25;
	pointer = &a;
	cout << pointer << endl; //вывод 000000AFA78FF854. “.е. указатель возвращает адрес первого байта из 4х занимаемых переменной a
	cout << *pointer << endl;//процедура разименовывани€ указател€. ¬ывод 25


}