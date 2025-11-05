#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#pragma warning(disable : 4996)
#include <windows.h>

using namespace std;

void sequenceQuickSort(vector<int> &vec, int left, int right)
{
	if (left > right) return;
	int pivot = vec[(left + right) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (vec[i] < pivot) i++;
		while (vec[j] > pivot) j--;
		if (i <= j)
		{
			int tmp = vec[i];
			vec[i] = vec[j];
			vec[j] = tmp;
			i++;
			j--;
		}
	}
	sequenceQuickSort(vec, left, j);
	sequenceQuickSort(vec, i, right);
}

void arrayQuickSort(int arr[], int left, int right)
{
	if (left > right) return;
	int pivot = arr[(left + right) / 2];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	arrayQuickSort(arr, left, j);
	arrayQuickSort(arr, i, right);
}

void array2D_QuickSort(int arr[][5], int left, int right)
{
	if (left > right) return;
	int pivot = arr[(left + right) / 2][0];
	int i = left, j = right;

	while (i <= j)
	{
		while (arr[i][0] < pivot) i++;
		while (arr[j][0] > pivot) j--;
		if (i <= j)
		{
			int tmp = arr[i][0];
			arr[i][0] = arr[j][0];
			arr[j][0] = tmp;
			i++;
			j--;
		}
	}
	array2D_QuickSort(arr, left, j);
	array2D_QuickSort(arr, i, right);
}

int compareStudent(const void* a, const void* b)
{
	const char* s1 = *(const char**)a;
	const char* s2 = *(const char**)b;
	return strcmp(s1, s2);
}

int main()
{
	SetConsoleCP(1251);      // ввод в CP1251
	SetConsoleOutputCP(1251);

	////////////////////////////// 1
	
	srand(time(0));

	vector <int> numbers;
	int vector_lenght = 1000; 
	for (int i = 0; i < vector_lenght; i++)
	{
		numbers.push_back(rand() % 100);
	}

	sequenceQuickSort(numbers, 0, vector_lenght-1);

	cout << "Отсортированная последовательность из 1000 целых чисел:" << endl;
	for (int value : numbers)
	{
		cout << value << " ";
	}
	cout << endl;

	////////////////////////// 2

	const int array1_size = 20;
	int array1[array1_size];

	for (int i = 0; i < array1_size; i++)
	{
		array1[i] = rand() % (99 - 51 + 1) + 51;
	}

	arrayQuickSort(array1, 0, array1_size - 1);

	cout << "Отсортированный одномерный массив по возрастанию из случайных целых чисел, находящихся в интервале {50,100}:" << endl;;
	for (int i : array1)
	{
		cout << i << ' ';
	}
	cout << endl;

	////////////////////// 3

	const int array2_columns = 5;
	const int array2_rows = 5;
	int array2[array2_rows][array2_columns];

	for (int i = 0; i < array2_rows; i++)
	{
		for (int j = 0; j < array2_columns; j++)
		{
			array2[i][j] = rand() % (62 - 6 + 1) + 6;
		}
	}

	array2D_QuickSort(array2, 0, array2_rows-1);

	cout << "Отсортированный двумерный массив по возрастанию из случайных целых чисел, находящихся в интервале {5,61}:" << endl;;
	for (int i = 0; i < array2_rows; i++)
	{
		for (int j = 0; j < array2_columns; j++)
		{
			cout << array2[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	///////////////////////////////// 4
	int n = 0;
	cout << "Введите число студентов: ";
	cin >> n;
	cin.ignore();

	char** students = new char*[n];

	cout << "Введите фамилии студентов (каждую с новой строки): " << endl;
	for (int i = 0; i < n; i++)
	{
		string temp;
		getline(cin, temp);
		
		students[i] = new char(temp.size() + 1);
		strcpy(students[i], temp.c_str());
	}

	qsort(students, n, sizeof(char*), compareStudent);

	cout << "Отсортированный список студентов: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << students[i] << endl;
	}
}