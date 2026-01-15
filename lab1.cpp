#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <locale>

// Функция для сортировки массива по возрастанию с использованием сортировки выбором
void selectionSortAscending(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}

// Функция для сортировки массива по убыванию с использованием сортировки выбором
void selectionSortDescending(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int maxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        std::swap(arr[i], arr[maxIdx]);
    }
}

// Функция для сортировки списка телефонов по возрастанию с использованием сортировки выбором
void selectionSortPhones(std::vector<std::string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (phones[j] < phones[minIdx]) {
                minIdx = j;
            }
        }
        std::swap(phones[i], phones[minIdx]);
    }
}

// Функция для генерации случайных чисел в указанном диапазоне
int getRandomInt(int low, int high) {
    return rand() % (high - low + 1) + low;
}

// Функция для вывода массива
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Устанавливаем локаль для правильного отображения русских символов
    std::setlocale(LC_ALL, "RU");  // Для Linux/Mac
    // Для Windows можно использовать: std::setlocale(LC_ALL, "Russian_Russia.UTF-8");

    // Или, можно использовать std::wcout для работы с широкими строками, если нужно, например:
    // std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    srand(time(0));  // Инициализация генератора случайных чисел

    // Задание 1: Сортировка массива случайных целых чисел по возрастанию
    std::vector<int> arr1;
    for (int i = 0; i < 10; ++i) {
        arr1.push_back(getRandomInt(2, 103));
    }

    std::cout << "Исходный массив (возрастание): ";
    printArray(arr1);

    selectionSortAscending(arr1);

    std::cout << "Отсортированный массив (возрастание): ";
    printArray(arr1);

    // Задание 2: Сортировка массива случайных целых чисел по убыванию
    std::vector<int> arr2;
    for (int i = 0; i < 10; ++i) {
        arr2.push_back(getRandomInt(0, 100));
    }

    std::cout << "\nИсходный массив (убывание): ";
    printArray(arr2);

    selectionSortDescending(arr2);

    std::cout << "Отсортированный массив (убывание): ";
    printArray(arr2);

    // Задание 3: Сортировка списка телефонов по возрастанию
    std::vector<std::string> phones = { "13-47-88", "12-34-56", "98-76-54", "34-56-78", "67-89-01" };

    std::cout << "\nИсходный список телефонов: ";
    for (const auto& phone : phones) {
        std::cout << phone << " ";
    }
    std::cout << std::endl;

    selectionSortPhones(phones);

    std::cout << "Отсортированный список телефонов: ";
    for (const auto& phone : phones) {
        std::cout << phone << " ";
    }
    std::cout << std::endl;

    return 0;
}
