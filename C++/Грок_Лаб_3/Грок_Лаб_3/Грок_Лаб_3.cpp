#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void vectCout(vector<int> &v) {
    for (auto el : v) {
        cout << el << " ";
    }
    cout << "\n";
}

int partition(vector<int> &v, int start, int end) {
    int pivot = v[end];
    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[end]);
    return (i + 1);
}

int partition(vector<vector<int>>& v, int start, int end) {
    int pivot = v[start][0];
    int i = start;
    int j = end + 1;

    while (true) {
        do {
            i++;
        } while (i <= end && v[i][0] < pivot);
        do {
            j--;
        } while (v[j][0] > pivot);

        if (i >= j) break;
        swap(v[i], v[j]);
    }

    swap(v[start], v[j]);

    return j;
}


void quickSort(vector<int> &v, int start, int end) {
    if (start < end) {
        int n = partition(v, start, end);
        quickSort(v, start, n - 1);
        quickSort(v, n + 1, end);
    }
    else {
        return;
    }
}

void quickSort(vector<vector<int>>& v, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(v, start, end);

        quickSort(v, start, pivotIndex - 1);
        quickSort(v, pivotIndex + 1, end);
    }
    else {
        return;
    }
}


class student {
public: 
    char name[100];
};


int main() {
    setlocale(LC_ALL, "Russian");

    //Задание 1
    cout << "Задание 1\n";
    ifstream file("input.txt");
    string line;
    vector<int> v = {  };
    cout << "Содержимое файла: \n";
    while(getline(file, line)) {
        v.push_back(stoi(line));
    }

    cout << "Изначальный вектор:\n";
    vectCout(v);

    int n = v.size();
    quickSort(v, 0, n - 1);

    cout << "\nОтсортированный вектор:\n";
    vectCout(v);

    //Задание 2
    cout << "\n\nЗадание 2\n";
    srand(time(NULL));
    v.clear();
    for (int i = 0; i < 100; i++) {
        v.push_back(50 + rand() % 51);
    }
    cout << "Изначальный вектор:\n";
    vectCout(v);

    n = v.size();
    quickSort(v, 0, n - 1);

    cout << "\nОтсортированный вектор:\n";
    vectCout(v);

    //Задание 3
    cout << "\n\nЗадание 3\n";
    vector<vector<int> > vec(100, vector <int>(5));

    cout << "Изначальный вектор:\n";
    for (int i = 0; i < 100; i++) {
        cout << " [ ";
        for (int j = 0; j < 5; j++) {
            vec[i][j] = 5 + rand() % 56;
            cout << vec[i][j] << " ";
        }
        cout << "], ";
    }

    cout << "\nОтсортированный вектор:\n";
    quickSort(vec, 0, vec.size()-1);
    for (int i = 0; i < 100; i++) {
        cout << " [ ";
        for (int j = 0; j < 5; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "], ";
    }

    //Задание 4
    cout << "\n\nЗадание 4\n";
    student names[29] = {
     {"Богоявленская Любовь"}, {"Крутиков Фёдор"}, {"Назаров Дилшод"}, {"Бондаренко Кирилл"}, {"Пулов Артем"},
     {"Траксель Никита"}, {"Свирин Алексей"}, {"Медведев Егор"}, {"Колупаева Светлана"}, {"Сагна Пирре Марселин"},
     {"Зданович Никита"}, {"Мацюшевский Егор"}, {"Булахов Эрик"}, {"Фай Адама"}, {"Черная Ульяна"}, {"Слесаренко Элла"}, 
     {"Муньос Дмитрий"}, {"Лисьева Александра"}, {"Турков Роман"}, {"Воронов Давид"}, {"Уйсал Ясин"}, {"Петров Иван"},
     {"Яковлев Александр"}, {"Мухамедьяров Артур"}, {"Бекетов Назарий"}, {"Тошбоева Нилуфар"}, {"Степанов Виталий"},
     {"Обидов Эрадж"}, {"Чиканчи Дарья"}
    };

    cout << "Изначальный вектор:\n";
    for (auto elem : names) {
        cout << "[ " << elem.name << " ], ";
    }
    cout << "\n";

    cout << "\nОтсортированный вектор:\n";
    qsort(names, 29, sizeof(names[0]), [](const void* x, const void* y)
        {
            const student* studentA = (const student*)x;
            const student* studentB = (const student*)y;
            return strcmp(studentA->name, studentB->name);
        }
    );
    for (auto elem : names) {
        cout << "[ " << elem.name << " ], ";
    }
    cout << "\n";
}