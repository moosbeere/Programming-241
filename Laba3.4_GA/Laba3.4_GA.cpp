#include <iostream>
#include <string>    
#include <algorithm> 
using namespace std;

struct Student {
    string name;
};

int main() {
    setlocale(LC_ALL, "ru");
    Student students[] = {
        {"Иванов"},
        {"Петров"},
        {"Сидоров"},
        {"Абрамов"},
        {"Николаев"},
        {"Балашов"}
    };

    const int numStudents = sizeof(students) / sizeof(students[0]);

    cout << "Список студентов до сортировки:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << students[i].name << endl;
    }


    std::sort(students, students + numStudents, [](const Student& a, const Student& b) {
        return a.name < b.name;
        });

    cout << "\nСписок студентов после сортировки:" << endl;
    for (int i = 0; i < numStudents; ++i) {
        cout << students[i].name << endl;
    }

    return 0;
}
