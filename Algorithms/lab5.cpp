#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

vector<string> findShortestPath(const unordered_map<string, vector<string>>& maze,
    const string& start, const string& end)
{
    queue<pair<string, vector<string>>> q;
    unordered_set<string> visited;
    vector<string> initialPath = { start };
    q.push(make_pair(start, initialPath));
    visited.insert(start);

    while (!q.empty())
    {
        pair<string, vector<string>> current = q.front();
        q.pop();

        string currentRoom = current.first;
        vector<string> path = current.second;
        if (currentRoom == end)
        {
            return path;
        }
        auto it = maze.find(currentRoom);
        if (it != maze.end())
        {
            for (const string& neighbor : it->second)
            {
                if (visited.find(neighbor) == visited.end())
                {
                    visited.insert(neighbor);
                    vector<string> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(make_pair(neighbor, newPath));
                }
            }
        }
    }
    return {};
}

int main()
{
    setlocale(LC_ALL, "ru");

    unordered_map<string, vector<string>> maze = {
        {"S", {"A", "E", "D", "B"}},
        {"A", {"S"}},
        {"B", {"S", "D", "C"}},
        {"C", {"B", "J"}},
        {"D", {"S", "B", "G"}},
        {"E", {"S", "G"}},
        {"F", {"G", "H"}},
        {"G", {"F", "H", "J", "D", "E"}},
        {"H", {"F", "I", "G"}},
        {"I", {"H", "J"}},
        {"J", {"C", "G", "I"}}
    };

    vector<string> path = findShortestPath(maze, "S", "I");
    cout << "Кратчайший путь из S в I: ";
    for (const string& room : path)
    {
        cout << room << " ";
    }
    cout << endl;
    cout << "Длина: " << path.size() - 1 << " шагов \n";
}