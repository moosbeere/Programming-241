/* 
1) Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}. Использовать сортировку выбором. 
2) Написать программу, сортирующую по убыванию одномерный массив случайных целых чисел, находящихся в интервале {0,100}. 
3) Написать программу, сортирующую список телефонов по возрастанию и использующую  сортировку выбором. Телефон задан в виде строки. Например, 23-45-67.
*/
#include <iostream>
#include <ctime>
using namespace std;

void foo1()
{
	int const SIZE = 10;
	int arr[SIZE];
	cout << "Задание 1. " << endl;
	cout << "Исходный массив: ";
	for (int i = 0;i < SIZE;i++) // Заполнение массива случайными числами
	{
		arr[i] = rand() % (2, 103);
		cout << arr[i] << "\t";
	}
	cout << "\n" << "------------------------------------------------------------------------" << endl;
	int smallind = 0;
	int small = arr[0];
	cout << "Отсортированный массив: " << endl;
	for (int j = 0; j < SIZE; j++) 
	{
		for (int i = 0; i < SIZE; i++) 
		{
			if (arr[i] < small)
			{
				small = arr[i];
				smallind = i;
			}
			if (i == SIZE - 1)
			{
				arr[smallind] = 200;
				cout << small << "\t";
				small = arr[smallind];
			}
		}
	}
}

void foo2()
{
	int const SIZE = 10;
	int arr[SIZE];
	cout << "\n\nЗадание 2. " << endl;
	cout << "Исходный массив: \t" << endl;
	for (int i = 0;i < SIZE;i++) // Заполнение массива случайными числами
	{
		arr[i] = rand() % (2, 103);
		cout << arr[i] << "\t";
	}
	cout << "\n" << "------------------------------------------------------------------------" << endl;
	int maxind = 0;
	int max = arr[0];
	cout << "Отсортированный массив: " << endl;
	for (int j = 0; j < SIZE; j++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				maxind = i;
			}
			if (i == SIZE - 1)
			{
				arr[maxind] = -1;
				cout << max << "\t";
				max = arr[maxind];
			}
		}
	}
}
void foo3()
{
	cout << "\n\nЗадание 3. " << endl;
	string arr[] { "22-45-21  ", "22-23-51  ", "11-75-21  ", "92-10-31  ", "54-61-89"};
	string arr_sorted[4]{};
	string small = "Empty";

	cout << "Исходный массив: " << arr[0] << arr[1] << arr[2] << arr[3] << arr[4];
	cout << "\n" << "------------------------------------------------------------------------" << endl;
	
	int smallind = 0;
	int const SIZE = 5;
	cout << "Отсортированный массив: " << endl;
	for (int j = 0; j < SIZE; j++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i] < small)
			{
				small = arr[i];
				smallind = i;
			}
			if (i == SIZE - 1)
			{
				arr[smallind] = "Empty";
				cout << small << "\t";
				small = arr[smallind];
			}
		}
	}
}

int main()

{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	foo1();
	foo2();
	foo3();
	cout << endl;
	return 0;

}