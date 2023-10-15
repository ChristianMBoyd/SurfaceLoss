#pragma once
#include "Test.h"
#include "LinearAlgebraObject.h"

class TestLinearAlgebra : public Test {
private:
	LinearAlgebraObject linearAlgebraObject;

public:
	TestLinearAlgebra();
	void runTests();

	void testOperatorOverloads();
	void checkOperatorOverloadFunctions();
	void checkCopyAssignment();
};