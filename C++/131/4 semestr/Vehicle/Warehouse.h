#pragma once
#include <iostream>
#include <vector>

template <typename T> 
class Warehouse
{
private:
	std::vector<T> items;
public:
	void addItem(const T& item);
	T getItem(int index);
	int getTotalItems();
};
//Можно было просто реализовать все внутри класса. Так как для шаблонных классов компилятор (линковщик)
// не позволяет разделять объявление и определение функций в разных файлах. Все функции должны быть
// реализованы внутри заголовочного файла
template <typename T>
void Warehouse<T>::addItem(const T& item) {
	items.push_back(item);
}

template <typename T>
T Warehouse<T>::getItem(int index) {
	return items[index];
}

template <typename T>
int Warehouse<T>::getTotalItems() {
	return items.size();
}
