#pragma once
#include "Exception.h"
#include "Complex.h"
#include "StringConverter.h"

class NumericalError : public Exception {
private:
	StringConverter stringConverter;
	const char* errorMessage = "Assignment error: ";
	String stringErrorMessage; // used to hold string contents for .c_str() conversion

	void initializeFromStringErrorMessage() {
		errorMessage = stringErrorMessage.c_str();
	}

	template<class Object>
	void initializeFromNameValueInput(const String& memberName, const Object& memberValue,
		const Object& inputValue);
	template<>
	void initializeFromNameValueInput<String>(const String& memberName, const String& memberValue,
		const String& inputValue);

public:
	NumericalError() {}
	NumericalError(const char* errorMessage) : errorMessage(errorMessage) {}
	NumericalError(const String& errorMessage) : stringErrorMessage(errorMessage) {
		initializeFromStringErrorMessage();
	}
	// personal preference: public overloads deferring to internal template
	NumericalError(const String& memberName, const String& memberValue, const String& inputValue) {
		initializeFromNameValueInput<String>(memberName, memberValue, inputValue);
	}
	NumericalError(const String& memberName, const unsigned int memberValue, const unsigned int inputValue) {
		initializeFromNameValueInput<unsigned int>(memberName, memberValue, inputValue);
	}
	NumericalError(const String& memberName, const int memberValue, const int inputValue) {
		initializeFromNameValueInput<int>(memberName, memberValue, inputValue);
	}
	NumericalError(const String& memberName, const double memberValue, const double inputValue) {
		initializeFromNameValueInput<double>(memberName, memberValue, inputValue);
	}
	NumericalError(const String& memberName, const Complex& memberValue, const Complex& inputValue) {
		initializeFromNameValueInput<Complex>(memberName, memberValue, inputValue);
	}
	NumericalError(const String& memberName, const Matrix& memberValue, const Matrix& inputValue) {
		initializeFromNameValueInput<Matrix>(memberName, memberValue, inputValue);
	}

	const char* what() const noexcept override {
		return errorMessage;
	}
};

template<class Object>
inline void NumericalError::initializeFromNameValueInput(const String& memberName, const Object& memberValue,
	const Object& inputValue) {
	String memberValueString = stringConverter.toString(memberValue);
	String inputValueString = stringConverter.toString(inputValue);
	initializeFromNameValueInput<String>(memberName, memberValueString, inputValueString);
}

template<>
inline void NumericalError::initializeFromNameValueInput<String>(const String& memberName, const String& memberValue,
	const String& inputValue) {
	stringErrorMessage = memberName + " = " + memberValue + " differs from input of " + inputValue + "!\n";
	initializeFromStringErrorMessage();
}