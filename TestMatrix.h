#pragma once
#include "TestLinearAlgebra.h"
#include "Matrix.h"

class TestMatrix : public TestLinearAlgebra {
protected:
	Matrix matrix;
public:
	TestMatrix();
	void runTests();

private:
	void testConstructors();
	void checkConstructorFunctions();

	
	// To do: fill in below!
	void testOperatorOverloads();
	void checkAddition();
	void checkSubtraction();
	void checkScalarMultiplication();
	void checkMatrixMultiplication();
	void checkEquality();

	void testAdditionalFunctions();
	void checkAccessors();
	void checkDimensions();
	void checkIsEqualToDoublePrecision();

	// To do: fill in checkEquality() and checkIsEqualToDoublePrecision() for respective tests
};