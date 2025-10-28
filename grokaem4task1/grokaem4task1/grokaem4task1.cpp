#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <locale>

using namespace std;

int main() {
    // Устанавливаем локаль системы для корректного отображения русского текста
    setlocale(LC_ALL, "RU");

    unordered_set<long long> numbers;
    long long num;

    cout << "Введите последовательность чисел (завершите нулем):" << endl;

    while (cin >> num) {
        if (num == 0) {
            // Выводим все числа в порядке возрастания
            vector<long long> sorted_numbers(numbers.begin(), numbers.end());
            sort(sorted_numbers.begin(), sorted_numbers.end());

            cout << "Результат: ";
            for (size_t i = 0; i < sorted_numbers.size(); ++i) {
                cout << sorted_numbers[i];
                if (i != sorted_numbers.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            break;
        }
        else if (num > 0) {
            // Добавляем положительное число
            numbers.insert(num);
            cout << "Добавлено: " << num << endl;
        }
        else {
            // Удаляем противоположное число (для отрицательного)
            long long to_remove = -num;
            if (numbers.find(to_remove) != numbers.end()) {
                numbers.erase(to_remove);
                cout << "Удалено: " << to_remove << endl;
            }
            else {
                cout << "Число " << to_remove << " не найдено для удаления" << endl;
            }
        }
    }

    return 0;
}