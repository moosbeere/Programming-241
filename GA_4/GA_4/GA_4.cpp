#include <iostream>           
#include <unordered_set>     
#include <vector>            
#include <algorithm>          

using namespace std;         

int main() {
    setlocale(LC_ALL, "ru");

    unordered_set<int> numbers; 
    int x;                      

    while (cin >> x) {        
        if (x > 0) {           
            numbers.insert(x);  
        }
        else if (x < 0) {     
            numbers.erase(-x); 
        }
        else {               
            vector<int> result(numbers.begin(), numbers.end()); 
            sort(result.begin(), result.end()); 

            for (int num : result) {         
                cout << num << " ";              
            }
            cout << "\n";                  
            break;                            
        }
    }

    return 0;              
}
