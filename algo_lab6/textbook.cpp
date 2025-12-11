#include <iostream>

int f(int ia[10])
{
    ia[1] = 8;
    return ia[0];
}
int main()
{
    char c = 100;
    std::cout << c;
}