#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Box {
    int weight, capacity;
};

bool compare(Box a, Box b) {
    return a.weight < b.weight;
}

int main() {
    setlocale(LC_ALL, "RU");


    srand(time(nullptr));

    // Генерация случайного количества коробок от 0 до 1000
    int n = rand() % 1001;  // Случайное количество коробок от 0 до 1000
    cout << "Количество коробок: " << n << endl;

    if (n == 0) {
        cout << "Нет коробок, программа завершена." << endl;
        return 0;
    }

    vector<Box> boxes(n);

    // Генерация случайных весов и грузоподъемности коробок
    for (int i = 0; i < n; i++) {
        boxes[i].weight = 1 + rand() % 100; // вес от 1 до 100
        boxes[i].capacity = 1 + rand() % 1000; // максимальная нагрузка от 1 до 1000
        cout << "Коробка " << i + 1 << ": вес = " << boxes[i].weight << ", грузоподъемность = " << boxes[i].capacity << endl;
    }

    // Сортировка коробок по весу
    sort(boxes.begin(), boxes.end(), compare);

    // Динамическое программирование для нахождения максимальной последовательности коробок
    vector<long long> dp(n, 0);
    dp[0] = boxes[0].weight;

    for (int i = 1; i < n; i++) {
        dp[i] = boxes[i].weight;  // Минимальный вес для коробки
        for (int j = 0; j < i; j++) {
            if (dp[j] + boxes[i].weight <= boxes[i].capacity) {
                dp[i] = max(dp[i], dp[j] + boxes[i].weight);
            }
        }
    }

    long long max_weight = 0;
    for (int i = 0; i < n; i++) {
        max_weight = max(max_weight, dp[i]);
    }

    cout << "Максимальный вес коробок, которые можно сложить: " << max_weight << endl;

    return 0;
}
