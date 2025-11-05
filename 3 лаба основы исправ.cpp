#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	//переменная со значением
	int num = 5;
	//указатель на нее
	int* ykaz = &num;
	//вывод адреса и значения
	cout << "Адрес указателя: " << ykaz << endl;
	cout << "Значение указателя: " << *ykaz << endl;
	//замена значения
	*ykaz = 10;
	//убеждаюсь что изменилось
	cout << *ykaz << endl;
	//создаю массив
	int mass[3] = { 1, 2, 3 };
	//вывод массива исп указ
	cout << "Массив через указатель: ";
	int* ykazmass = mass;
	for (int i = 0; i < 3; i++) {
		cout << *(ykazmass + i) << " ";
	}
	cout << endl;
	//еще одна переменная
	int num2 = 10;
	cout << "Переменная num2: " << num2;
	//указатель на нее (нельзя менять адрес)
	int* const nelz = &num2;
	//убеждаюсь что сделал все правильно
	//*nelz = 20;
	//cout << *num2;

	return 0;
}