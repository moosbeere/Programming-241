#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <set>


int getMinNode(std::map<int, int> nodes, std::set<int> processed);

int main()
{
    std::ifstream in("input2.txt");
    int cntTowns;
    std::map<int, int> gasolineCost;
    in >> cntTowns;
    for (int i = 1; i <= cntTowns; ++i)
    {
        int cost;
        in >> cost;
        gasolineCost[i] = cost;
    }
    int cntRoads;
    in >> cntRoads;
    std::map<int, std::map<int, int>> graph;
    for (int i = 0; i < cntRoads; ++i)
    {
        int t1, t2;
        in >> t1 >> t2;
        /* counting starts from 1 */
        t1;
        t2;
        graph[t1][t2] = gasolineCost[t1];
        graph[t2][t1] = gasolineCost[t2];
    }

    std::set<int> proccesed;
    std::map<int, int> nodes;
    nodes[1] = 0;

    while (getMinNode(nodes, proccesed) != -1)
    {
        char town = getMinNode(nodes, proccesed);
        int cost = nodes[town];
        for (auto town2: graph[town])
        {
            if (!nodes.count(town2.first) || (cost + town2.second < nodes[town2.first]))
            {
                nodes[town2.first] = cost + town2.second;
            }
        }
        proccesed.insert(town);
        
    }
    int lastTown = cntTowns;
    std::cout << ((nodes.count(lastTown)) ? nodes[lastTown] : -1);
    
}

int getMinNode(std::map<int, int> nodes, std::set<int> processed)
{
    int minRib = INT_MAX;
    int minPeak = -1;
    for (const auto n: nodes)
    {
        if (!processed.count(n.first) && n.second < minRib)
        {
            minPeak = n.first;
            minRib = n.second;
        }
    }
    return minPeak;
}