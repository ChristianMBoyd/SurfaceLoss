#pragma once
#include "Test.h"
#include "Matrix.h"

class TestMatrix : public Test {
public:
	TestMatrix();
	void runTests();
	Matrix generateRandomUnitMatrix();

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

	// Next: update TestMatrix to use random values and implement generateRandomUnitMatrix()
	// On a similar note: update TestInputStructs to use random values
	// Then: implement addition/subtraction operators, then extend rows/columns and other related functions
};