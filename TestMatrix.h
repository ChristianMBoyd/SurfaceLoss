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

	
	// To do: implement below!
	void testOperatorsOverloads();
	void testAdditionalFunctions();
};