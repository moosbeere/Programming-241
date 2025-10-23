#pragma once
#include <exception>

using namespace std;

enum class ErrorCode {
	Negative,
	Big,
	False
};

class CustomError : public exception {
private:
	ErrorCode code;
public:
	CustomError(ErrorCode code) : code(code) {}
	const char* what() const throw() override;
};