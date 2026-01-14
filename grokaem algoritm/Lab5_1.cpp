#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void printArr(vector<string>& vec) {
    cout << "Кратчайший путь от S до I: ";
    for (auto elem : vec) {
        cout << elem;
    }
}

vector<string> findShortestWay(string start, string end, unordered_map<string, vector<string>>& g) {
    queue<string> q;
    unordered_set<string> visited;
    unordered_map<string, string> parent;
    q.push(start);
    visited.insert(start);
    parent[start] = "";

    bool found = false;
    while (!q.empty() && !found) {
        string current = q.front();
        // cout << current;
        q.pop();

        if (g.find(current) != g.end()) {
            for (string neighbor : g[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    parent[neighbor] = current;
                    q.push(neighbor);
                    if (neighbor == end) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    vector<string> path;
    string curr = end;

    if (found) {
        while (curr != "") {
            path.push_back(curr);
            curr = parent[curr];
        }
        return path;
    }
    else { return path; }
}

int main()
{
    setlocale(LC_ALL, "Ru");
    ifstream input("input.txt");
    string str;
    unordered_map<string, vector<string>> graph;
    cout << "Граф прочтённый из файла input.txt:" << endl;
    while (getline(input, str)) {
        string key = str.substr(0, 1);
        cout << key << ": ";
        for (auto elem : str.substr(str.find(">") + 1)) {
            string neighbor(1, elem);
            graph[key].push_back(neighbor);
            cout << elem << " ";
        }
        cout << endl;
    }
    input.close();

    string start = "S";
    string end = "I";
    vector<string> out = findShortestWay(start, end, graph);
    reverse(out.begin(), out.end());
    printArr(out);
}
