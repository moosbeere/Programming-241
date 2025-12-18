#include <iostream>
#include <vector>
#include <map>
#include <queue>

// Главная функция для поиска кратчайшего пути в графе методом BFS (поиск в ширину)
// Реализует алгоритм поиска пути от начальной вершины 'S' до конечной 'I'
// в графе комнат, представленном как список смежности
// Алгоритм:
//   1. Создает граф связей между комнатами
//   2. Использует очередь для обхода графа в ширину
//   3. Отслеживает посещенные вершины и родителей для восстановления пути
//   4. Восстанавливает и выводит кратчайший путь от start до finish
int main() 
{
    std::setlocale(LC_ALL, "Russian");

    std::map<char, std::vector<char>> full_path {};
    full_path['S'] = { 'A', 'B' };
    full_path['A'] = { 'S' };
    full_path['B'] = { 'S', 'C', 'D' };
    full_path['C'] = { 'B', 'J' };
    full_path['D'] = { 'B', 'E' };
    full_path['E'] = { 'D', 'G' };
    full_path['F'] = { 'G' };
    full_path['G'] = { 'E', 'H' };
    full_path['H'] = { 'G', 'I' };
    full_path['I'] = { 'H', 'J' };
    full_path['J'] = { 'C', 'I' };

    char start = 'S';
    char finish = 'I';

    std::queue<char> path_queue {};
    std::map<char, bool> used {};
    std::map<char, char> parent {};

    path_queue.push(start);
    used[start] = true;
    parent[start] = 0;

    while (!path_queue.empty())
    {
        char next_room = path_queue.front();
        path_queue.pop();

        for (char room : full_path[next_room]) 
        {
            if (!used[room])
            {
                used[room] = true;
                parent[room] = next_room;
                path_queue.push(room);
            }
        }
    }

    if (!used[finish]) 
    {
        std::cout << " " << std::endl;
        return 0;
    }

    std::vector<char> path {};
    for (char v = finish; v != 0; v = parent[v])
        path.push_back(v);

    std::reverse(path.begin(), path.end());

    std::cout << "  - " << path.size() - 1 << std::endl;

    for (int i = 0; i < path.size(); ++i) 
    {
        std::cout << path[i];

        if (i + 1 != path.size())
            std::cout << " -> ";
    }
}

