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
        {"������", "�������"},
        {"������", "����"},
        {"�������", "�������"},
        {"�������", "�������"},
        {"���������", "�����"},
    };
    cout << "�������� ������:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i].lastName << " " << students[i].firstName << "\n";
    }
    qsort(students, count, sizeof(Student), compareStudents);
    cout << "��������������� ������:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i].lastName << " " << students[i].firstName << "\n";
    }
}