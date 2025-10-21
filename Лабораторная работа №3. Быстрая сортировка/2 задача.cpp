#include <iostream>
using namespace std;

void swap(int data[], int first, int second) {
    auto temp = data[first];
    data[first] = data[second];
    data[second] = temp;
}

void sort(int data[], int start, int end) {
    if (start >= end) return;
    int current = start;
    for (int i = start + 1; i <= end; i++) {
        if (data[i] < data[start]) swap(data, ++current, i);
    }
    swap(data, current, start);
    if (current > start) {
        sort(data, start, current - 1);
    }
    if (end > current) {
        sort(data, current + 1, end);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int data[] = {50, 52, 100, 67, 91, 82, 64, 99};
    sort(data, 0, size(data) - 1);
    for (auto elem : data) {
        cout << elem << ", ";
    }
}
// не понимаю, в чем разница между 1 и 2 задачей, кроме как количеством элементов в массиве.
