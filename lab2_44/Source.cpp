#include <iostream>
using namespace std;
namespace head {
    void printSum(int param) {
        static int totalSum = 0;
        cout << totalSum + param << '\n';
        totalSum += param;
    }
}