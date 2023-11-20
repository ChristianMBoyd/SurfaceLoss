#pragma once
#include <string>
#include <exception>

struct NumericalError : public std::exception {
	const char* errorMessage = "Numerical error!\n";
	std::string stringErrorMessage;

	NumericalError() {}
	NumericalError(const char* errorMessage) : errorMessage(errorMessage) {}
	NumericalError(std::string errorMessage) {
		stringErrorMessage = errorMessage;
		this->errorMessage = stringErrorMessage.c_str();
	}

	const char* what() {
		return errorMessage;
	}
};