#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Lecture {
    int start, end;
};

bool compare(Lecture a, Lecture b) {
    return a.end < b.end;
}

int main() {
    setlocale(LC_ALL, "RU");


    srand(time(nullptr));

    // Генерация случайного количества заявок от 0 до 1000
    int N = rand() % 1001;  // Случайное количество заявок от 0 до 1000
    cout << "Число заявок: " << N << endl;

    if (N == 0) {
        cout << "Нет заявок, программа завершена." << endl;
        return 0;
    }

    vector<Lecture> lectures(N);

    // Генерация случайных интервалов
    for (int i = 0; i < N; i++) {
        lectures[i].start = rand() % 1440;  // Случайное время начала (0-1439 минут)
        lectures[i].end = lectures[i].start + 1 + rand() % (1440 - lectures[i].start);  // Случайное время конца

        cout << "Заявка " << i + 1 << ": " << lectures[i].start << " - " << lectures[i].end << endl;
    }

    sort(lectures.begin(), lectures.end(), compare);

    int count = 1;
    int last_end = lectures[0].end;

    for (int i = 1; i < N; i++) {
        if (lectures[i].start >= last_end) {
            count++;
            last_end = lectures[i].end;
        }
    }

    cout << "Максимальное количество заявок, которые можно выполнить: " << count << endl;

    return 0;
}
