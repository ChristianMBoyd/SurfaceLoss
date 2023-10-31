#pragma once
#include "Test.h"
#include "Matrix.h"

class TestMatrix : public Test {
public:
	TestMatrix();
	void runTests();

private:
	void testConstructors();
	void checkConstructorFunctions();

	void testAccessors();
	void checkAccessorRecall();
	void checkAccessorAssignment();
};