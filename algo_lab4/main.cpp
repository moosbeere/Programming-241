#include <set>
#include <fstream>
#include <iostream>


int main()
{
    std::set<int> set;
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    int n;
    while (in >> n)
    {
        if (n > 0) set.insert(n);
        else if (n < 0) set.extract(-n);
        else
        {
            for (auto& i: set) std::cout << i << ' ';
        }
    }
    for (auto i: set) out << i << ' ';
}