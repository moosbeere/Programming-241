#include <iostream>
#include <vector>
#include <algorithm>
#include <locale> // Для русской локали

struct Box {
    long long weight;    // вес коробки
    long long capacity;  // максимальный вес, который выдерживает
};

int main() {
    // Установка локали для поддержки русского языка в консоли
    std::locale::global(std::locale("")); // Использует локаль системы
    std::wcout.imbue(std::locale());
    std::wcin.imbue(std::locale());

    int n;
    std::wcout << L"Введите количество коробок: ";
    std::wcin >> n;

    std::vector<Box> boxes(n);
    std::wcout << L"Введите вес и грузоподъемность каждой коробки через пробел:\n";
    for (int i = 0; i < n; ++i) {
        std::wcin >> boxes[i].weight >> boxes[i].capacity;
    }

    // Сортируем по сумме веса и грузоподъемности
    std::sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
        return a.weight + a.capacity < b.weight + b.capacity;
        });

    long long totalWeight = 0; // суммарный вес коробок в стеке
    int count = 0;

    for (const auto& box : boxes) {
        if (totalWeight <= box.capacity) {
            totalWeight += box.weight;
            count++;
        }
    }

    std::wcout << L"Максимальное количество коробок, которые можно поставить в стек: " << count << L"\n";

    return 0;
}
