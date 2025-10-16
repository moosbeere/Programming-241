#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    string name;
    Student(string s, string n) {
        surname = s;
        name = n;
    }
};

void printArr(Student arr[], int num) {
    cout << "Список студентов:" << endl;
    for (int i = 0; i < num; i++) {
        cout << arr[i].surname + " " + arr[i].name << endl;
    }
}

int compareStudents(const void* first, const void* second) {
    const Student* firstStud = (Student*)first;
    const Student* secondStud = (Student*)second;
    int comp = firstStud->surname.compare(secondStud->surname);
    if (comp != 0) return comp;
    
    return firstStud->name.compare(secondStud->name);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int s = 4;
    Student students[s] = {
        Student("Яковлев", "Александр"),
        Student("Крутиков", "Фёдор"),
        Student("Мацюшевский", "Егро"),
        Student("Мацюшевский", "Егор")
    };
    cout << "До сортировки:" << endl;
    printArr(students, s);
    
    qsort(students, s, sizeof(Student), compareStudents);
    
    cout << endl << "После сортировки:" << endl;
    printArr(students, s);

}
