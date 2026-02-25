class MyMath {
private:
    static int callCount;

public:
    static int Add(int a, int b);
    static int Sub(int a, int b);
    static int Mult(int a, int b);
    static double Div(int a, int b);

    static int getCallCount() { return callCount; }
};