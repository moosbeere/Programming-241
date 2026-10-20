// Greedy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    set<string> states_needed = {"ut", "nv", "wa", "mt", "or", "ca", "az", "id"};
    unordered_map<string, set<string>> stations = {};
    stations["kone"] = { "id", "nv", "ut" };
    stations["ktwo"] = { "wa", "id", "mt" };
    stations["kthree"] = {"or", "nv", "ca"};
    stations["kfour"] = { "nv", "ut" };
    stations["kfive"] = { "ca", "az"};
    set<string> final_stations = {};

    while (!empty(states_needed)) {
        string best_statios = "";
        set<string> states_covered = {};
        for (auto& states_for_station : stations) {
            set <string> covered = {};
            set_intersection(states_needed.begin(), states_needed.end(),
                states_for_station.second.begin(), states_for_station.second.end(),
                inserter(covered, covered.begin()));
            if (covered.size() > states_covered.size()) {
                best_statios = states_for_station.first;
                states_covered = covered;
            }
        }
        for (auto& elem : states_covered) {
            states_needed.erase(elem);
        }
        final_stations.insert(best_statios);
    }
    for (auto& elem : final_stations) {
        cout << elem << ", ";
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
