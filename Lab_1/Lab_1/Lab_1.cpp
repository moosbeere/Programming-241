//// Подключение библиотеки для ввода и вывода
//#include <iostream>  
//
//// Начало программы
//int main() {  
//
//    // Вывод строки "First string" в консоль
//    std::cout << "First string" << std::endl;
//
//    // Вывод сразу двух строк "Первая строка" и "Вторая строка"
//    std::cout << "Первая строка\nВторая строка" << std::endl;
//
//    // Вывод спецсимвола "/"
//    std::cout << "Спецсимволы \"\\\"" << std::endl;
//
//    // Завершение программы
//    return 0;  
//
//// Скобка, которая закрывает main
//}



#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "ru");
    int int_Chislo = 150;
    float float_Chislo = 15.933;
    unsigned char small_Chislo = 250;
    std::cout << "int_Chislo" << std::endl;
    std::cout << "float_Chislo" << std::endl;
    std::cout << "small_Chislo" << std::endl;

    int day = 26;
    std::string month = "октября";
    int year = 2006;
    std::cout << "Моя дата рождения " << day << " " << month << " " << year << " года" << std::endl;
    
    const double const_Chislo = 2.3;
    std::cout << "const_Chislo: " << const_Chislo << std::endl;

    const std::string conts_stroka = "WINDOWS";
    std::cout << "const_stroka" << std::endl;

    return 0;

}