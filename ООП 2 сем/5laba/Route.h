#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
private:
    std::string startPoint;
    std::string endPoint;
    double length;   // в км

public:
    
    Route(const std::string& start, const std::string& end, double len);

    // Метод вывода информации
    void printInfo() const;

    double getLength() const;
    const std::string& getStartPoint() const;
    const std::string& getEndPoint() const;
};

#endif
