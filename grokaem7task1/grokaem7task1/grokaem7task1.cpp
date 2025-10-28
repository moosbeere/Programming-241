#include <iostream>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);

    for (int i = 0; i < N; i++) {
        cin >> lectures[i].second >> lectures[i].first; // (окончание, начало)
    }

    // Сортируем лекции по времени окончания
    sort(lectures.begin(), lectures.end());

    int count = 0;
    int last_end = -1; // время окончания последней выбранной лекции

    for (int i = 0; i < N; i++) {
        int start = lectures[i].second;
        int end = lectures[i].first;

        // Если текущая лекция начинается не раньше окончания последней выбранной
        if (start >= last_end) {
            count++;
            last_end = end;
        }
    }

    cout << count << endl;

    return 0;
}