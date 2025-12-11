#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <fstream>



char getMinNode(const std::map<char, int>& costs, const std::set<char>& processed)
{
    int lowest_cost = INT_MAX;
    char lowestCostNode = '-';
    for (auto i : costs)
    {
        int cost = i.second;
        if (!processed.count(i.first) && cost < lowest_cost)
        {
            lowest_cost = cost;
            lowestCostNode = i.first;
        }
    }
    return lowestCostNode;
}

int main()
{

    
    std::set<char> processed = {};
    std::map<char, char> parents = {};
    std::map<char, int> costs = {{'A', 0}};
    std::map<char, std::map<char, int>> graph = {
        {'A', {{'B', 10}}}, {'B', {{'C', 20}}},
        {'C', {{'D', 30}, {'E', 1}}}, {'E', {{'B', 1}}}
    };


    char lowestNode = getMinNode(costs, processed);
    while (lowestNode != '-')  // While getMinNode finding node exist otherwise it returns '-'
    {
        auto nachbars = graph[lowestNode];

        for (auto nachbar : nachbars)
        {
            auto node = nachbar.first;
            auto nodeCost = nachbar.second;
            int current_cost = (costs.count(node)) ? costs[node] : INT_MAX;
            int cost = costs[lowestNode] + nodeCost;
            if (cost < current_cost)
            {
                costs[node] = cost;
                parents[node] = lowestNode;
            }


        }
        processed.insert(lowestNode);
        lowestNode = getMinNode(costs, processed);
    }
    char fin = 'D';
    std::cout << "D: " << costs[fin] << ' ';
    while (parents.count(fin))
    {
        std::cout << parents[fin] << ' ';
        fin = parents[fin];
    }
}