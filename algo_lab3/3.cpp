#include <iostream>
#include <random>
#include "quickSort.cpp"


int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(5, 61);
    int size1 = 5;
    int size2 = 5;
    
    /* Determine the vector 5x5 */
    std::vector<std::vector<int>> vec(size1, std::vector<int>(5, 0));
    std::cout << std::endl << "Original vector:" << std::endl;
    for (int i = 0; i < size1; ++i)
    {
        std::cout << '[';
        for (int j = 0; j < size2; ++j)
        {
            vec[i][j] = dist(gen);
            std::cout << vec[i][j] << ' ';   
        }
        std::cout << ']' << ' ';
    }
    std::cout << std::endl << "Vector with sorted 1st column:" << std::endl;
    /* Take the 1st column */
    std::vector<int> column;
    for (auto& subvec: vec) column.push_back(subvec[0]);
    /* Sort and replace values from sorted column to original vector */
    column = quickSort(column);
    for (int i = 0; i < vec.size(); ++i) vec[i][0] = column[i];

    for (int i = 0; i < size1; ++i)
    {
        std::cout << '[';
        for (int j = 0; j < size2; ++j)
        {
            std::cout << vec[i][j] << ' ';   
        }
        std::cout << ']' << ' ';
    }
}