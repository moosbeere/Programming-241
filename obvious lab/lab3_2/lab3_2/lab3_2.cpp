#include <iostream>
using namespace std;

int second_part(int* beginnig, int* finish) {
    int sum_of_el = 0;

    for (int* ptr = beginnig; ptr != finish; ptr++) {
        sum_of_el += *ptr;
    }

    return sum_of_el;
}

int sum_func(int a, int b) {
    return a + b;
}

int sec_of_part(int a, int b) {
    return a - b;
}

int (*dlya_togo(char m))(int, int) {
    if (m == '+') {
        return sum_func;
    }
    else {
        return sec_of_part;
    }
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = 5;

    int sum_result = second_part(arr, arr + size);
    cout << "Sum with pointers: " << sum_result << "\n\n";

    char plus = '+';
    char minus = '-';

    int (*func_plus)(int, int) = dlya_togo(plus);
    int result_plus = func_plus(10, 5);
    cout << "10 + 5 = " << result_plus << "\n";

    int (*func_minus)(int, int) = dlya_togo(minus);
    int result_minus = func_minus(10, 5);
    cout << "10 - 5 = " << result_minus << "\n\n";

    float* dynamic_float = new float(3.14f);

    cout << "Dynamic float value: " << *dynamic_float << "\n";

    delete dynamic_float;

    return 0;
}