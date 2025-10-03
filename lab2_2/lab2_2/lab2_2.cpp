

#include <iostream>
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    int n;
    std::cout << "Введите положительное число ";
    std::cin >> n;
    while (n < 0) {
        std::cout << "Введите положительное число ";
        std::cin >> n;
        if (n < 0)
            continue;
        if (n > 0)
            break;
    }
    for (int i = 1; i < n; i++) {
        i += 1;
    int tab[] = { 1,4,78,4,9,67,11,25,356,45 };
    std::cout << " первое " << tab[0] << "ЧИСЛО  _" << " второе " << tab[1] << " ЧИСЛО  _ " << " третое" << tab[2] << "ЧИСЛО  _ " << " четвертое " << tab[3] << "ЧИСЛО  _ " << " пятое   " << tab[4] << "ЧИСЛО  _ " << "шестое   " << tab[5] << " ЧИСЛО  _ " << " седьмое  " << tab[6] << " ЧИСЛО  _  " << " восьмое " << tab[7] << " ЧИСЛО  _  " << " девятое " << tab[8] << " ЧИСЛО  _  " << " десятое " << tab[9] << " ЧИСЛО  _ ";

    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0)
            std::cout << tab[i];
    }
    for (int i = 1; i < 10; i++) {
        int sum = 0;
        if (i % 2 != 0)
            sum = +i;
    }
}
  