#include "Test.h"

Test::Test() {}

// Note on error output: convention is to include '\n' at the end of all partial statements [e.g., specific error messages].
//		Errors are then called according to: cout << "error: " << error.what(); 
void Test::runTests() {
	std::cout << "Testing Test base class...\n";

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

bool Test::twoDoublesAreEqual(double first, double second) {
	return (std::abs(first - second) < DOUBLE_ERROR);
}

bool Test::twoComplexesAreEqual(Complex leftValue, Complex rightValue) {
	bool realValuesAreEqual = twoDoublesAreEqual(leftValue.real(), rightValue.real());
	bool imagValuesAreEqual = twoDoublesAreEqual(leftValue.imag(), rightValue.imag());
	return realValuesAreEqual && imagValuesAreEqual;
}