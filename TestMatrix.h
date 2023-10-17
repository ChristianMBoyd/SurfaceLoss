#pragma once
#include "TestLinearAlgebra.h"
#include "Matrix.h"

class TestMatrix : public TestLinearAlgebra {
public:
	TestMatrix();
	void runTests();

	void testConstructors();
};