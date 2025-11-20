#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPair(vector<pair<int, int>>& vec) {
    for (auto elem : vec) {
        cout << elem.first << " " << elem.second << endl;
    }
}

bool compTime(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int N;
    cout << "Введите количество заявок: ";
    cin >> N;
    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    sort(lectures.begin(), lectures.end(), compTime);
     printPair(lectures);
    int count = 0;
    int curr_end = 0;
    for (auto elem : lectures) {
        if (elem.first >= curr_end) {
            count++;
            curr_end = elem.second;
        }
    }
    cout << "Максимальное количество заявок, которые можно выполнить: " << count;
}



//boxes
//void printArr(vector<pair<int, int>>& vec) {
//    for (auto elem : vec) {
//        cout << elem.first << " " << elem.second << endl;
//    }
//}
//
//bool compWeight(pair<int, int>& a, pair<int, int>& b) {
//    return a.first + a.second < b.first + b.second;
//}
//
//int main()
//{
//    /*setlocale(LC_ALL, "Ru");*/
//    int n;
//    cout << "Введите количество коробок: ";
//    cin >> n;
//    vector<pair<int, int>> presents(n);
//    for (int i = 0; i < n; i++) {
//        cin >> presents[i].first >> presents[i].second;
//    }
//    sort(presents.begin(), presents.end(), compWeight);
//     printArr(presents);
//    int total = 0;
//    int count = 0;
//    for (auto elem : presents) {
//        if (total <= elem.second) {
//            count++;
//            total += elem.first;
//        }
//    }
//    cout << "Количество сложенных друг на друга коробок: " << count;
//}