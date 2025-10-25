#include <iostream>
using namespace std;



int first_part() {
	//1-5
	cout << "            first part of lab3" << endl;
	int* Apointe;
	int a = 2;
	Apointe = &a;
	cout << "ADRESS:" << Apointe << endl << "VALUE:" << *Apointe << endl;
	*Apointe = 3;
	cout << "after edit:" << a << endl;

	//6-10
	int massive[4] = { 24,89,55,40 };
	int* MASpoint;
	MASpoint = massive;
	cout << "elements of array: ";
	for (int i = 0; i < 4; i++) {
		cout << *(MASpoint + i) << " ";
	}

		
	int con = 90;
	int* const CONpointer=&con;
	*CONpointer = 100;
	cout <<"const variable is changed from 90 to:" << *CONpointer <<"\n";
	return 0;
}

int second_part(int* beginnig, int* finish) {
	int sum_of_el = 0;

	for (int* ptr = beginnig; ptr != finish; ptr++) {
		sum_of_el += *ptr;  
	}
	cout <<"Sum with pointers:" << sum_of_el << "\n";
	

	return 0;
}


int sec_of_part(int* beginnig, int* finish) {
	int dif_of_el = 0;


	bool first = true;
	for (int* ptr = beginnig; ptr != finish; ptr++) {
		if (first) {
			dif_of_el += *ptr; 
			first = false;
		}
		else {
			dif_of_el -= *ptr;  
		}
	}

	cout << "Difference of elements:" << dif_of_el << "\n";
	return dif_of_el;
}


int dlya_togo() {  
	char m;
	int arr[] = { 1, 2, 3, 4, 5 };
	int size = 5;

	cout << "Введите операцию (+ или -): ";
	cin >> m;

	if (m == '+') {
		second_part(arr, arr + size);
	}
	else if (m == '-') {
		sec_of_part(arr, arr + size);
	}
	else {
		cout << "Неизвестная операция!" << endl;
	}

	return 0;
}




int main() {
	first_part();


	int arr[] = { 1, 2, 3, 4, 5 };
	int size = 5;
	int sum_of_el = second_part(arr, arr + size);

	for (int n = 0; n < 5; n++) {
		cout << endl;
	}

	cout << "    second part of lab3" << "\n";


	int dif_of_el = sec_of_part(arr, arr + size);

	dlya_togo();

	//2.7-2.8
	float* pc1 = new float(5);
	cout << *pc1;
	delete pc1;
	return 0;
}




