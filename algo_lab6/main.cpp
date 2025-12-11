#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>



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
    std::map<char, char> parents = { {'B', 'A'}, {'D', 'A'} };
    std::map<char, int> costs = { {'B', 5}, {'D', 2}, {'F', INT_MAX} };
    std::map<char, std::map<char, int>> graph = {
        {'A', {{'B', 5}, {'D', 2}}}, {'B', {{'E', 2}, {'C', 4}}},
        {'D', {{'B', 8}, {'E', 7}}}, {'E', {{'F', 1}}}, {'C', {{'F', 3}, {'E', 6}}}
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
    char fin = 'F';
    std::cout << "F:";
    while (parents.count(fin))
    {
        std::cout << parents[fin] << ' ';
        fin = parents[fin];
    }
}