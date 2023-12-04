#pragma once
#include "Exception.h"
#include "Complex.h"

struct AssignmentError : Exception {
	const char* errorMessage = "Assignment error: ";
	std::string stringErrorMessage; // used to build const char* used in .what() via std::string::c_str();

	AssignmentError() {}
	AssignmentError(const char* errorMessage) : errorMessage(errorMessage) {}
	AssignmentError(const std::string& errorMessage) {
		this->errorMessage = errorMessage.c_str();
	}
	AssignmentError(const char* memberName, int memberValue, int inputValue) {
		errorMessage = generateErrorMessage<int>(memberName, memberValue, inputValue);
	}
	AssignmentError(const char* memberName, unsigned int memberValue, unsigned int inputValue) {
		errorMessage = generateErrorMessage<unsigned int>(memberName, memberValue, inputValue);
	}
	AssignmentError(const char* memberName, double memberValue, double inputValue) {
		errorMessage = generateErrorMessage<double>(memberName, memberValue, inputValue);
	}
	AssignmentError(const char* memberName, Complex memberValue, Complex inputValue) {
		errorMessage = generateErrorMessage<Complex>(memberName, memberValue, inputValue);
	}

	const char* what() const noexcept override {
		return errorMessage;
	}

	template<class Number> // used when std::to_string(Number) is defined
	const char* generateErrorMessage(const char* memberName, Number memberValue, Number inputValue) {
		stringErrorMessage = std::string(memberName) + " = " + std::to_string(memberValue) 
		+ " differs from input value " + std::to_string(inputValue) + "!\n";
		return stringErrorMessage.c_str();
	}

	template<> // std::to_string(Complex) not provided
	const char* generateErrorMessage<Complex>(const char* memberName, Complex memberValue, Complex inputValue) {
		stringErrorMessage = std::string(memberName) + " = (" + std::to_string(memberValue.real()) + ", "
			+ std::to_string(memberValue.imag()) + ") differs from input value (" + std::to_string(inputValue.real())
			+ ", " + std::to_string(inputValue.imag()) + ")!\n";
		return stringErrorMessage.c_str();
	}
};