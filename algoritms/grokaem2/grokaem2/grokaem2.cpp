#include <iostream>
using namespace std;


//void printNumbers(int n) {
//    if (n == 0) return;        
//    printNumbers(n - 1);       
//    cout << n << " ";         
//}
//
//int main() {
//    int n;
//    cin >> n;                  
//    printNumbers(n);          
//    return 0;
//}



//2 Рекурсивная функция для вывода чисел от A до B
//void printRange(int a, int b) {
//    if (a == b) {              
//        cout << a << " ";      
//        return;
//    }
//
//    cout << a << " ";          
//
//    if (a < b) {
//        printRange(a + 1, b);  
//    }
//    else {
//        printRange(a - 1, b);  
//    }
//}
//
//int main() {
//    int A, B;
//    cin >> A >> B;            
//    printRange(A, B);          
//    return 0;
//}




//3 Рекурсивная функция для вычисления суммы цифр числа
//int sumOfDigits(int n) {
//    if (n == 0) return 0;     
//    return (n % 10) + sumOfDigits(n / 10);  
//}
//
//int main() {
//    int N;
//    cin >> N;                 
//    cout << sumOfDigits(N);    
//    return 0;
//}




//4 простые делители числа
void primeDivisors(int n, int divisor = 2) {
    if (n == 1) return;                  
    if (divisor * divisor > n) {          
        cout << n << " ";                  
        return;
    }

    if (n % divisor == 0) {            
        cout << divisor << " ";       
        primeDivisors(n / divisor, divisor); 
    }
    else {
        primeDivisors(n, divisor + 1);     
    }
}

int main() {
    int n;
    cin >> n;
    primeDivisors(n);
    return 0;
}