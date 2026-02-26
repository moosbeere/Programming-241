#include <iostream>
#include "Vehicle.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<Vehicle>lst;
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < 4; ++i) {
        string b; int maxS;
        cout << "Введите название машины: ";
        cin >> b;
        cout << "Введите максимальную скорость: ";
        cin >> maxS;
        lst.push_back(Vehicle(b, maxS));
    }
    cout << "Массив отсортированный по возрастанию:" << endl << endl;
    sort(lst.begin(), lst.end());
    for (auto elem : lst) {
        elem.getStatus();
    }

}