#ifndef DISPATCH_CENTER_H
#define DISPATCH_CENTER_H

class DispatchCenter {
private:
    static int totalVehiclesDispatched;  // Статическое поле
    
public:
    static void report();                 // Статический метод
    static void incrementCounter();      
};

#endif
