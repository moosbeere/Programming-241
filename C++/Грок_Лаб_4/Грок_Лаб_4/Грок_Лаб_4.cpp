#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	unordered_set<int> filet;

	ifstream input("input.txt");
	ofstream output("output.txt");

	int num;
	string line;

	while (getline(input, line, ' ')) {
		if (stoi(line) > 0) {
			filet.insert(stoi(line));
			cout << line << endl;
		}
		else if (stoi(line) < 0) {
			filet.erase(filet.find(-stoi(line)));
			cout << line << " deleted" << endl;
		}
	}
	cout << "Неотсортированный файл: ";
	for (auto i : filet) cout << i << " ";

	vector<int> files(filet.begin(), filet.end());
	sort(files.begin(), files.end());

	cout << "\nОтсортированный файл: ";
	for (auto i : files) cout << i << " ";

	for (int i = 0; i < files.size(); i++) output << files[i] << " ";

	input.close();
	output.close();
}