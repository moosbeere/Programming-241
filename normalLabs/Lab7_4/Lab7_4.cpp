#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Settings {
private:
    map<string, int> dict;
public:
    void Add(string key, int num) {
        dict[key] = num;
    }
    int Get(string key) {
        auto finder = dict.find(key);
        if (finder != dict.end()) { return finder->second; }
        cout << "Ключ не найден!" << endl;
        return -1;
    }
    void Print() {
        cout << "Все элементы Map:" << endl;
        for (auto i = dict.begin(); i != dict.end(); i++) {
            cout << i->first << " = " << i->second << endl;
        }
    }
};

class StaticSettings {
private:
    static map<string, int> dict;
public:
    static void Add(string key, int num) {
        dict[key] = num;
    }
    static int Get(string key) {
        auto finder = dict.find(key);
        if (finder != dict.end()) { return finder->second; }
        cout << "Ключ не найден!" << endl;
        return -1;
    }
    static void Print() {
        cout << "Все элементы Map:" << endl;
        for (auto i = dict.begin(); i != dict.end(); i++) {
            cout << i->first << " = " << i->second << endl;
        }
    }
};

map<string, int> StaticSettings::dict;

void print(vector<float> vec) {
    for (auto i = vec.begin(); i != vec.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    vector<float> v1;
    for (int i = 0; i <= 4; i++) {
        float num;
        cout << "Введите значение элемента: ";
        cin >> num;
        v1.push_back(num);
    }
    cout << "Исходный вектор: ";
    print(v1);

    v1.insert(v1.begin() + 2, 3);
    v1.insert(v1.begin() + 3, 4);
    cout << "Вектор после вставок: ";
    print(v1);
    v1.pop_back();
    cout << "Вектор после удаления последнего элемента: ";
    print(v1);

    Settings set;
    set.Add("первый", 1);
    set.Add("второй", 2);
    set.Add("третий", 3);
    set.Print();
    cout << "Получение второго элемента: " << set.Get("второй") << endl;
    cout << "Получение несуществующего элемента: ";
    set.Get("dadsfsd");
    
    // в статическом классе у всех экземпляров один и тот же map
    StaticSettings::Add("первый", 1);
    StaticSettings::Add("второй", 2);
    StaticSettings::Add("третий", 3);
    StaticSettings::Print();
    cout << "Получение второго элемента: " << StaticSettings::Get("второй") << endl;
    cout << "Получение несуществующего элемента: ";
    StaticSettings::Get("dadsfsd");
    StaticSettings stat;
    stat.Add("новый", 4);
    stat.Print();
}