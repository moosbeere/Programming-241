// FAst sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int maxNumber(vector<int> list) {
	if (list.size() == 2) {
		return (list[0] > list[1]) ? list[0] : list[1];
	}
	list.erase(list.begin());
	int sub_Max = maxNumber(list);
	return (list[0] > sub_Max) ? list[0] : sub_Max;
}


void swap(int data[], int first, int second) {
	auto temp = data[first];
	data[first] = data[second];
	data[second] = temp;
}

void sort(int data[], int start, int end) {
	if (start >= end) return;
	int current = start;
	for (int i = start + 1; i <= end; i++) {
		if (data[i] < data[start]) swap(data, ++current, i);
	}
	swap(data, current, start);
	if (current > start) {
		sort(data, start, current - 1);
	}
	if (end > current) {
		sort(data, current + 1, end);
	}
}

int main()
{
	vector<int> list = { 3,6,2,5 };
	//cout << maxNumber(list);
	int data[] = { 5,3,8,2,9,1 };
	sort(data, 0, size(data) - 1);
	for (auto elem : data) {
		cout << elem << ", ";
	}
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
