#pragma once
#include <complex>

typedef std::complex<double> Complex;

// convenient overloads for int and Complex types

inline Complex operator*(const int leftInt, const Complex rightComplex) {
	return (1.0 * leftInt) * rightComplex;
}

inline Complex operator*(const Complex leftComplex, const int rightInt) {
	return rightInt * leftComplex;
}

inline Complex operator+(const Complex leftComplex, const int rightInt) {
	return leftComplex + (1.0 * rightInt);
}

inline Complex operator+(const int leftInt, const Complex rightComplex) {
	return rightComplex + leftInt;
}

inline Complex operator-(const Complex leftComplex, const int rightInt) {
	return leftComplex - (1.0 * rightInt);
}

inline Complex operator-(const int leftInt, const Complex rightComplex) {
	return (1.0 * leftInt) - rightComplex;
}