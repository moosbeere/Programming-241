#include <iostream>
#include <vector>
#include <algorithm>
#include <locale> // Для работы с локалью

struct Lecture {
    int start;
    int finish;
};

// Функция для сортировки лекций по времени окончания
bool compareByFinish(const Lecture& a, const Lecture& b) {
    return a.finish < b.finish;
}

int main() {
    // Установка локали для консоли (русский язык)
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    int N;
    std::wcout << L"Введите количество заявок: ";
    std::wcin >> N;

    std::vector<Lecture> lectures(N);
    std::wcout << L"Введите " << N << L" заявок (время начала и окончания каждой лекции):\n";
    for (int i = 0; i < N; ++i) {
        std::wcin >> lectures[i].start >> lectures[i].finish;
    }

    // Сортируем по времени окончания
    std::sort(lectures.begin(), lectures.end(), compareByFinish);

    int count = 0;
    int lastFinish = 0; // Время окончания последней выбранной лекции

    for (const auto& lec : lectures) {
        if (lec.start >= lastFinish) {
            ++count;
            lastFinish = lec.finish;
        }
    }

    std::wcout << L"Максимальное количество заявок, которые можно выполнить: " << count << L"\n";

    return 0;
}
