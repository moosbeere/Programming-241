 
#include <iostream>

void separator() {
    
    std::cout << "\n---------------------\n";
}

int sumtab(const int array[], int length) {
    int sum = 0;

    
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }

    
    std::cout << "Сумма элементов массива = " << sum << "\n";
    return sum;
}

 
int sum(int x, int y) {
    int result = x + y;
    std::cout << "Сумма = " << result << "\n";
    return result;
}

 
int sou(int x, int y) {
    int result = x - y;
    std::cout << "Разность = " << result << "\n";
    return result;
}

 
char carc(char k) {
    
    if (k == '+' || k == '-') {
        return k;
    }
    else {
        std::cout << "Неизвестный оператор\n";
    }
}

 
float* test() {
    return new float(10.0f);   
}

 
void operation(int k, int m, char l) {
    char op = carc(l);
    if (l == '+') {
        sum(k, m);   
    }
    else if (l == '-') {
        sou(k, m);   
    }
    else {
        std::cout << "Неизвестный оператор\n";
    }
}

int main() {
    int array[] = { 5, 8, 9 };

    int length = sizeof(array) / sizeof(array[0]);

    sumtab(array, length);

    separator();

    operation(8, 9, '+');

    separator();

    float* x = new float(5.0f);
    std::cout << "Адрес x: " << x << ", значение: " << *x << "\n";
    delete x;   

    
    float* y = test();
    std::cout << "Адрес y: " << y << ", значение: " << *y << "\n";
    delete y;   

    return 0;  
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
