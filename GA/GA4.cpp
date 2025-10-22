#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<int, int> numbers;
    int n;
    
    cout << "Введите числа (0 для завершения):" << endl;
    
    while (cin >> n) {
        if (n > 0) {
            numbers[n]++;
        } else if (n < 0) {
            int pos = -n;
            if (numbers[pos] > 0) {
                numbers[pos]--;
                if (numbers[pos] == 0) {
                    numbers.erase(pos);
                }
            }
        } else {
            break;
        }
    }
    
    vector<int> result;
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        for (int i = 0; i < it->second; i++) {
            result.push_back(it->first);
        }
    }
    
    sort(result.begin(), result.end());
    
    cout << "Результат: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
