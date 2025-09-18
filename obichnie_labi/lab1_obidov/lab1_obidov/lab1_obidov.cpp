

//#include <iostream> //подключение библиотекие iostream
//using namespace std;
//
//
//int main() //функция int
//{
//	setlocale(LC_ALL, "RU") //утсановление русского языка
//    cout << "First string\n";
// 
//    cout << "привет string\n"; // вывод переменных
//
//}


//2
#include <iostream>
#include <string>
using namespace std;
int main(){
//1
	int chislo = 150;
	float drugoe = 15.933;
	short c = 250;
	cout <<chislo <<"\n" << drugoe <<"\n" << c;
//2
	int den = 27;
	string mesyac = "may";
	short god = 2007;
	cout << den << "\n" << mesyac << "\n" << god <<"\n";

//3
	const double num = 2.3;
	const string stroka_windows = "WINDOWS";
	cout << num << " " << stroka_windows;
}


