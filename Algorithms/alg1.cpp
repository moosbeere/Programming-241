#include <iostream>
#include <string>
using namespace std;

void swap(int* a, int* b) // замена значений двух переменных
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(string* a, string* b) // замена значений двух переменных
{
	string temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int array[], int const len) // сортировка выбором по возрастанию
{
	for (int i = 0; i < len - 1; i++) // первый элемент
	{
		int min_id = i; // iтый элемент становится минимальным
		for (int j = i + 1; j < len; j++) // следующий элемент
		{
			if (array[min_id] > array[j])
			{
				min_id = j; // если следующий элемент меньше найденного минимального, то следующий элемент становится минимальным
			}
		}
		swap(&array[min_id], &array[i]); // замена значений элементов
	}
}

void unselectionSort(int array[], int const len) // сортировка выбором по убыванию
{
	for (int i = 0; i < len - 1; i++) // первый элемент
	{
		int max_id = i; // iтый элемент становится минимальным
		for (int j = i + 1; j < len; j++) // следующий элемент
		{
			if (array[max_id] < array[j])
			{
				max_id = j; // если следующий элемент меньше найденного минимального, то следующий элемент становится минимальным
			}
		}
		swap(&array[max_id], &array[i]); // замена значений элементов
	}
}

void telephoneSelectionSort(string array[], int const len) // сортировка выбором по возрастанию
{
	for (int i = 0; i < len - 1; i++) // первый элемент
	{
		int min_id = i; // iтый элемент становится минимальным
		for (int j = i + 1; j < len; j++) // следующий элемент
		{
			if (array[min_id] > array[j])
			{
				min_id = j; // если следующий элемент меньше найденного минимального, то следующий элемент становится минимальным
			}
		}
		swap(&array[min_id], &array[i]); // замена значений элементов
	}
}


int main()
{
	//////////////////////////// 1
	setlocale(LC_ALL, "ru");
	cout << "Сортировка выбором по возрастанию:" << endl;
	srand(time(0));
	int randArray1[15] = {};

	for (int i = 0; i < 15; i++)
	{
		randArray1[i] = rand() % (103 - 2 + 1) + 2; // создание массива с псевдорандомными числами [2;103]
		cout << randArray1[i] << ' '; // первоначальный массив
	}
	cout << endl;
	int lenArray1 = sizeof(randArray1) / sizeof(randArray1[0]); // длина массива

	selectionSort(randArray1, lenArray1);

	for (int i = 0; i < 15; i++)
	{
		cout << randArray1[i] << ' '; // отсортированный массив
	}
	cout << endl;

	/////////////////////////// 2

	cout << "Сортировка выбором по убыванию:" << endl;
	srand(time(0));
	int randArray2[15] = {};

	for (int i = 0; i < 15; i++)
	{
		randArray2[i] = rand() % (100 + 1); // создание массива с псевдорандомными числами [0;100]
		cout << randArray2[i] << ' '; // первоначальный массив
	}
	cout << endl;
	int lenArray2 = sizeof(randArray2) / sizeof(randArray2[0]); // длина массива

	unselectionSort(randArray2, lenArray2);

	for (int i = 0; i < 15; i++)
	{
		cout << randArray2[i] << ' '; // отсортированный массив
	}
	cout << endl;

	/////////////////////////////////// 3
	cout << "Сортировка списка телефонных номеров вида 12-34-56 выбором по возрастанию:" << endl;

	srand(time(0));
	string randArray3[15] = {};

	for (int i = 0; i < 15; i++)
	{
		randArray3[i] = to_string(rand() % (99 - 10 + 1) + 10) + "-" + to_string(rand() % (99 - 10 + 1) + 10) + "-" + to_string(rand() % (99 - 10 + 1) + 10); // создание номеров вида 12-34-56
		cout << randArray3[i] << ' ';
	}
	
	

	cout << endl;
	int lenArray3 = sizeof(randArray3) / sizeof(randArray3[0]); // длина массива

	telephoneSelectionSort(randArray3, lenArray3);

	for (int i = 0; i < 15; i++)
	{
		cout << randArray3[i] << ' '; // отсортированный массив
	}
	cout << endl;
}