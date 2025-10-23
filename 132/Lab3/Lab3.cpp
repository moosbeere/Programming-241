#include <iostream>
using namespace std;

int main() {
	int* pointer;
	int a = 25;
	pointer = &a;
	cout << pointer << endl; //вывод 000000AFA78FF854. Т.е. указатель возвращает адрес первого байта из 4х занимаемых переменной a
	cout << *pointer << endl;//процедура разименовывания указателя. Вывод 25
	*pointer = 50;
	cout << *pointer << endl;//процедура разименовывания указателя. Вывод 25


}