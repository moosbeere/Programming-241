
#include <iostream>
using std::cout;
using std::endl;
#define sum_number(r,y) r+y;
#include "MyMath.h";
using namespace firstNS;

//void func(int y) {
//	static int x = 0;
//	int sum = 0;
//	sum = x + y;
//	cout << sum << x << "\n";
//	x = sum;
//}

int main()
{
	std::setlocale(LC_ALL, "ru_RU.UTF-8");
	//func(6);
	//func(8);
	//func(25);
	//func(99);
	int r = 11;
	int y = 6;
	//cout << sum_number(r, y);

	cout << func(1);

}

