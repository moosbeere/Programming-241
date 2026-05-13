#pragma once
#ifndef DISPATCHCENTER_H
#define DISPATCHCENTER_H

#include <iostream>

using namespace std;

// ======================================================
// Класс DispatchCenter
// ======================================================

class DispatchCenter {
public:

    // Статическое поле
    static int totalVehiclesDispatched;

    // Статический метод
    static void report();
};

#endif