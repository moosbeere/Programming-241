#include <iostream>
#include <random>
#include "quickSort.cpp"


int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(50, 100);
    int size = 25;
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = dist(gen);
        std::cout << vec[i] << ' ';
    }
    vec = quickSort(vec);
    std::cout << std::endl;
    for (auto& i: vec) std::cout << i << ' ';
}