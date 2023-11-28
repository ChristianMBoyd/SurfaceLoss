#pragma once
#include "Test.h"
#include "Matrix.h"
#include "RandomGenerator.h"

class TestMatrix : public Test {
private:
	RandomGenerator valueGenerator; // default unit line (complex square)
	RandomGenerator indexGenerator = RandomGenerator(1, 100); // positive values for indices
	const int NUMBER_OF_ASSIGNMENT_TESTS = 10, NUMBER_OF_OPERATION_TESTS = 100; // more concerned with mathematical operations

public:
	TestMatrix();
	void runTests();

private:
	void testConstructors();
	void checkConstructorFunctions();

	void testAccessors();
	void checkAccessors();

	Matrix randomMatrix(unsigned int rows, unsigned int columns);
	Matrix randomMatrix();
	void testRandomMatrix();
	void checkRandomMatrix();

	void testEquals();
	void checkEquals();
	void checkIsNotEquals();

	void testScalarMultiplication();
	void checkIntMultiplication();
	void checkDoubleMultiplication();
	void checkComplexMultiplication();

	void testAddition();
	void checkAddition();

	void testSubtraction();
	void checkSubtraction();

	void testMatrixMultiplication();
	void checkMatrixMultiplication();

	// Next: think up reasonable tests of matrix multiplication, then implement
	// Then: extend rows(), columns(), size(), and other helpful functions
};