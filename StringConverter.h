#pragma once
#include "String.h"
#include <sstream>
#include "Complex.h"
#include "Matrix.h"

// this class handles string conversions for error and test readout.

class StringConverter {
public:
	StringConverter() {}
	// personal preference: public overloads deferring to an internal template
	String toString() {
		return "";
	}
	String toString(const unsigned int value) {
		return convertObjectToString<unsigned int>(value);
	}
	String toString(const int value) {
		return convertObjectToString<int>(value);
	}
	String toString(const double value) {
		return convertObjectToString<double>(value);
	}
	String toString(const Complex& complex) {
		return convertObjectToString<Complex>(complex);
	}
	String toString(const Matrix& matrix) {
		return convertObjectToString<Matrix>(matrix);
	}

private:
	template<class Object>
	String convertObjectToString(const Object& object);
};

template<class Object> // defer to << overloads
inline String StringConverter::convertObjectToString(const Object& object) {
	std::stringstream stream;
	stream << object;
	return stream.str();
}