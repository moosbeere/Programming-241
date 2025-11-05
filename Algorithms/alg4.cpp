#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void inputFile()
{
	ofstream inputFile("input.txt");
	inputFile << "3 2 1 3 0";
	inputFile.close();
}

void outputFile()
{
	ifstream outputFile("output.txt");
	string line;
	cout << "Файл output.txt" << endl;
	if (getline(outputFile, line))
	{
		if (line.empty()) cout << "Пустая последовательность";
		else cout << line;
	}
	outputFile.close();
}

int main()
{
	setlocale(LC_ALL, "rus");
	inputFile();
	ifstream input("input.txt");
	ofstream output("output.txt");
	unordered_set<int> numbers;
	int num;
	while (input >> num)
	{
		if (num > 0)
		{
			numbers.insert(num);
		}
		else if (num < 0)
		{
			num *= -1;
			numbers.erase(num);
		}
		else
		{
			vector<int> sortedNumbers(numbers.begin(), numbers.end());
			sort(sortedNumbers.begin(), sortedNumbers.end());

			for (int i = 0; i < size(sortedNumbers); i++)
			{
				output << sortedNumbers[i];
				if (i < size(sortedNumbers))
				{
					output << ' ';
				}
			}
		}
	}
	input.close();
	output.close();
	outputFile();
}