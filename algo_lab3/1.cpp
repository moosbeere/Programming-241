#include <vector>
#include <random>
#include <iostream>
#include "quickSort.cpp"
// std::vector<int> quickSort(std::vector<int> vec);

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 1000);
    int size = 1000;
    std::vector<int> vec(size);
    for (int i = 0; i < size; ++i)
    {
        vec[i] = dist(gen);
        std::cout << vec[i] << ' ';
    }
    vec[0] = vec[2];
    vec = quickSort(vec);
    std::cout << std::endl;
    for (auto& i: vec) std::cout << i << ' ';

    return 0;

}

