#pragma once
#include <iostream>
#include "Complex.h"
#include "NumericalError.h"
#include "StringConverter.h"

// basic testing utils, specific tests should be inherited

class Test {
private:
	const double DOUBLE_ERROR = 1.0e-12;

protected:
	bool PASSED_TESTS = true; // a test must actively fail to flag an error, default is passing
	StringConverter stringConverter;
	
public:
	Test();
	virtual void runTests();
	bool twoDoublesAreEqual(double first, double second);
	bool twoComplexesAreEqual(Complex leftValue, Complex rightValue);
};