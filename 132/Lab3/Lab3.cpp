#include <iostream>
using namespace std;

int main() {
	int* pointer;
	int a = 25;
	pointer = &a;
	cout << pointer << endl; //����� 000000AFA78FF854. �.�. ��������� ���������� ����� ������� ����� �� 4� ���������� ���������� a
	cout << *pointer << endl;//��������� ��������������� ���������. ����� 25


}