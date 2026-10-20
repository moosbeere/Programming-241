#include <iostream>

int main()
{
    int a = 10;
    int* pointer;
    pointer = &a;
    std::cout << "pointer = " << pointer << '\n';
    *pointer = 20;
    std::cout << a << '\n';

    int numbers[4]{ 1, 2, 3, 4 };
    for (int i = 0; i < 4; i++) {
        std::cout << *(numbers + i) << " ";
    }
    std::cout << '\n';

    int b = 5;
    const int*  pointer2 = &b;
    std::cout << "pointer2 = " << *pointer2 << '\n';
    pointer2 = &a;
    std::cout << "pointer2 = " << *pointer2 << '\n';

}