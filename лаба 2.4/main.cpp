#include "function.h"

int main() {
    using MyFunctions::functionWithStatic;
    
    // Вызов функции несколько раз с разными параметрами
    std::cout << "=== Первый вызов ===" << std::endl;
    functionWithStatic(5);     // 5 + 0 = 5, staticVar становится 5
    
    std::cout << "\n=== Второй вызов ===" << std::endl;
    functionWithStatic(10);    // 10 + 5 = 15, staticVar становится 10
    
    std::cout << "\n=== Третий вызов ===" << std::endl;
    functionWithStatic(3);     // 3 + 10 = 13, staticVar становится 3
    
    std::cout << "\n=== Четвертый вызов ===" << std::endl;
    functionWithStatic(8);     // 8 + 3 = 11, staticVar становится 8
    
    // Использование макроса SUM
    std::cout << "\n=== Использование макроса SUM ===" << std::endl;
    int a = 7, b = 12;
    std::cout << "SUM(" << a << ", " << b << ") = " << SUM(a, b) << std::endl;
    std::cout << "SUM(15, 25) = " << SUM(15, 25) << std::endl;
    
    // Пример с выражением
    std::cout << "SUM(a*2, b/3) = " << SUM(a*2, b/3) << std::endl;
    
    return 0;
}