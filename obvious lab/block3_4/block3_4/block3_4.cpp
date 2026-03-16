#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "vehicle.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    vector<Vehicle> lst;

    for (int i = 0; i < 4; ++i) {
        string b;
        int maxS;

        cout << "Введите название машины " << i + 1 << ": ";
        cin >> b;
        cout << "Введите максимальную скорость: ";
        cin >> maxS;

        lst.push_back(Vehicle(b, maxS));
        cout << endl;
    }


    sort(lst.begin(), lst.end());

    cout <<"МАШИНЫ, ОТСОРТИРОВАННЫЕ ПО СКОРОСТИ \n" << endl;
    for (const auto& elem : lst) {
        elem.getStatus();
    }

    return 0;
}