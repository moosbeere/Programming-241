#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <clocale>

using namespace std;

int main()
{
    // Включаем поддержку русского языка в консоли
    setlocale(LC_ALL, "Russian");

    // Описание лабиринта в виде графа
    map<string, vector<string>> labyrinth = {
        {"S", {"A", "B"}},
        {"A", {"S", "F"}},
        {"F", {"A", "H"}},
        {"H", {"F", "G"}},
        {"G", {"H", "D"}},
        {"D", {"G", "B"}},
        {"B", {"S", "D", "C"}},
        {"C", {"B", "J"}},
        {"J", {"C", "I"}},
        {"I", {"J"}}
    };

    string start = "S";
    string exit = "I";

    queue<string> q;
    map<string, bool> visited;
    map<string, string> parent;

    q.push(start);
    visited[start] = true;

    // BFS
    while (!q.empty())
    {
        string current = q.front();
        q.pop();

        if (current == exit)
            break;

        for (const string& neighbor : labyrinth[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    // Восстановление пути
    vector<string> path;
    string step = exit;

    while (step != start)
    {
        path.push_back(step);
        step = parent[step];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    // Вывод результата
    cout << "Кратчайший путь из лабиринта:\n";
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i + 1 < path.size())
            cout << " -> ";
    }

    cout << "\nДлина пути: " << path.size() - 1 << " шагов\n";

    return 0;
}
