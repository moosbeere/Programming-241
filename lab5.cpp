#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Функция для восстановления пути по предкам
vector<char> reconstruct_path(unordered_map<char, char>& came_from, char start, char goal) {
    vector<char> path;
    char current = goal;

    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start);

    reverse(path.begin(), path.end());
    return path;
}

// Функция BFS для поиска кратчайшего пути
vector<char> bfs_maze(char start, char goal) {
    // Граф лабиринта (соседние комнаты)
    unordered_map<char, vector<char>> maze = {
        {'S', {'A', 'B'}},
        {'A', {'S'}},
        {'B', {'S', 'C', 'E'}},
        {'C', {'B', 'D', 'J'}},
        {'D', {'C', 'G'}},
        {'E', {'B', 'F'}},
        {'F', {'E', 'G'}},
        {'G', {'D', 'F', 'H'}},
        {'H', {'G', 'I'}},
        {'I', {'H', 'J'}},
        {'J', {'C', 'I'}}
    };

    // Очередь для BFS
    queue<char> frontier;
    frontier.push(start);

    // Множество посещенных вершин
    unordered_set<char> visited;
    visited.insert(start);

    // Для восстановления пути (откуда пришли в каждую вершину)
    unordered_map<char, char> came_from;
    came_from[start] = start;

    while (!frontier.empty()) {
        char current = frontier.front();
        frontier.pop();

        // Если достигли цели
        if (current == goal) {
            return reconstruct_path(came_from, start, goal);
        }

        // Проверяем всех соседей
        for (char neighbor : maze[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                came_from[neighbor] = current;
                frontier.push(neighbor);
            }
        }
    }

    // Если путь не найден, возвращаем пустой вектор
    return {};
}

int main() {
    setlocale(LC_ALL, "RU");
    char start = 'S';
    char goal = 'I';

    vector<char> path = bfs_maze(start, goal);

    if (!path.empty()) {
        cout << "Кратчайший путь из '" << start << "' в '" << goal << "':" << endl;
        cout << "Длина пути: " << path.size() - 1 << " шагов" << endl;
        cout << "Маршрут: ";

        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else {
        cout << "Путь не найден!" << endl;
    }

    return 0;
}