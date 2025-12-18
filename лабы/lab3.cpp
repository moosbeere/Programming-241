#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

#pragma warning(disable: 4996)

// Рекурсивная функция быстрой сортировки (Quick Sort) для вектора целых чисел
// Параметры:
//   numbers - вектор чисел для сортировки (передается по ссылке)
//   left - левая граница подмассива (индекс начала)
//   right - правая граница подмассива (индекс конца)
// Алгоритм: выбирает опорный элемент (pivot) в середине массива,
// разделяет массив на элементы меньше и больше опорного,
// затем рекурсивно сортирует обе части
void quick_sort(std::vector<int>& numbers, const int left, const int right) 
{
    int i = left;
    int j = right;
    int pivot = numbers[(left + right) / 2];

    while (i <= j) 
    {
        while (numbers[i] < pivot) 
            i++;
        while (numbers[j] > pivot) 
            j--;

        if (i <= j)
        {
            std::swap(numbers[i], numbers[j]);
            i++; 
            j--;
        }
    }

    if (left < j) 
        quick_sort(numbers, left, j);

    if (i < right) 
        quick_sort(numbers, i, right);
}

// Обертка для функции быстрой сортировки
// Принимает вектор чисел и сортирует его полностью
// Вызывает рекурсивную версию quick_sort для всего массива
void quick_sort(std::vector<int>& numbers)
{
    quick_sort(numbers, 0, numbers.size() - 1);
}

constexpr int ROWS = 3;
constexpr int COLUMNS = 3;

// Функция для обмена двух строк в двумерном массиве
// Параметры:
//   array - двумерный массив размером ROWS x COLUMNS
//   x - индекс первой строки для обмена
//   y - индекс второй строки для обмена
// Обменивает все элементы строки x со строкой y
void swap_rows(int array[ROWS][COLUMNS], const int x, const int y)
{
    for (int i = 0; i < COLUMNS; ++i)
        std::swap(array[x][i], array[y][i]);
}

// Функция быстрой сортировки для строк двумерного массива
// Сортирует строки по значению первого элемента каждой строки
// Параметры:
//   array - двумерный массив для сортировки строк
//   left - левая граница диапазона строк
//   right - правая граница диапазона строк
// Использует первый элемент каждой строки как ключ для сравнения
void quick_sort_rows(int array[ROWS][COLUMNS], const int left, const int right)
{
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2][0];

    while (i <= j) 
    {
        while (array[i][0] < pivot) 
            i++;
        while (array[j][0] > pivot) 
            j--;

        if (i <= j) 
        {
            swap_rows(array, i, j);
            i++;
            j--;
        }
    }

    if (left < j)
        quick_sort_rows(array,left, j);

    if (i < right) 
        quick_sort_rows(array, i, right);
}

// Структура для хранения информации о студенте
// Содержит массив символов для хранения имени (максимум 15 символов + нулевой символ)
struct Student
{
    // Конструктор структуры Student
    // Параметры:
    //   name - указатель на строку с именем студента
    // Копирует имя в массив m_name с ограничением длины (15 символов + нулевой символ)
    // Гарантирует, что строка завершается нулевым символом
    Student(const char* name)
    {
        std::strncpy(m_name, name, sizeof(m_name));

        m_name[sizeof(m_name) - 1] = 0;
    }

    char m_name[16];  // Массив для хранения имени студента
};

// Функция сравнения для qsort при сортировке студентов
// Параметры:
//   a - указатель на первый элемент (Student)
//   b - указатель на второй элемент (Student)
// Возвращает:
//   отрицательное число, если имя первого студента меньше второго
//   0, если имена равны
//   положительное число, если имя первого студента больше второго
// Используется для лексикографической сортировки по именам
int sort_compare(const void* a, const void* b)
{
    return std::strcmp(
        static_cast<const Student*>(a)->m_name, 
        static_cast<const Student*>(b)->m_name
    );
}

// Функция сортировки вектора студентов по именам
// Параметры:
//   names - вектор студентов для сортировки
// Использует стандартную функцию qsort для сортировки массива студентов
// Сортирует по алфавиту используя функцию сравнения sort_compare
// Примечание: параметр передается по значению, поэтому изменения не сохраняются
void quick_sort_students(std::vector<Student> names)
{
    std::qsort(names.data(), names.size(), 16, sort_compare);
}

// Главная функция для демонстрации работы алгоритмов сортировки
// Тестирует:
//   1. Быструю сортировку вектора случайных чисел
//   2. Сортировку строк двумерного массива
//   3. Сортировку студентов по именам
int main_4()
{
	std::vector<int> numbers {};
	std::random_device device {};

	std::uniform_int_distribution<int> random_range_1(50, 100);

	for (int i = 0; i < 1000; i++)
		numbers.push_back(random_range_1(device));

	quick_sort(numbers);

    int array[3][3] =
    {
        3, 5, 6,
        1, 8, 3,
        6, 7, 8
    };

    quick_sort_rows(array, 0, 2);

    std::vector<Student> names {};
    names.push_back("Vadim");
    names.push_back("Andrew");
    names.push_back("Masha");

    quick_sort_students(names);

	return 0;
}

