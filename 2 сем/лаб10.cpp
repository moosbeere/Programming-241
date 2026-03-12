#include <iostream>

#include "public_transport.h"

int main()
{
    Bus bus(12, 80, "MAN", 90, "diesel");
    Tram tram(5, 150, 600);

    std::cout << "=== Public transport info ===\n\n";

    bus.printInfo();
    std::cout << "\n";

    tram.printInfo();

    return 0;
}
