#pragma once
#include "Test.h"
#include "Matrix.h"

class TestMatrix : public Test {
public:
	TestMatrix();
	void runTests();
	bool twoComplexesAreEqual(std::complex<double> leftValue, std::complex<double> rightValue);

private:
	void testConstructors();
	void checkConstructorFunctions();

	void testAccessors();
	void checkAccessors();

	void testEquals();
	void checkEquals();

	void testMultiplication();
	void checkScalarMultiplication();
	void checkComplexMultiplication();
	void checkDoubleMultiplication();

	// Next: implement addition/subtraction operators, then extend rows/columns and other related functions
};