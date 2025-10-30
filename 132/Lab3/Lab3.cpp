#include <iostream>
using namespace std;

//функции и массивы
void separator() {
	std::cout << "\n---------------------\n";
}

void printArray(int array[], int length) {
	std::cout << *array;
	separator();
	//int length = sizeof(array) / sizeof(array[0]);
	//std::cout << length;
	//separator();
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << "\n";
	}
	//for (int i:array){}//ошибка
}

void printArray(int* begin, int* end) {//передадим указатели на первый и последний элементы массива
	for (int* p = begin; p < end; p++) std::cout << *p << " ";
}

const int cols = 2;
void printArray2(int(*array)[cols], int rows) {//передаем указатель на массив массивов и количечство строк
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			std::cout << array[i][j] << " ";
		std::cout << "\n";
	}
}

//void primtArray2(int *array[]){}// так получается массив указателей

void test(int* array) {
	array[3] = 25;
}

void test(const int* array) {//если не хотим давать возможность изменять значения элементов массива
	//array[3] = 25;ошибка
}

//указатели на функции
void function1() {
	std::cout << "Function 1\n";
}

void function2() {
	std::cout << "Function 2\n";
}

void (*pfs[])() = { function1, function2 };//массив указателей на функции

float add(float x, float y) {
	return x + y;
}

float sub(float x, float y) {
	return x - y;
}

int getMax(int array[], int length, bool (*compare)(int, int)) {
	int max = array[0];
	for (int i = 1; i < length; i++) {
		if (compare(array[i], max)) max = array[i];
	}
	return max;
}

bool compare1(int x, int y) {
	return x > y;
}

bool compare2(int x, int y) {
	return x < y;
}

void numberPositive() {
	std::cout << "+\n";
}

void numberNegative() {
	std::cout << "-\n";
}

void (*function(int x))() {
	if (x > 0) return numberPositive;//обращаемся к функции, а не вызываем ее.
	else return numberNegative;
}

//динамические объекты
int* test() {
	return new int(5);
}

int main() {
	//динамические объекты
	int* pc1 = new int(5);// new возвращает указатель
	std::cout << pc1 << " = " << *pc1 << "\n";
	delete pc1;
	int* pc2 = test();
	delete pc2;
	//delete pc2; // Неправильно!Мы не можем освободить память дважды

	int* array = new int[3] { 0, 5, -5 };
	std::cout << array[1] << "\n";
	for (int* i = array; i < array + 3; i++) {
		std::cout << *i << " ";
	}
	delete[] array;

	//указатели на функции
	void (*pf)();
	pf = function1;
	pf();

	pf = function2;
	pf();

	pfs[0]();
	pfs[1]();

	float (*operation)(float, float);
	operation = add;
	std::cout << operation(5, 7) << "\n";
	operation = sub;
	std::cout << operation(5, 7) << "\n";

	int array3[] = { 2, 5, 7, 0, -5 };
	std::cout << getMax(array3, 5, compare1) << "\n";
	std::cout << getMax(array3, 5, compare2) << "\n";

	void (*testf)() = function(-5);//инициализация
	testf();//вызов
	testf = function(5);
	testf();

	// функции и массивы
	int array4[] = { 2,3,7,43,4 };
	int length = sizeof(array4) / sizeof(array4[0]);
	printArray(array4, length);

	int array1[] = { 2,3,7,43,4 };
	printArray(std::begin(array1), std::end(array1));

	int array2[3][2] = { {2,3}, {5,6}, {8,9} };
	printArray2(array2, 3);
	
	//Работа с указателями
	int* pointer;
	int a = 25;
	pointer = &a;
	cout << pointer << endl; //вывод 000000AFA78FF854. Т.е. указатель возвращает адрес первого байта из 4х занимаемых переменной a
	cout << *pointer << endl;//процедура разименовывания указателя. Вывод 25
	*pointer = 50;
	cout << *pointer << endl;//процедура разименовывания указателя. Вывод 25

	//Указатели и константы
	const float PI = 3.14;
	const float G = 9.8;
	//float* pointer = &PI;//ошибка
	const float* pointer1 = &PI;
	std::cout << pointer1 << " = " << *pointer1 << "\n";
	//*pointer = 4;//ошибка
	pointer1 = &G;
	std::cout << pointer1 << " = " << *pointer1;
	int z = 20;
	int* const pz = &z;
	std::cout << pz << " = " << *pz << "\n";
	*pz = 25;
	std::cout << pz << " = " << *pz << "\n";
	std::cout << "z" << " = " << z << "\n";
	//pz = &x;//ошибка
	int m = 8;
	const int* const pm = &m;
	//*pm = 7;//ошибка
	//pm = &z;//ошибка
	std::cout << pm << " = " << *pm << "\n";

}