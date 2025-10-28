#include <iostream>
using namespace std;

struct Student {
    char lastName[50];
    char firstName[50];
};

int compareStudents(const void* a, const void* b) {
    const Student* studentA = (const Student*)a;
    const Student* studentB = (const Student*)b;
    int lastNameCompare = strcmp(studentA->lastName, studentB->lastName);
    if (lastNameCompare != 0) {
        return lastNameCompare;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int count = 5;
    Student students[count] = {
        {"Иванов", "Алексей"},
        {"Петров", "Иван"},
        {"Сидоров", "Алексей"},
        {"Валишин", "Алексей"},
        {"Кузнецова", "Мария"},
    };
    cout << "Исходный список:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i].lastName << " " << students[i].firstName << "\n";
    }
    qsort(students, count, sizeof(Student), compareStudents);
    cout << "Отсортированный список:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i].lastName << " " << students[i].firstName << "\n";
    }
}