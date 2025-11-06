//ЗАДАНИЕ 1
#include <iostream>
using namespace std;

//int main() {
//	setlocale(LC_ALL, "ru");
//
//	//1. Создание переменной
//	int number = 15;
//
//	//2. Объявление указателя на созданную переменную
//	int* pointer = &number;
//
//	//3. Вывод в консоль адрес указателя и значение
//	cout << "Адрес указателя: ";
//	cout << pointer << endl;
//	cout << "Значение, которое хранится по этому адресу: ";
//	cout << *pointer << endl;
//
//	//4. Изменение значения, котрое хранится по этому адресу
//	*pointer = 36;
//
//	//5. Изменение значения
//	cout << "Новое значение из number: ";
//	cout << number << endl;
//
//	//6. Создание массива
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//	//7. Вывод всех элементов с помощью указателя
//	int* Arr = arr;
//	cout << "Элементы массива: "<< Arr << endl;
//
//	//8. Объявление целой переменной
//	int znachenie = 5;
//
//	//9. Создание указателя на нее
//	int* const const_znachenie = &znachenie;
//
//	//10. Проверка
//	*const_znachenie = 50;
//	cout << "Новое значение из const_znachenie: ";
//	cout << const_znachenie << endl;
//
//	return 0;
//	
//}






//ЗАДАНИЕ 2
//#include <iostream>
//using namespace std;
//
////1. Функция, которая принимает 2 указателя
int sumNumbers(int* begin, int* end) {
	int sum = 0;
	for (int* pointer = begin; pointer != end; pointer++) {
		sum += *pointer;
	}
	return sum;
}

//3. Создание функции с суммой
int Sum_chisel(int a, int b) {
	return a + b;
}

//3. Создание функции с разностью
int Razn_chisel(int a, int b) {
	return a - b;
}

//4, 5. Создание функции, которая возвращает указатель на одну из функций
int (*getOperation(char op))(int, int) {
	if (op == '+')
		return Sum_chisel;
	else if (op == '-')
		return Razn_chisel;
	else
		return nullptr;
}

int main() {
	setlocale(LC_ALL, "ru");
//6
	int (*testf)(int,int) = getOperation('-');
	cout << testf(3,5);

	//2. Проверка работы 1-го пункта
	int arr[] = { 1, 2, 3, 4, 5 };
	cout << "Сумма элементвов масиива: ";
	cout << sumNumbers(begin(arr), end(arr));

	//6. Проверка работы, созданных функций

	//7. Создание динамичекого указателя типа float
	float* pFloat = new float(3.14f);

	//8. Вывод в консоль и удаление его из памяти
	cout << "Значение данамически выделенного float: " << *pFloat << endl;
	delete pFloat;
	pFloat = nullptr;

	return 0;

}