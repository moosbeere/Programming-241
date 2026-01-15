#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <locale>  // Для локализации

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");  
   

    // Входные данные, которые эмулируют файл input.txt
    int input[] = { 3, 2, 1, 3, 0 };
    int n = sizeof(input) / sizeof(input[0]);

    unordered_set<int> numSet;  // Множество для хранения чисел

    // Эмуляция работы с input.txt
    for (int i = 0; i < n; ++i) {
        int num = input[i];

        if (num == 0) {  // Если число равно 0, выводим множество и завершаем программу
            vector<int> sortedNumbers(numSet.begin(), numSet.end());  // Копируем элементы в вектор
            sort(sortedNumbers.begin(), sortedNumbers.end());  // Сортируем вектор

            // Эмуляция записи в output.txt
            cout << "Выходные данные (output.txt): ";
            for (int x : sortedNumbers) {  // Печатаем числа через пробел
                cout << x << " ";
            }
            cout << endl;
            break;  // Завершаем программу
        }
        else if (num > 0) {  // Если число положительное, добавляем его в множество
            numSet.insert(num);
        }
        else {  // Если число отрицательное, удаляем его противоположное значение
            numSet.erase(-num);
        }
    }

    return 0;
}
