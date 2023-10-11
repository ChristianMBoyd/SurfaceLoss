#pragma once
#include <exception>

struct NumericalError : public std::exception {
	const char* what() {
		return "Numerical error!\n";
	}
};