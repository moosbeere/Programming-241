// Dejkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;

string find_lowest_cost_node(unordered_map<string, int> costs, vector<string> processed);
bool node_not_is_processed(vector<string> processed, string usel);

int main()
{
    unordered_map<string, unordered_map<string, int>> graph;
    graph["start"] = {};
    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;
    graph["a"] = {};
    graph["a"]["fin"] = 1;
    graph["b"] = {};
    graph["b"]["fin"] = 5;
    graph["b"]["a"] = 3;
    graph["fin"] = {};

    unordered_map<string, int> costs = {};
    int inf = numeric_limits<int>::max();
    costs["a"] = 6;
    costs["b"] = 2;
    costs["fin"] = inf;

    unordered_map<string, string> parents = {};
    parents["a"] = "start";
    parents["b"] = "start";
    parents["fin"] = "";

    vector<string> processed = {};

    string node = find_lowest_cost_node(costs, processed);
    while (!node.empty()) {
        int cost = costs[node];
        unordered_map<string, int> neighbors = graph[node];
        for (auto& elem : neighbors) {
            int new_cost = cost + elem.second;
            if (costs[elem.first] > new_cost) {
                costs[elem.first] = new_cost;
                parents[elem.first] = node;
            }
        }
        processed.push_back(node);
        node = find_lowest_cost_node(costs, processed);
    }

    for (auto& elem : parents) {
        cout << elem.first << " " << elem.second << endl;
    }
}


string find_lowest_cost_node(unordered_map<string, int> costs, vector<string> processed)
{
    int inf = numeric_limits<int>::max();
    int lower_cost = inf;
    string lower_cost_node = "";
    for (auto& elem : costs) {
        int cost = elem.second;
        if (cost < lower_cost && node_not_is_processed(processed, elem.first)) {
            lower_cost = cost;
            lower_cost_node = elem.first;
        }
    }
    return lower_cost_node;
}

bool node_not_is_processed(vector<string> processed, string usel)
{
    for (auto elem : processed) {
        if (elem == usel) return false;
    }
    return true;
}
