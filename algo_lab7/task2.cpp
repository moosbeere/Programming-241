#include <deque>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

 /* algorithm: first take a box with max load capacity and weight, then put on it boxes in order with max capacity and minimum weight  */
int main()
{
    std::ifstream in("input2.txt");
    int n;
    in >> n;
    std::deque<std::pair<int, int>> boxes(n);  // 1st = self weight, 2nd = Load capacity
    for (int i = 0; i < n; ++i)
    {
        int weight, holdedWeight;
        in >> weight >> holdedWeight;
        boxes[i] = std::make_pair(weight, holdedWeight);
    }
    std::map<int, int> loaded; // here are capacities 3of each boxes

    auto maxSecond = std::max_element(boxes.begin(), boxes.end(),
        [](const auto& a, const auto& b) {
            return ((a.second == b.second) ? a.first < b.first : a.second < b.second);
        });
    
    std::cout << maxSecond->first << ' ' << maxSecond->second << std::endl;
    std::pair<int, int> box = *maxSecond;

    boxes.erase(maxSecond);

    std::sort(boxes.begin(), boxes.end(), [](std::pair<int, int> a, std::pair<int, int> b){
        return (((a.second - a.first) > (b.second - b.first)));
    });
    for (auto [a, b] : boxes) std::cout << a << ' ' << b << std::endl;

    int currentCapacity = box.second;
    int totalCount = 1; 
    
    while (!boxes.empty())
    {
        std::pair<int, int> box = boxes.front();
        boxes.pop_front();
        while (currentCapacity < box.first && !boxes.empty()) // find 1st box we able to carry
        {
            box = boxes.front();
            boxes.pop_front();
        }
        currentCapacity = ((currentCapacity - box.first) < box.second) ? currentCapacity - box.first : box.second;
        totalCount++;
    }
    std::cout << totalCount;
}