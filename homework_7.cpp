#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    struct Lecture
    {
        int m_start;
        int m_end;
    };

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

int task_bulb_bulb()
{
    struct Box 
    {
        int m_weight;
        int m_capacity;
    };

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