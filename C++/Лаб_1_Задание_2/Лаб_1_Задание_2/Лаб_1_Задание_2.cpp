#include <iostream>

int oneHundredAndFifty = 150;
float fifteenDotNineThreeThree = 15.933;
short twoHundredAndFifty = 250;

short day = 1;
std::string month = "декабря";
int year = 2005;

const std::string whatIsThis = "2,3";
const std::string iDontUnderstand = "WINDOWS";

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "\noneHundredAndFifty = " << oneHundredAndFifty;
    std::cout << "\nfifteenDotNineThreeThree = " << fifteenDotNineThreeThree;
    std::cout << "\ntwoHundredAndFifty = " << twoHundredAndFifty;
    std::cout << "\n\nМоя дата рождения: " << day << " " << month << " " << year << " года";
    std::cout << "\n\n" << whatIsThis << " " << iDontUnderstand;

    std::cout << "\n\n\n\n\n\n";
}