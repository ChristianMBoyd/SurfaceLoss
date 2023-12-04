#pragma once
#include "Test.h"
#include "Matrix.h"
#include "RandomGenerator.h"

class TestMatrix : public Test {
private:
	RandomGenerator valueGenerator; // default unit line (complex square)
	RandomGenerator indexGenerator = RandomGenerator(1, 100); // positive values for indices
	const int NUMBER_OF_TESTS = 10; // randomized operation checks
	const int matrixDimension = 10; // suitable number of entries for component-wise checks

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

	void testMatrixProperties();
	void checkSizes();
	void checkSizeAccessibility();


	// Next: implement (and test!) transposeInPlace(), transpose(), and other helpful functions
	// Consider: implementing a string converter to simplify Complex error string generation
};