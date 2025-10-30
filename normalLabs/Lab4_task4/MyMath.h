#pragma once
class MyMath
{
private:
    static int staticMethodCount;
public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static int Div(int a, int b);
    static int getStaticCount();
};