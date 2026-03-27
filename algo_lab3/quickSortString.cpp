#include <vector>
#include <random>
#include <algorithm>
#include <string>

bool is_all_iddentical(std::vector<std::string>& vec);

std::vector<std::string> quickSort(std::vector<std::string> vec)
{
    if (vec.size() <= 1) return vec;
    if (is_all_iddentical(vec)) return vec;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, vec.size() - 1);
    std::string pivot = vec[dist(gen)];

    std::vector<std::string> vec1, vec2, vec3;
    for (auto& i: vec)
    {
        if (i < pivot) vec1.push_back(i);
        else vec2.push_back(i);
    }
    vec2 = quickSort(vec2);
    vec1 = quickSort(vec1);
    for (auto& i: vec1) vec3.push_back(i);
    for (auto& i: vec2) vec3.push_back(i);
    return vec3;
}

bool is_all_iddentical(std::vector<std::string>& vec)
{
    bool res = std::count(vec.begin(), vec.end(), vec[0]) == vec.size() ? true : false;
    return res;
}