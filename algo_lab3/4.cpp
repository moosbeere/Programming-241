#include <iostream>
#include <random>
#include "quickSortString.cpp"

int main()
{
     std::vector<std::string> names = {
        "James", "Mary", "John", "Patricia", "Robert",
        "Jennifer", "Michael", "Linda", "William", "Elizabeth",
        "David", "Barbara", "Richard", "Susan", "Joseph",
        "Jessica", "Thomas", "Sarah", "Charles", "Karen",
        "Christopher", "Nancy", "Daniel", "Lisa", "Matthew",
        "Patricia"
    };
    std::cout << "Original vector:" << std::endl;
    for (auto n: names) std::cout << n << ' ';
    
    names = quickSort(names);
    std::cout << std::endl << "Sorted vector:" << std::endl;
    for (auto n: names) std::cout << n << ' ';
}
