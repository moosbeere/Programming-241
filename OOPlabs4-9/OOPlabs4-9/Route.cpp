#include <iostream>
#include "Route.h"

Route::Route(std::string destination)
    : destination(destination)
{
}

void Route::showRoute() const {
    std::cout << "Destination: "
        << destination
        << std::endl;
}