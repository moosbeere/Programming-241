#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Student {
    char surname[50];
    char name[50];
    int group;
};

// Функция сравнения для qsort
int compare(const void* a, const void* b) {
    return strcmp(((Student*)a)->surname, ((Student*)b)->surname);
}

int main() {
    // Устанавливаем русскую локаль для ввода/вывода
    setlocale(LC_ALL, "Russian");

    cout << "СОРТИРОВКА СТУДЕНТОВ ПО АЛФАВИТУ" << endl;
    cout << "================================" << endl;

    int count;
    cout << "Сколько студентов в группе? ";
    cin >> count;
    cin.ignore(); // очищаем буфер

    Student* students = new Student[count];

    // Ввод данных о студентах
    cout << "\nВведите данные о студентах:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\nСтудент " << i + 1 << ":" << endl;
        cout << "Фамилия: ";
        cin.getline(students[i].surname, 50);
        cout << "Имя: ";
        cin.getline(students[i].name, 50);
        cout << "Группа: ";
        cin >> students[i].group;
        cin.ignore(); // очищаем буфер после ввода числа
    }

    // Вывод исходного списка
    cout << "\nИсходный список:" << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < count; i++) {
        setlocale(LC_ALL, "Russian");
        cout << students[i].surname << " " << students[i].name
            << " - группа " << students[i].group << endl;
    }

    // Сортировка с помощью qsort
    qsort(students, count, sizeof(Student), compare);

    // Вывод отсортированного списка
    cout << "\nОтсортированный список:" << endl;
    cout << "----------------------" << endl;
    for (int i = 0; i < count; i++) {
        cout << students[i].surname << " " << students[i].name
            << " - группа " << students[i].group << endl;
    }

    delete[] students;
    return 0;
}