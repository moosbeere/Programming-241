#include <iostream>

using namespace std;

string print(string array[], int size) {
    string data = "";
    for (int i = 0; i < size; i++) {
        data += array[i] + " ";
    }
    return data + "\n";
}

int main()
{
    setlocale(LC_ALL, "Ru");
    const int s = 5;
    string arr[s]{ "32-12-54", "16-43-96", "94-43-23", "74-13-25", "74-12-74"};
    cout << "Первоначальный массив номеров: " << print(arr, s);
    for (int i = 0; i < s; i++) {
        int min = i;
        for (int j = i + 1; j < s; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        string temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout << "Отсортированный список номеров: " << print(arr, s);
}