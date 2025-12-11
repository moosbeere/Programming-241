#pragma once
#include <iostream>

enum class PlayerError {
    BIG,
    NEGATIVE,
    ZERO
};

class PlayerException :
    public std::exception
{
private:
    PlayerError code;
public:
    PlayerException(PlayerError code) :code(code) {}
    const char* what() const throw() override;
};

