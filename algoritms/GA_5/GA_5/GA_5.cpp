#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    // Создание графа лабиринта
    std::unordered_map<std::string, std::vector<std::string>> graph;

    graph["S"] = { "A", "B" };
    graph["A"] = { "S", "E" };
    graph["B"] = { "S", "C", "D" };
    graph["C"] = { "B", "J" };
    graph["D"] = { "B", "F" };
    graph["E"] = { "A", "F" };
    graph["F"] = { "D", "E", "L" };
    graph["L"] = { "F", "T" };
    graph["T"] = { "L", "H" };
    graph["H"] = { "T", "I" };
    graph["J"] = { "C", "I" };
    graph["I"] = { "H", "J" };

    // Инициализация BFS
    std::queue<std::string> searchQueue;
    searchQueue.push("S");

    // Хеш-таблица для отслеживания пути
    std::unordered_map<std::string, std::string> cameFrom;
    cameFrom["S"] = "";

    // Основной цикл BFS
    while (!searchQueue.empty()) {
        std::string currentRoom = searchQueue.front();
        searchQueue.pop();

        // Проверка достижения цели
        if (currentRoom == "I") {
            break;
        }

        // Обработка соседей текущей комнаты
        std::vector<std::string> neighbors = graph[currentRoom];
        for (const std::string& neighbor : neighbors) {
            if (cameFrom.find(neighbor) == cameFrom.end()) {
                searchQueue.push(neighbor);
                cameFrom[neighbor] = currentRoom;
            }
        }
    }

    // Восстановление пути
    std::vector<std::string> path;
    std::string current = "I";

    while (current != "S") {
        path.push_back(current);
        current = cameFrom[current];
    }
    path.push_back("S");

    // Вывод результата
    std::cout << "Кратчайший путь: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        std::cout << path[i];
        if (i > 0) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    std::cout << "Длина пути: " << path.size() - 1 << std::endl;

    return 0;
}