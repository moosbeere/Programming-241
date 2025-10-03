// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	//for (int i = 0; i < 10; i++) { //i++ (i = i + 1) (i +=i) 
	//	cout << i << ",";
	//}
	//cout << endl;

	//int i = 0;
	//while (i <= 10) {
	//	cout << i << ",";
	//	i++;
	//}
	//cout << endl;
	//i = 0;
	//do {
	//	cout << i << ",";
	//	i--;
	//} while (i > 0);
	//cout << endl;


	int i = 0;
	while (i < 7) {
		i++;
		if (i == 3) continue;
		if (i == 6) break;
		cout << i << endl;
	}


	/*int a;
	cout << "Enter number: ";
	cin >> a;
	switch (a)
	{
	case 1: {
		cout << "Your's number: 1\n";
		break;
	}
	case 2: {
		cout << "Your's number: 2\n";
		break;
	}
	case 3: {
		cout << "Your's number: 3\n";
		break;
	}
	default: cout << "ok\n";
		break;
	}*/




	//if (a > 10) {
	//	a = a * 2;
	//}
	//else {
	//	a = a * 4;
	//}
	//a = (a > 10) ? (a * 2) : (a * 4);

	/*if (a > 10) {
		a = a * 2;
	}
	else if (a < 0){
		a = a * (-4);
	}
	else {
		a = a * 4;
	}*/
	//cout << a << endl;




	//a = a * 2;
	//cout << a << endl;

	/*string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << name << endl;*/

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
