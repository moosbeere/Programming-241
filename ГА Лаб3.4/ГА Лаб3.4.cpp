#include <iostream>
#include <cstring>

using namespace std;

int f(const void* a, const void* b) {
    const char* nameA = *(const char**)a;
    const char* nameB = *(const char**)b;
    return strcmp(nameA, nameB);
}

int main() {
    setlocale(LC_ALL, "RU");
    const char* students[] = {
        "Бекетов",
        "Вилла",
        "Бондаренко",
        "Колупаева",
        "Лисьева",
        "Мацюшевский",
        "Назаров",
        "Обидов",
        "Петров",
        "Сагна"
    };

    int n = sizeof(students) / sizeof(students[0]);

    cout << "Список студентов до сортировки:\n";
    for (int i = 0; i < n; ++i) {
        cout << students[i] << endl;
    }

    qsort(students, n, sizeof(const char*), f);

    cout << "\nСписок студентов после сортировки:\n";
    for (int i = 0; i < n; ++i) {
        cout << students[i] << endl;
    }

    return 0;
}
