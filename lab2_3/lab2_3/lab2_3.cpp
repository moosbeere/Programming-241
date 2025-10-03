 
#include <iostream>
#include <clocale>

int fun(int x, int s) {
    std::cout << "Введите певрое число ";
    std::cin >> x;
    if (x > 0)
        for (int i = 1; i < x + 1; i++) {
            int s;
            s = 0;
            s = i + s;
        }
    else
        std::cout << x;
}

int fun() {
    return 1;
}

int func(float x, float y) {
    int z;
    int v;
    std::cout << "Введите певрое число ";
    std::cin >> x;
    std::cout << "Введите певрое число ";
    std::cin >> y;
    float& z = x;
    float& v = y;
    z = x + y;
    v = x * y;
    return (z, v);

}

int main() {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    int array[2][3] = { {1,2, 96 }, {3,4,5} };
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum = array[i][j] + sum;
        }
    }
    std::cout << sum << "\n";
    int tab[] = { 3,4,5 };
    int tab1[] = { array[0][0] + array[0][1], array[0][1] + array[1][1], array[0][2] + array[1][2] };
    for (int i = 1; i < 3; i++) {
        std::cout << tab1[i] << "\n";
    }
    float x = 20.84;
    float& y = x;
    float& z = x;
    y = 2.29;
    std::cout << "x=" << x << "y = " << y << "and z " << z << "\n";


    func(12, 9);

    int k = 24;

    for (int i = 1; i < 4; i++) {
        std::cout << k;
        int p = 11;
        std::cout << p;
    }




}

 