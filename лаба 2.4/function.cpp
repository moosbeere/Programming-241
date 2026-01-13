#include "function.h"

namespace MyFunctions {
    void functionWithStatic(int number) {
        // Статическая переменная (сохраняет значение между вызовами)
        static int staticVar = 0;
        
        // Вывод суммы переданного числа и статической переменной
        using std::cout;
        using std::endl;
        
        cout << "Сумма " << number << " и статической переменной (" 
             << staticVar << "): " << (number + staticVar) << endl;
        
        // Присваиваем статической переменной значение переданного числа
        staticVar = number;
    }
}