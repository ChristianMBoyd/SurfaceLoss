#pragma once
#include <iostream>
#include "Complex.h"
#include "NumericalError.h"

class Test {
private:
	const double DOUBLE_ERROR = 1.0e-12;

protected:
	bool PASSED_TESTS = true; // a test must actively fail to flag an error, default is passing
	
public:
	Test();
	virtual void runTests();
	bool twoDoublesAreEqual(double first, double second);
	bool twoComplexesAreEqual(Complex leftValue, Complex rightValue);
};