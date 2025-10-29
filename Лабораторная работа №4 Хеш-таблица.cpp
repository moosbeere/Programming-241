#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

void createFile() {
    ofstream input("input.txt");
    input << "3 2 1 3 0";
    input.close();
}

void outputFile() {
    ifstream output("output.txt");
    string line;
    cout << "Содержимое output.txt: ";
    if (getline(output, line)) {
        if (line.empty()) {
            cout << "(пусто)" << endl;
        }
        else {
            cout << line << endl;
        }
    }
    output.close();
}

int main() {
    setlocale(LC_ALL, "Russian");
    createFile();
    ifstream input("input.txt");
    ofstream output("output.txt");
    unordered_set<int> numbers;
    int num;
    while (input >> num) {
        if (num == 0) {
            vector<int> sortedNumbers(numbers.begin(), numbers.end());
            sort(sortedNumbers.begin(), sortedNumbers.end());
            for (size_t i = 0; i < sortedNumbers.size(); i++) {
                output << sortedNumbers[i];
                if (i != sortedNumbers.size() - 1) {
                    output << " ";
                }
            }
            break;
        }
        else if (num > 0) {
            numbers.insert(num);
        }
        else {
            numbers.erase(-num);
        }
    }
    input.close();
    output.close();
    outputFile();
}