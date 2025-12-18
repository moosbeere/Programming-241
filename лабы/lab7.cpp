#include <iostream>
#include <vector>
#include <algorithm>

// Решение задачи о максимальном количестве непересекающихся лекций (жадный алгоритм)
// Находит максимальное количество лекций, которые можно посетить без пересечений
// Входные данные:
//   N - количество лекций
//   Для каждой лекции: время начала и время окончания
// Алгоритм:
//   1. Сортирует лекции по времени окончания (раньше заканчивающиеся - первыми)
//   2. Жадный выбор: выбирает лекцию, если она начинается не раньше окончания последней выбранной
//   Это оптимальное решение, так как выбор лекции с ранним окончанием оставляет больше времени
//   для последующих лекций
int main()
{
    // Структура для представления лекции
    // Содержит время начала и окончания лекции
    struct Lecture
    {
        int m_start;  // Время начала лекции
        int m_end;    // Время окончания лекции
    };

    // Лямбда-функция для сравнения лекций при сортировке
    // Сравнивает лекции по времени окончания (m_end)
    // Возвращает true, если первая лекция заканчивается раньше второй
    // Используется для сортировки лекций по возрастанию времени окончания
    const auto compare_lectures = [](const Lecture& a, const Lecture& b) -> bool {
        return a.m_end < b.m_end;
    };

    int N = 0;
    std::cin >> N;

    std::vector<Lecture> lectures(N);
    for (auto& lecture : lectures)
        std::cin >> lecture.m_start >> lecture.m_end;

    std::sort(lectures.begin(), lectures.end(), compare_lectures);

    int count = 0;
    int last = 0;

    for (auto& lecture : lectures)
    {
        if (lecture.m_start >= last)
        {
            count++;
            last = lecture.m_end;
        }
    }

    std::cout << count << std::endl;

    return 0;
}

// Решение задачи о максимальной высоте стопки коробок (динамическое программирование)
// Находит максимальное количество коробок, которые можно сложить в стопку
// Условие: вес всех коробок выше текущей не должен превышать грузоподъемность текущей коробки
// Входные данные:
//   N - количество коробок
//   Для каждой коробки: вес (m_weight) и грузоподъемность (m_capacity)
// Алгоритм:
//   1. Сортирует коробки по сумме веса и грузоподъемности, затем по грузоподъемности
//   2. Использует динамическое программирование:
//      box_stack[j] - минимальный общий вес стопки из j коробок
//   3. Для каждой коробки проверяет, можно ли добавить её к существующим стопкам
//   4. Выводит максимальное количество коробок, которые можно сложить
int task_bulb_bulb()
{
    // Структура для представления коробки
    // Содержит вес коробки и её грузоподъемность (максимальный вес, который она может выдержать сверху)
    struct Box 
    {
        int m_weight;    // Вес коробки
        int m_capacity;  // Грузоподъемность коробки (максимальный вес, который можно положить сверху)
    };

    // Лямбда-функция для сравнения коробок при сортировке
    // Сначала сравнивает по сумме веса и грузоподъемности (m_weight + m_capacity)
    // Если суммы равны, сравнивает по грузоподъемности (m_capacity)
    // Возвращает true, если первая коробка должна идти раньше второй
    // Используется для сортировки коробок в оптимальном порядке
    const auto compare_boxes = [](const Box& a, const Box& b) -> bool {
        if (a.m_weight + a.m_capacity != b.m_weight + b.m_capacity)
            return a.m_weight + a.m_capacity < b.m_weight + b.m_capacity;

        return a.m_capacity < b.m_capacity;
    };

    int N = 0;
    std::cin >> N;

    std::vector<Box> boxes(N);
    for (auto& box : boxes)
        std::cin >> box.m_weight >> box.m_capacity;

    std::sort(boxes.begin(), boxes.end(), compare_boxes);

    std::vector<long long> box_stack(N + 1, std::numeric_limits<long long>::max());
    box_stack[0] = 0;

    int max_boxes = 0;

    for (const auto& box : boxes)
    {
        for (int j = max_boxes; j >= 0; j--) 
        {
            if (box_stack[j] != std::numeric_limits<long long>::max() 
                && box_stack[j] <= box.m_capacity)
            {
                if (box_stack[j + 1] > box_stack[j] + box.m_weight)
                {
                    box_stack[j + 1] = box_stack[j] + box.m_weight;
                    max_boxes = std::max(max_boxes, j + 1);
                }
            }
        }
    }

    std::cout << max_boxes << std::endl;

    return 0;
}