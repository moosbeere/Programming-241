// Find width.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

void pushQueue(vector<string> arr, queue<string>& queue);
bool personIsSailer(string person);
bool checkPerson(string person, vector<string>& arr);

int main()
{
    unordered_map < string, vector<string>> graph;
    queue<string> queue;
    vector<string> arr;
    graph["you"] = { "alice", "bob", "claire" };
    graph["bob"] = { "anuj", "peggi" };
    graph["alice"] = { "peggi" };
    graph["claire"] = { "thom", "jonny" };
    graph["anuj"] = {};
    graph["peggi"] = {};
    graph["thom"] = {};
    graph["jonny"] = {};
    pushQueue(graph["you"], queue);
    while (!queue.empty()) {
        string person = queue.front();
        queue.pop();
        if (checkPerson(person, arr)) {
            if (personIsSailer(person)) {
                cout << "Is a mango saller: " << person << endl;
                return true;
            }
            else {
                pushQueue(graph[person], queue);
            }
        }

    }

}

void pushQueue(vector<string> arr, queue<string>& queue)
{
    for (auto elem : arr) {
        queue.push(elem);
    }
}

bool personIsSailer(string person)
{
    //if (person[person.size() - 1] == 'm') {
    //    return false;
    //}
    return false;

}

bool checkPerson(string person, vector<string>& arr)
{
    for (auto elem : arr) {
        if (elem == person) {
            return false;
        }
        else {
            arr.push_back(person);
            return true;
        }
    }
}
