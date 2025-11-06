//ЗАДАНИЕ 1
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int main() {
// setlocale(LC_ALL, "ru");
// 
//	const int N = 1000;
//	int arr[N];
//
//	for (int i = 0; i < N; i++) {
//		cin >> arr[i];
//	}
//
//	sort(arr, arr + N);
//
//	for (int i = 0; i < N; i++) {
//		cout << arr[i] << " ";
// 	}
//
//	return 0;
//}





//ЗАДАНИЕ 2	
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void quickSort(int arr[], int left, int right) {
//	if (left >= right) return;
//
//	int pivot = arr[right];
//	int i = left - 1;
//
//	for (int j = left; j < right; j++) {
//		if (arr[j] <= pivot) {
//			swap(arr[i], arr[j]);
//		 }
//	}
//
//	swap(arr[i + 1], arr[right]);
//
//	int pivotIndex = i + 1;
//
//	quickSort(arr, left, pivotIndex - 1);
//
//	quickSort(arr, pivotIndex + 1, right);
//}
//
//int main() {
//	setlocale(LC_ALL, "ru");
//
//	const int N = 10;
//	int arr[N];
//
//	std::srand(std::time(nullptr));
//
//	for (int i = 0; i < N; ++i) {
//		arr[i] = 50 + std::rand() % 51; 
//	}
//
//	std::cout << "Неотсортированный массив:\n";
//	for (int i = 0; i < N; ++i) {
//		std::cout << arr[i] << " ";  
//	}
//	std::cout << "\n";
//
//	quickSort(arr, 0, N - 1);    
//
//	std::cout << "Отсортированный массив:\n";
//	for (int i = 0; i < N; ++i) {
//		std::cout << arr[i] << " ";   
//	}
//	std::cout << "\n";
//
//	return 0;
//}





//ЗАДАНИЕ 3
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void quickSort(int arr[][2], int left, int right) {
//    int i = left, j = right;
//    int pivot = arr[(left + right) / 2][0];
//    while (i <= j) {
//        while (arr[i][0] < pivot) i++;
//        while (arr[j][0] > pivot) j--;
//        if (i <= j) {
//            swap(arr[i][0], arr[j][0]);
//            swap(arr[i][1], arr[j][1]);
//            i++;
//            j--;
//        }
//    }
//    if (left < j) quickSort(arr, left, j);
//    if (i < right) quickSort(arr, i, right);
//}
//
//int main() {
//    setlocale(LC_ALL, "ru");
//
//    const int N = 10;  
//    const int M = 2;   
//    int arr[N][M];
//
//    srand(time(nullptr));
//    for (int i = 0; i < N; ++i)
//        for (int j = 0; j < M; ++j)
//            arr[i][j] = 5 + rand() % (61 - 5 + 1);
//
//    cout << "Исходный массив:" << endl;
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j)
//            cout << arr[i][j] << "\t";
//        cout << endl;
//    }
//
//    quickSort(arr, 0, N - 1);
//
//    cout << "\nОтсортированный массив по первому столбцу:" << endl;
//    for (int i = 0; i < N; ++i) {
//        for (int j = 0; j < M; ++j)
//            cout << arr[i][j] << "\t";
//        cout << endl;
//    }
//
//    return 0;
//}





//ЗАДАНИЕ 4
#include <iostream>
#include <cstring>  
#include <cstdlib> 
using namespace std;

struct Student {
    char name[50];  
    int id;       
};

int compareStudents(const void* a, const void* b) {
    const Student* studA = (const Student*)a;
    const Student* studB = (const Student*)b;
    return strcmp(studA->name, studB->name);  
}

int main() {
    setlocale(LC_ALL, "ru");

    Student group[] = {
        {"Ivanov", 101},
        {"Petrov", 102},
        {"Sidorov", 103},
        {"Alexeev", 104},
        {"Borisov", 105}
    };

    int n = sizeof(group) / sizeof(group[0]);  

    cout << "До сортировки:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << group[i].name << " (id:" << group[i].id << ")" << endl;
    }

    
    qsort(group, n, sizeof(Student), compareStudents);

    cout << "\nПосле сортировки по алфавиту:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << group[i].name << " (id:" << group[i].id << ")" << endl;
    }

    return 0;
}
