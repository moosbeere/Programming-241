#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void Printvector(vector<float> v)
{
    for (float x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

class Settings
{
public:
    static map<string, string> data;

    static void Add(string key, string value)
    {
        data[key] = value;
    }

    static string Get(string key)
    {
        return data[key];
    }

    static void Print()
    {
        for (auto pair : data)
        {
            cout << pair.first << " = " << pair.second << endl;
        }
    }
};

map<string, string> Settings::data;

int main()
{
    vector<float> v;

    v.push_back(1.1f);
    v.push_back(2.2f);
    v.push_back(3.3f);
    v.push_back(4.4f);
    v.push_back(5.5f);

    Printvector(v);

    v.insert(v.begin() + 3, 9.9f);

    Printvector(v);

    v.pop_back();

    Printvector(v);

    //Settings s; 
    //s.Add("volume", "80"); 
    //s.Print();

    Settings::Add("volume", "80");
    Settings::Add("brightness", "50");

    cout << "Volume: " << Settings::Get("volume") << endl;

    Settings::Print();

    return 0;
}
