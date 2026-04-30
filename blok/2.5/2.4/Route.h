#pragma once
using namespace std;
#include <string>

class Route
{
private:
    string startPoint;
    string endPoint;
    double length;
public:
    Route(string start, string end, int len);

    void PrintInfo();
    double getLen();
};

