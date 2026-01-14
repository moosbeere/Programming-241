#pragma once
#ifndef HANDS_H
#define HANDS_H

// Шаблонный класс Hands
// Можно хранить любые типы оружия или просто числа
template <typename Left, typename Right>
class Hands {
private:
    Left leftHand;   // Левая рука
    Right rightHand; // Правая рука

public:
    // Конструктор
    Hands(Left l, Right r) : leftHand(l), rightHand(r) {}

    // Сеттеры
    void setLeft(Left l) { leftHand = l; }
    void setRight(Right r) { rightHand = r; }

    // Геттеры
    Left getLeft() const { return leftHand; }
    Right getRight() const { return rightHand; }
};

#endif
