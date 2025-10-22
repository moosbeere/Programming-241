#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Задача 1: Расписание лекций
int maxLectures(vector<pair<int, int>>& lectures) {
    // Сортируем по времени окончания
    sort(lectures.begin(), lectures.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    
    int count = 0;
    int lastEnd = 0;
    
    for (int i = 0; i < lectures.size(); i++) {
        if (lectures[i].first >= lastEnd) {
            count++;
            lastEnd = lectures[i].second;
        }
    }
    
    return count;
}

// Задача 2: Укладка коробок
int maxBoxes(vector<pair<int, int>>& boxes) {
    // Сортируем по сумме веса и грузоподъемности
    sort(boxes.begin(), boxes.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.first + a.second) < (b.first + b.second);
    });
    
    int count = 0;
    int totalWeight = 0;
    
    for (int i = 0; i < boxes.size(); i++) {
        if (totalWeight <= boxes[i].second) {
            count++;
            totalWeight += boxes[i].first;
        }
    }
    
    return count;
}

int main() {
    cout << "Задача 1: Расписание лекций" << endl;
    
    // Пример для задачи 1
    vector<pair<int, int>> lectures;
    lectures.push_back(make_pair(1, 3));
    lectures.push_back(make_pair(2, 5));
    lectures.push_back(make_pair(3, 6));
    lectures.push_back(make_pair(4, 7));
    lectures.push_back(make_pair(6, 8));
    
    int result1 = maxLectures(lectures);
    cout << "Максимум лекций: " << result1 << endl;
    
    cout << "\nЗадача 2: Коробки" << endl;
    
    // Пример для задачи 2
    vector<pair<int, int>> boxes;
    boxes.push_back(make_pair(10, 20)); // вес, грузоподъемность
    boxes.push_back(make_pair(5, 15));
    boxes.push_back(make_pair(8, 12));
    boxes.push_back(make_pair(3, 25));
    
    int result2 = maxBoxes(boxes);
    cout << "Максимум коробок: " << result2 << endl;
    
    return 0;
}
