#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


int main()
{
    std::ifstream in("input.txt");
    int n;
    in >> n;
    std::vector<std::pair<int, int>> vec;
    vec.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        std::string t1, t2;  // is works if Guaranted that time will be inputed in HH:MM format
        in >> t1 >> t2;
        int startTime, endTime, delIndx1, delIndx2;
        delIndx1 = t1.find(':');
        delIndx2 = t2.find(':');
        int h1 = std::stoi(t1.substr(0, delIndx1)), m1 = std::stoi(t1.substr(delIndx1 + 1, 2));
        int h2 = std::stoi(t2.substr(0, delIndx2)), m2 = std::stoi(t2.substr(delIndx2 + 1, 2));
        startTime = h1 * 60 + m1;
        endTime = h2 * 60 + m2;
        vec.emplace_back(startTime, endTime);
    }
    std::vector<std::pair<int, int>> schedule;
    int currentTime = 0;
    std::vector<std::pair<int, int>> filtered; // Put here lessons, where start > currentTime
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(filtered),
     [&](const auto& interval) { auto [start, end] = interval; return start >= currentTime;});
    while (filtered.size() != 0)
    {
        int minEndTime = INT_MAX;
        std::pair<int, int> nextLesson;
        for (const auto& lesson: vec)
        {
            if (lesson.second < minEndTime && lesson.first >= currentTime)
            {
                minEndTime = lesson.second;
                nextLesson = lesson;
            }
        }
        currentTime = nextLesson.second;
        schedule.push_back(nextLesson);
        filtered = {};
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(filtered),
     [&](const auto& interval) { auto [start, end] = interval; return start >= currentTime;});

    }
    std::cout << "Count of lessons: " << schedule.size() << std::endl; 
    for (auto [start, end]: schedule)
    {
        std::string startStr = std::to_string(start % 60);
        if (startStr.size() < 2) startStr = '0' + startStr;
        startStr = std::to_string(start / 60) + ':' + startStr;
        std::string endStr = std::to_string(end % 60);
        if (endStr.size() == 1) endStr = '0' + endStr;
        endStr = std::to_string(end / 60) + ':' + endStr;
        std::cout << startStr << ' ' << endStr << std::endl;
    }
}