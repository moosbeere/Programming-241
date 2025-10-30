#include <iostream>
#include <ctime>

using namespace std;


void massivchik(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
       
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    srand(time(0)); 

    const int SIZE = 10;
    int arr[SIZE];

    
    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 102 + 2; // 2..103
        cout << arr[i] << " ";
    }
    cout << endl;

    
    massivchik(arr, SIZE);

  
    cout << "Отсортированный массив (по возрастанию): ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}



// 2 Функция сортировки выбором по убыванию
void selectionSortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {    
        int maxIndex = i;                  
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) { 
                maxIndex = j;              
            }
        }
        
        int temp = arr[i];           
        arr[i] = arr[maxIndex];     
        arr[maxIndex] = temp;        
    }
}

int main() {                         
    srand(time(0));                  

    const int SIZE = 10;           
    int arr[SIZE];                   

  
    cout << "Исходный массив: ";     
    for (int i = 0; i < SIZE; i++) { 
        arr[i] = rand() % 101;       
        cout << arr[i] << " ";       
    }
    cout << endl;                    

   
    selectionSortDesc(arr, SIZE);    

    // Вывод отсортированного массива
    cout << "Отсортированный массив (по убыванию): "; 
    for (int i = 0; i < SIZE; i++) { 
        cout << arr[i] << " ";       
    }
    cout << endl;                   

    return 0;                       
}


#include <vector>

using namespace std;

// 3 Функция сортировки выбором для строк (телефонных номеров)
void selectionSortPhones(vector<string>& phones) {
    int n = phones.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (phones[j] < phones[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен элементов
        string temp = phones[i];
        phones[i] = phones[minIndex];
        phones[minIndex] = temp;
    }
}

int main() {
    vector<string> phones = {
        "23-45-67",
        "12-34-56",
        "89-01-23",
        "45-67-89",
        "34-56-78"
    };
    
    cout << "Исходный список телефонов:" << endl;
    for (const auto& phone : phones) {
        cout << phone << endl;
    }
    cout << endl;
    
    // Сортировка
    selectionSortPhones(phones);
    
    cout << "Отсортированный список телефонов (по возрастанию):" << endl;
    for (const auto& phone : phones) {
        cout << phone << endl;
    }
    
    return 0;
}

