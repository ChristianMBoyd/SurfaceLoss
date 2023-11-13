#pragma once
#include "Test.h"
#include "Matrix.h"

class TestMatrix : public Test {
public:
	TestMatrix();
	void runTests();

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

	// Next: extract testing methods in Test (avoid duplicate), then implement similar functionality to generate random matrices
	// Then: implement addition/subtraction operators, then extend rows/columns and other related functions
};