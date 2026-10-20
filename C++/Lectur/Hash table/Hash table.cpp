// Hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_map<string, int> phone_book;
	phone_book["olga"] = 909;
	phone_book["sara"] = 9094;
	phone_book["oleg"] = 90941;
	phone_book["polina"] = 9094108;
	//foreach( phone_book as elem)
	for (auto& elem : phone_book) {
		cout << elem.first << " " << elem.second << endl;
	}
	cout << endl;
	cout << phone_book["polina"];
	cout << endl;

	unordered_set<string> voted;
	string name;
	while (true) {
		cout << "Enter wour name: ";
		cin >> name;
		if (name == "o") break;
		auto search = voted.find(name);
		if (search != voted.end()) {
			cout << "kick the out" << endl;
		}
		else {
			voted.insert(name);
			cout << "Let them vote" << endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
