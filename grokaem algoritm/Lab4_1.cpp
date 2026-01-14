#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");
    unordered_set<int> set;
    
    ifstream input("input.txt");
    int num;
    cout << "Первоначальный вид файла: ";
    while (input >> num) {
        cout << num << " ";
        if (num > 0) {
            set.insert(num);
        }
        else if (num < 0) {
            set.erase(-num);
        }
        else {
            break; 
        }
    }
    input.close();
    cout << endl;

    cout << "Отсортированный массив: ";
    vector<int> vec;
    for (auto i : set) {
        vec.push_back(i);
    }
    sort(vec.begin(), vec.end());

    ofstream output("output.txt");
    for (auto elem : vec) {
        cout << elem << " ";
        output << elem << " ";
    }
}