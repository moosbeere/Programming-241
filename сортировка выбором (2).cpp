#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> arr, int x) {
	int max = arr[x];
	int max_index = x;
	for (int i = x; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
			max_index = i;
		}
	}
	return max_index;
}

vector<int> selectionSort(vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		int max_index = findMax(arr, i);
		int temp = arr[i];
		arr[i] = arr[max_index];
		arr[max_index] = temp;
	}
	return arr;
}

int main()
{
	vector<int> arrey{ 2, 29, 47, 99, 13, 1, 88, 33, 61 };
	vector<int> sort = selectionSort(arrey);
	for (int n : sort) cout << n << ", ";

}
