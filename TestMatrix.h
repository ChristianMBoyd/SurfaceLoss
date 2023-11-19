#pragma once
#include "Test.h"
#include "Matrix.h"
#include "RandomGenerator.h"

class TestMatrix : public Test {
private:
	RandomGenerator randomGenerator;

public:
	TestMatrix();
	void runTests();

private:
	void testConstructors();
	void checkConstructorFunctions();

	void testAccessors();
	void checkAccessors();

	Matrix randomMatrix(unsigned int rows, unsigned int columns);

	void testEquals();
	void checkEquals();

	void testMultiplication();
	void checkScalarMultiplication();
	void checkComplexMultiplication();
	void checkDoubleMultiplication();

	// Next: start with tests on accessors using random values, then implement a randomMatrix function for subsequent testing
	// On a similar note: update TestInputStructs to use RandomGenerator 
	// Then: implement addition/subtraction operators, extend rows/columns and other related functions
};