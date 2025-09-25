#include <iostream>
#include "Header.h"
using namespace std;

#define sumFunc(var1, var) cout << var1+var;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	manDotDotDot::func(a);
	manDotDotDot::func(b);
	manDotDotDot::func(c);
	cout << endl;
	sumFunc(a,b);
	cout << " ";
	sumFunc(b,c);
	cout << " ";
	sumFunc(c,a);
	cout << " ";
	cin >> a;
}