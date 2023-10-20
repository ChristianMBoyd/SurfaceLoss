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

	void testOperatorOverloads();
	void checkAddition();
	void checkSubtraction();
	void checkScalarMultiplication();
	void checkMatrixMultiplication();
	void checkEquality();

	void testPropertyFunctions();
	void checkDimensions();
	void checkIsEqualToDoublePrecision();

	void testManipulationFunctions();
	void checkAccessors();
	void checkTransposeInPlace();
	void checkTranspose();
};