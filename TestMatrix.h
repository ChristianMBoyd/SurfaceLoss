#pragma once
#include "Test.h"
#include "Matrix.h"
#include "RandomGenerator.h"

class TestMatrix : public Test {
private:
	RandomGenerator randomGenerator;
	const int NUMBER_OF_ASSIGNMENT_TESTS = 10, NUMBER_OF_OPERATIONS_TESTS = 100; // more concerned with mathematical operations

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
	void checkIsNotEquals();

	void testMultiplication();
	void checkScalarMultiplication();
	void checkComplexMultiplication();
	void checkDoubleMultiplication();

	// Next: test mathematical operations with randomly generated matrices
	// Consider: implementing two RandomGenerator objects, one for (positive) sizes and one for unit square complex values
	// Then: implement addition/subtraction operators, extend rows/columns and other related functions
};