#pragma once
#include "Exception.h"

struct NumericalError : public Exception {
	const char* errorMessage = "Numerical error!\n";
	std::string stringErrorMessage;

	NumericalError() {}
	NumericalError(const char* errorMessage) : errorMessage(errorMessage) {}
	NumericalError(const std::string& errorMessage) {
		stringErrorMessage = errorMessage;
		this->errorMessage = stringErrorMessage.c_str();
	}

	const char* what() const noexcept override {
		return errorMessage;
	}
};