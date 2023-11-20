#pragma once
#include <string>
#include <exception>
#include "Complex.h"

struct AssignmentError : public std::exception {
	const char* errorMessage = "Assignment error: ";
	std::string stringErrorMessage;

	AssignmentError() {}
	AssignmentError(const char* errorMessage) : errorMessage(errorMessage) {}
	AssignmentError(std::string errorMessage) {
		stringErrorMessage = errorMessage;
		this->errorMessage = stringErrorMessage.c_str();
	}
	AssignmentError(const char* memberName, double memberValue, double inputValue) {
		stringErrorMessage = std::string(memberName) + std::string(" = ") + std::to_string(memberValue)
			+ " differs from input value " + std::to_string(inputValue) + "!\n";
		errorMessage = stringErrorMessage.c_str();
	}
	AssignmentError(const char* memberName, Complex memberValue, Complex inputValue) {
		stringErrorMessage = std::string(memberName) + " = (" + std::to_string(memberValue.real()) + ", "
			+ std::to_string(memberValue.imag()) + ") differs from input value (" + std::to_string(inputValue.real())
			+ ", " + std::to_string(inputValue.imag()) + ")!\n";
		errorMessage = stringErrorMessage.c_str();
	}

	const char* what() {
		return errorMessage;
	}
};