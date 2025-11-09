#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    cout << "Количество коробок (1 <= n <= 10^5): ";
    cin >> n;
    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Вес " << i + 1 << " коробки (1 <= w <= 10^5 ) и вес, который она может выдержать (1 <= c <= 10^9 ): ";
        cin >> boxes[i].first >> boxes[i].second;
    }
    sort(boxes.begin(), boxes.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return (a.first + a.second) < (b.first + b.second);
        });
    long long current_weight = 0;
    int count = 0;
    for (const auto& box : boxes)
    {
        if (current_weight <= box.second)
        {
            count++;
            current_weight += box.first;
        }
    }
    cout << "Наибольшее количество коробок " << count;
}