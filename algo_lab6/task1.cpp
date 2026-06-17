#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <set>


char getMinNode(std::map<char, int> nodes, std::set<char> processed);

int main()
{
    std::ifstream in("input.txt");
    int cntVertex;
    char start, end;
    in >> cntVertex >> start >> end;

    /* Creating array with peaks in char view*/
    std::vector<char> peaks(cntVertex);
    char startChar = 'a';
    for (int i = 0; i < cntVertex; ++i)
    {
        peaks[i] = startChar + i;
    }
    /* Creating a graph */
    std::map<char, std::map<char, int>> graph;
    for (int i = 0; i < cntVertex; ++i)
    {
        std::vector<int> ribs(cntVertex);
        char peak = 'a' + i;
        for (int j = 0; j < cntVertex; ++j)
        {
            char curPeak = 'a' + j;
            int rib;
            in >> rib;
            /* Skip when rib = 0 */
            if (rib != 0) graph[peak][curPeak] = rib;
            
        }
    }

    std::set<char> proccesed;
    std::map<char, int> nodes;
    nodes[start] = 0;

    while (getMinNode(nodes, proccesed) != '-')
    {
        char node = getMinNode(nodes, proccesed);
        int cost = nodes[node];
        for (auto peak: graph[node])
        {
            if (!nodes.count(peak.first) || (cost + peak.second < nodes[peak.first]))
            {
                nodes[peak.first] = cost + peak.second;
            }
        }
        proccesed.insert(node);
        /* if we find peak = end, so we have the answer */
        if (nodes.count(end)) {
            // std::cout << nodes[end];
            break;
        }
    }
    std::cout << ((nodes.count(end)) ? nodes[end] : -1);
    
}

char getMinNode(std::map<char, int> nodes, std::set<char> processed)
{
    int minRib = INT_MAX;
    char minPeak = '-';
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