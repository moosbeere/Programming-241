#include <iostream>
#include <vector>
#include <climits>

// Реализация алгоритма Дейкстры для поиска кратчайшего пути в графе
// Находит минимальное расстояние от вершины S до вершины F
// Входные данные:
//   N - количество вершин в графе
//   S - начальная вершина (1-индексированная, преобразуется в 0-индексированную)
//   F - конечная вершина (1-индексированная, преобразуется в 0-индексированную)
//   graph - матрица смежности NxN, где graph[i][j] - вес ребра от i к j (-1 если ребра нет)
// Алгоритм:
//   1. Инициализирует расстояния до всех вершин как бесконечность, кроме начальной (0)
//   2. На каждой итерации выбирает непосещенную вершину с минимальным расстоянием
//   3. Обновляет расстояния до соседних вершин
//   4. Выводит кратчайшее расстояние до F или -1, если путь не существует
int djekstra_1() 
{
    int N = 0;
    int S = 0;
    int F = 0;

    std::cin >> N >> S >> F;
    S--;
    F--;

    std::vector<std::vector<int>> graph(N, std::vector<int>(N));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            std::cin >> graph[i][j];
    }

    std::vector<int> destination(N, std::numeric_limits<int>::max());
    std::vector<bool> visited(N, false);

    destination[S] = 0;

    for (int i = 0; i < N; i++) 
    {
        int min_distance = std::numeric_limits<int>::max();
        int u = -1;
        for (int j = 0; j < N; j++) 
        {
            if (!visited[j] && destination[j] < min_distance) 
            {
                min_distance = destination[j];
                u = j;
            }
        }

        if (u == -1 || min_distance == std::numeric_limits<int>::max())
            break;

        visited[u] = true;

        for (int v = 0; v < N; v++)
        {
            if (graph[u][v] != -1 && !visited[v])
            {
                int new_distance = destination[u] + graph[u][v];

                if (new_distance < destination[v])
                    destination[v] = new_distance;
            }
        }
    }

    if (destination[F] == std::numeric_limits<int>::max())
        std::cout << -1 << std::endl;
    else
        std::cout << destination[F] << std::endl;

    return 0;
}

// Модифицированный алгоритм Дейкстры для задачи о заправке
// Находит минимальную стоимость пути от города 0 до города N-1
// с учетом стоимости заправки в каждом городе и ограниченного запаса топлива
// Входные данные:
//   N - количество городов
//   cost[i] - стоимость заправки одной единицы топлива в городе i
//   M - количество дорог
//   u, v - пары городов, соединенных дорогами (дороги двусторонние)
// Алгоритм:
//   Использует динамическое программирование: distance[city][fuel] - минимальная стоимость
//   достижения города city с fuel единицами топлива
//   Обновляет расстояния для двух операций:
//     1. Заправка в текущем городе (увеличивает топливо на 1)
//     2. Переезд в соседний город (уменьшает топливо на 1)
//   Выводит минимальную стоимость достижения последнего города или -1, если невозможно
int djekstra_2()
{
    int N = 0;
    std::cin >> N;

    std::vector<int> cost(N);
    for (int i = 0; i < N; i++)
        std::cin >> cost[i];

    int M = 0;
    std::cin >> M;

    std::vector<std::vector<int>> cities(N);
    for (int i = 0; i < M; i++) 
    {
        int u = 0;
        int v = 0;

        std::cin >> u >> v;
        u--; v--;
        
        cities[u].push_back(v);
        cities[v].push_back(u); 
    }

    std::vector<std::vector<int>> distance(N, std::vector<int>(N, std::numeric_limits<int>::max()));
    std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));

    distance[0][0] = 0;

    bool updated;
    do {
        updated = false;

        for (int city = 0; city < N; city++) 
        {
            for (int fuel = 0; fuel < N; fuel++) 
            {
                if (distance[city][fuel] == std::numeric_limits<int>::max())
                    continue;

                if (fuel + 1 < N) 
                {
                    int newCost = distance[city][fuel] + cost[city];

                    if (newCost < distance[city][fuel + 1])
                    {
                        distance[city][fuel + 1] = newCost;
                        updated = true;
                    }
                }

                if (fuel > 0) 
                {
                    for (int neighbor : cities[city]) 
                    {
                        int new_cost = distance[city][fuel];

                        if (new_cost < distance[neighbor][fuel - 1]) 
                        {
                            distance[neighbor][fuel - 1] = new_cost;
                            updated = true;
                        }
                    }
                }
            }
        }
    } while (updated);

    int min_cost = std::numeric_limits<int>::max();
    for (int fuel = 0; fuel < N; fuel++)
    {
        if (distance[N - 1][fuel] < min_cost)
            min_cost = distance[N - 1][fuel];
    }

    if (min_cost == std::numeric_limits<int>::max())
        std::cout << -1 << std::endl;
    else
        std::cout << min_cost << std::endl;

    return 0;
}

