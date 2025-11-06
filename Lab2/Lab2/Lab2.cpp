//ЗАДАНИЕ 1
//#include <iostream> 
//using namespace std;
// 
//int main()	{ 
//	setlocale(LC_ALL, "ru");
//	
//	//Получение двух числе от пользователя
//	double num1, num2;
//		cout << "Введите первое число: ";
//		cin >> num1;
//		cout << "Введеите второе число: ";
//		cin >> num2;
//		
//		//Вывод среднего арифметического в консоль
//		double average = (num1 + num2) / 2;
//		cout << "Среднее арифметическое: << average << endl";
//		
//		//Вывод знака операции
//		cout << "Введите знак операции (+, -, *, /): ";
//		char operation;
//		cin >> operation; 
//		
//		//Вывод результатов
//		/*double result;
//		if (operation == '+') {
//			result = num1 + num2;
//		}
//		else if (operation == '-') {
//			result = num1 - num2;
//		}
//		else if (operation == '*') {
//			result = num1 * num2;
//		}
//		else if (operation == '/') {
//			result = num1 / num2;
//		}*/
//		
//		//С помощью switch case
//		int result_Switch_Case;
//		switch (operation)
//		{
//		case '+':
//			result_Switch_Case = num1 + num2;
//			break;
//		case '-':
//			result_Switch_Case = num1 - num2;
//			break;
//		case '*':
//			result_Switch_Case = num1 * num2;
//			break;
//		case '/':
//			if (num2 != 0) {
//				result_Switch_Case = num1 / num2;
//			}
//			else {
//				cout << "Ошибка: деление на ноль!" << endl;
//				return 1;
//			}
//			break;
//		default:
//			cout << "Ошибка: неизвестная операция!" << endl;
//			return 1;
//		}
//		cout << "Результат: " << result_Switch_Case << endl;
//
//		return 0;
//}





//ЗАДАНИЕ 2
//#include <iostream>         
//using namespace std;        
//
//int main() {     
//	setlocale(LC_ALL, "ru");
//	int n;                  
//	
//	//Вывод положительного числа 
//	while (true) {
//		cout << "Введите целое положительное число: "; 
//		cin >> n;                                     
//		if (n > 0) {                                 
//			break;                                    
//		}
//		else {
//			cout << "Это не положительное число" << endl;
//		}
//	}
//	
//	//Сумма от 1 до этого числа
//	int sum = 0;                   
//	for (int i = 1; i <= n; i++) { 
//		sum += i;                 
//	}
//	cout << "Сумма чисел от 1 до " << n << ": " << sum << endl; 
//	
//	//Массив из 10 чисел 
//	int arr[10] = { 3, 7, 12, 5, 9, 21, 8, 4, 11, 6 }; 
//	
//	//Вывод чисел в консоль
//	cout << "Все числа массива: ";      
//	for (int i = 0; i < 10; i++) {       
//		cout << arr[i] << " ";            
//	}
//	cout << endl;                        
//	
//	//Вывод чисел на четных позициях
//	cout << "Числа на чётных позициях: "; 
//	for (int i = 0; i < 10; i++) {         
//		if (i % 2 == 0) {                   
//			cout << arr[i] << " ";         
//		}
//	}
//	cout << endl;                        
//	
//	//Сумма чисел на нечетных позициях
//	int oddSum = 0;                     
//	for (int i = 0; i < 10; i++) {        
//		if (i % 2 != 0) {                 
//			oddSum += arr[i];             
//		}
//	}
//	cout << "Сумма чисел на нечётных позициях: " << oddSum << endl; 
//
//	return 0;                            
//}





//ЗАДАНИЕ 3
//#include <iostream>
//using namespace std;
//
////Создание функции 10 - 11 пункт
//int Chislo(int n = 1) {
//	if (n <= 0) return 0;
//	int sum = 0;
//	for (int i = 1; i <= n; i++) sum += i;
//	return sum;
//}
//
////Пункты 12-14
//void First_and_Second(int a, int b, int& sumRef, int& prodRef) {
//	sumRef = a + b;
//	prodRef = a * b;
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//	
//	//Создание двумерного массива 2 * 3
//	int arr2[2][3] = { {1, 2, 3}, {4, 5, 6} };
//
//	//Сумма этого массива
//	int summ_massiv2 = 0;
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 3; j++)
//			summ_massiv2 += arr2[i][j];
//	cout << "Сумма всех элементов 2x3: " << summ_massiv2 << endl;
//
//	//Создание одномерного массива из 3-х элементов
//	int colSumm[3] = {7, 8, 9};
//
//	//Сумма столбцов двумерного массива
//	for (int j = 0; j < 3; j++)
//		for (int i = 0; i < 2; i++)
//			colSumm[j] += arr2[i][j];
//
//	//Вывод одномерного массива в консоль
//	cout << colSumm;
//
//	//Переменная типа float
//	float number_float = 20.84;
//
//	//Созадние двух ссылок на эту переменную
//	float& ssilka1 = number_float;
//	float& ssilka2 = number_float;
//
//	//Изменение значения ссылки на новое
//	ssilka1 = 10.5f;
//
//	//Вывод переменной и ссылки
//	cout << "fval = " << number_float << ", ref2 = " << number_float << endl;
//
//	//Вывод функции с передачей по ссылке
//	int s = 0, p = 0;
//	First_and_Second(3, 4, s, p);
//	cout << "Сумма (через ссылку): " << s << ", Произведение (через ссылку): " << p << endl;
//
//
//	//Переменная и другая ссылка
//	cout << "number_float = ";
//	cout << "ssilka2";
//	
//	//Создание и вывод переменной с любым значением
//	string Text = "Пример строки";
//	cout << "Любая переменная: " << endl;
//
//	//Создание любого цикла и вывод внутри него переменную 3 раза
//	cout << "Вывод двумерного массива 3 раза: " << endl;
//	for (int k = 0; k < 3; k++)
//		for (int i = 0; i < 2; i++)
//			for (int j = 0; j < 3; j++)
//				cout << arr2 << endl;
//
//	//Создание переменной внутри цикла
//	int in_peremennya = 52;
//
//	//Вывод этой переменной внутри цикла 3 раза
//	cout << "Вывод переменной внутри цикла: " << endl;
//	for (int t = 0; t < 3; t++)
//		cout << in_peremennya << endl;
//
//	return 0;
//}





//ЗАДАНИЕ 4
#include <iostream>
#include "MyFunction.h"
using namespace MyFunc;
//
////Статическая переменная

//Вывод функции несколько раз
int main() {
    MyFunc::myFunction(5);   
    myFunction(10);  
    myFunction(3);  
    std::cin.get(); //позволяет exe файл не закрываться сразу после запуска
    return 0;
}

//Пространоство имен 
namespace myNamespace {
    using std::cout;
    using std::endl;
    void myFunction(int num) {
        static int staticVar = 0;
        cout << staticVar + num << endl;
        staticVar = num;
    }
}

////Майкрос для суммы
#define SUM(a,b) ((a) + (b))





