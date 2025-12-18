#include <iostream>
#include "Windows.h"
#include <regex>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool validName(string s)
{
	regex reg("[A-Z][a-z]{1,31}");
	return (regex_match(s, reg) and isupper(s[0]));
}

void emailSearcher(string text) {
	regex epat(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
	auto ebeg = sregex_iterator(text.begin(), text.end(), epat);
	auto eend = sregex_iterator();
	int count = 0;
	for (sregex_iterator i = ebeg; i != eend; ++i) {
		smatch match = *i;
		cout << ++count << ". " << match.str() << std::endl;
	}

	if (count == 0) {
		std::cout << "Адреса не найдены." << std::endl;
	}
}

void vectorReader(vector<float> v) {
	for (float n : v) cout << n << " ";
	cout << "\n-------------\n";
}


class Settings {
private:
	static map<string, string> sMap;

public:
	static void Add(const string key, const string val) {
		sMap[key] = val;
	}

	static string Get(const string key) {
		return sMap[key];
	}

	static void Print() {
		for (const auto pair : sMap) {
			cout << pair.first << " = " << pair.second << endl;
		}
	}
};

map<string, string> Settings::sMap;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	while (true) {
		cin >> str;
		if (str == "стопе") {
			break;
		}
		cout << str.substr(1, 3) << endl;
		if (str.find("а") != 18446744073709551615) {
			cout << "Индекс первой \"а\": " << str.find("а") << endl;
		}
		else {
			cout << "Символа \"а\" не найдено\n";
		}
	}
	while (true) {
		cout << "\nВведите имя: ";
		cin >> str;
		if (str == "стопе") {
			break;
		}
		if (validName(str)) {
			cout << "Ваше имя: " << str << endl;
		}
		std::cout << "\nНайденные email-адреса:" << std::endl;

		str = "бабаббаабба ivan.petrov@mail.ruйоооооооооооооооооооооо nadezhda.smirnova@bk.ru alexander.volkov@gmail.com ekaterina.ivanova@outlook.com mihail.sokolov@mail.ru olga.vasileva@bk.ru dmitry.kuznetsov@gmail.com anna.fedorova@outlook.com sergey.popov@mail.ru бебебеббебе marina.nikitina@bk.ru vladimir.morozov@gmail.com";
		emailSearcher(str);
	}
	while (true) {
		cin >> str;
		if (str == "стопе") {
			break;
		}
		float rad = stoi(str);
		cout << setprecision(3) << 2 * M_PI * rad;

		string file = "output.txt";
        string userInput;
        while (true) {
            cout << "\nВведите строку (read - показать содержимое, erase - очистить файл, exit - выход): ";
			cin >> userInput;
            if (userInput == "exit") {
                break;
            }
            else if (userInput == "read") {
                ifstream Ifile(file);
                string line;
                cout << "Содержимое файла:" << endl;
				while (getline(Ifile, line)) {
					cout << line << endl;
				}
                Ifile.close();
            }
            else if (userInput == "erase") {
                ofstream Ofile(file, ios::trunc);
				cout << "Файл очищен." << endl;
				Ofile.close();

            }
            else {
                ofstream Ofile(file, ios::app); 
                Ofile << userInput << ' ';
                cout << "Строка записана в файл." << endl;
                Ofile.close();
            }
        }
	}

	while (true) {
		cin >> str;
		if (str == "стопе") {
			break;
		}

		vector<float> v1;
		v1.push_back(2.3);
		v1.push_back(3.3);
		v1.push_back(2.3);
		v1.push_back(3.3);
		v1.push_back(2.3);

		vectorReader(v1);
		auto i = v1.begin();
		i += 3;
		v1.insert(i, 2.1);
		vectorReader(v1);
		v1.pop_back();
		vectorReader(v1);
		Settings s;
		//s.Add("language", "Russian");
		//s.Add("theme", "Dark");
		//s.Add("volume", "75");
		//cout << "Language: " << s.Get("language") << endl;
		//cout << "Theme: " << s.Get("theme") << endl;
		//cout << "Non-existent key: " << s.Get("resolution") << endl;
		//s.Print();
		//s.Add("username", "admin");
		//s.Print();
		Settings::Add("server", "localhost");
		Settings::Add("port", "8080");
		Settings::Add("timeout", "30");

		cout << "Server: " << Settings::Get("server") << endl;
		cout << "Port: " << Settings::Get("port") << endl;
		cout << "Non-existent: " << Settings::Get("database") << endl;

		Settings::Print();
		Settings::Add("max_users", "100");
		Settings::Print();
	}
}