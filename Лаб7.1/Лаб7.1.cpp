#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    if (s.size() >= 4)
    {
        cout << "Подстрока (со 2 по 4 символ): "
            << s.substr(1, 3) << endl;
    }
    else
    {
        cout << "Строка слишком короткая" << endl;
    }
    int index = s.find("a");
    if (index != string::npos)
    {
        cout << "Индекс первого вхождения 'a': "
            << index << endl;
    }
    else
    {
        cout << "Символа a не найдено" << endl;
    }
    return 0;
}
