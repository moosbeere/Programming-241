#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip> 
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	float r;
	cout << "";
	cin >> r;
	cout << setprecision(3) << 2 * r * M_PI * r << endl;

	fstream fs;
	while (true) {
		cout << "";
		string line;
		cin >> line;
		if (line == "read") {
			fs.open("a.txt", ios::in);
			string str;
			string data;
			while (getline(fs, str)) {
				cout << str << endl;
				data += str;
			}
			fs.close();
		}
		else if (line == "erase") {
			fs.open("a.txt", ios::out);
			fs.close();
		}
		else if (line == "exit") {
			break;
		}
		else
		{
			fs.open("a.txt", ios::app);
			fs << line << endl;
			fs.close();
		}

	}
}
