#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

#pragma warning(disable: 4996)

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

void quick_sort(std::vector<int>& numbers)
{
    quick_sort(numbers, 0, numbers.size() - 1);
}

constexpr int ROWS = 3;
constexpr int COLUMNS = 3;

void swap_rows(int array[ROWS][COLUMNS], const int x, const int y)
{
    for (int i = 0; i < COLUMNS; ++i)
        std::swap(array[x][i], array[y][i]);
}

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

struct Student
{
    Student(const char* name)
    {
        std::strncpy(m_name, name, sizeof(m_name));

        m_name[sizeof(m_name) - 1] = 0;
    }

    char m_name[16];
};

int sort_compare(const void* a, const void* b)
{
    return std::strcmp(
        static_cast<const Student*>(a)->m_name, 
        static_cast<const Student*>(b)->m_name
    );
}

void quick_sort_students(std::vector<Student> names)
{
    std::qsort(names.data(), names.size(), 16, sort_compare);
}

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