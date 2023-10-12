#pragma once
#include <iostream>
#include "NumericalError.h"

class Test{
private:
	const double DOUBLE_ERROR = 1.0e-12;

protected:
	bool PASSED_TESTS = true;

public:
	Test();
	virtual void runTests();
	bool twoDoublesAreEqual(double first, double second);
};