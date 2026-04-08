#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>



using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	unordered_set<int> hech;

	ifstream input("input.txt");
	ofstream output("output.txt");

	int num;
	string line;

	while (getline(input, line, ' ')) {
		if (stoi(line) > 0) {
			hech.insert(stoi(line));
			cout << line << endl;
		}
		else if (stoi(line) < 0) {
			hech.erase(hech.find(-stoi(line)));
			// cout << line << " удален" << endl;
		}
	}
	vector<int> files(hech.begin(), hech.end());
	sort(files.begin(), files.end());

	cout << "Отсортированный файл: ";
	for (auto i : files) cout << i << " ";

	for (int i = 0; i < files.size(); i++) output << files[i] << " ";

	input.close();
	output.close();
}