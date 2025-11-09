#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int N;
    cout << "Количество заявок лекции (1 <= N <= 1000): ";
    cin >> N;
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++)
    {
        cout << "Время начала и конца " << i + 1 << " лекции (в минутах с начала суток): ";
        cin >> lectures[i].first >> lectures[i].second;
    }
    sort(lectures.begin(), lectures.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.second < b.second;
        });

    int count = 0;
    int last_end = 0;
    for (const auto& lecture : lectures)
    {
        if (lecture.first >= last_end)
        {
            count++;
            last_end = lecture.second;
        }
    }
    cout << "Максимальное количество заявок, которые можно выполнить: " << count;
}