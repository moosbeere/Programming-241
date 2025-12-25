#pragma once
#ifndef MYMATH_H
#define MYMATH_H

class MyMath {
private:
    static int callCount;  

public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static float Div(int a, int b);

    static int getCallCount() { return callCount; }
};

#endif