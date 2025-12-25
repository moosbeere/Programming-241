#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Settings {
private:
    static map<string, int> dict;

public:
    static void Add(string kluch, int n) {
        dict[kluch] = n;
    }
    static int Get(string kluch) {
        return dict[kluch];
    }
    static void Print() {
        for (auto i = dict.begin(); i != dict.end(); i++) {
            cout << i->first << " = " << i->second << endl;
        }
    }
};
map<string, int> Settings::dict;


void print(vector<float> vec) {
    for (auto i = vec.begin(); i != vec.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector<float> v;
    for (int i = 0; i <= 4; i++) {
        float n;
        cout << "";
        cin >> n;
        v.push_back(n);
    }
    print(v);

    v.insert(v.begin() + 2, 3);
    v.insert(v.begin() + 3, 4);
    print(v);

    v.pop_back();
    print(v);

    Settings set;
    set.Add("первый", 1);
    set.Add("второй", 2);
    set.Add("третий", 3);
    set.Print();
    cout << set.Get("второй") << endl;

}