// 4) Написать программу, сортирующую список студентов группы по алфавиту и использующую стандартную сортировку qsort

#include <iostream>
#include <ctime>
using namespace std;


void foo1(int arr[], int size)
{
	if (size <= 1)
		return;
	int index = rand() % size;
	int p = arr[index]; // выбор рандомного элемента массива в качестве опорного
	/*cout << "Массив: ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Опорный элемент = " << p << endl;*/


	int Pleft = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] < p)
			Pleft++;
	}
	int Pright = 0;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] >= p && i!=index)
			Pright++;
	}
	//cout << "Размер массива слева от опорного: " << Pleft << "\t" << "Размер массива справа от опорного: " << Pright << endl;

	int* left = new int[Pleft];
	int* right = new int[Pright];
	
	for (int i = 0, j = 0; i < size; ++i )
	{
		if (arr[i] < p)
		{ 
			left[j] = arr[i];
			++j;
		}
	}
	for (int i = 0, j = 0; i < size; ++i)
	{
		if (arr[i] >= p && i != index)
		{
			right[j] = arr[i];
			++j;
		}

	}
	//cout << "Left:" << endl;
	//for (int i = 0; i < Pleft; ++i)
	//	cout << left[i] << " ";
	//cout << endl;
	//cout << "Right:" << endl;
	//for (int i = 0; i < Pright; ++i)
	//	cout << right[i] << " ";
	//cout << endl;

	if (Pleft > 1)
		foo1(left, Pleft);
	if (Pright > 1)
		foo1(right, Pright);


	int current_index = 0;

	for (int i = 0; i < Pleft; i++) {
		arr[current_index++] = left[i];
	}

	arr[current_index++] = p;

	
	for (int i = 0; i < Pright; i++) {
		arr[current_index++] = right[i];
	}

	/*cout << "Собранный массив: ";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;*/

	delete[] right;
	delete[] left;
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	
	// 1) Задана последовательность из 1000 целых чисел.Переставить элементы последовательности таким образом, чтобы они располагались в порядке возрастания.
	int const size = 1000;
	int arr[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand() % 10000;
	}

	foo1(arr, size);

	for (int i = 0; i < 100; ++i) {  
		cout << arr[i] << " ";
	}

	cout << "\n" << "\n";
	int const size2 = 50;
	int arr2[size2];
	for (int i = 0; i < size2; ++i)
	{
		arr2[i] = rand() % (50,100);
	}

	// 2) Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале{ 50,100 }. Использовать быструю сортировку
	foo1(arr2, size2);
	for (int i = 0; i < size2; ++i) {
		cout << arr2[i] << " ";
	}





    // 3) Написать программу, сортирующую по возрастанию первый столбец двумерного массива целых чисел.Использовать быструю сортировку Массив создать из случайных чисел, расположенных в интервале{ 5,61 }
	int const size3 = 20;
	int arr3[size3][size3];
	for (int i=0; i < size3;++i)
	{
		for (int j = 0; j < size3;++j)
		{
			arr3[i][j] = rand() % (5, 61);
		}
	}
	int arr4[size3];
	for (int i = 0; i < size3;++i)
	{
		arr4[i] = arr3[i][0];
	}
	
	foo1(arr4, size3);
	cout << endl << endl;
	for (int i = 0; i < size3;++i)
	{
		cout << arr4[i] << "\t";
	}
	return 0;
}