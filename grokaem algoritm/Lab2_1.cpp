#include <iostream>
#include <string>

using namespace std;

string recursion(int num) {
    if (num == 1) { return "1"; }
    return  recursion(num - 1) + " " + to_string(num);
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;
    cout << recursion(n);
}