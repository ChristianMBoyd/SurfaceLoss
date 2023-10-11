#pragma once
#include <iostream>
#include "PlanarWavevector.h"
#include "NumericalError.h"

class Test{
private:
	bool PASSED_TESTS = true;
	PlanarWavevector qPlanar;
	double DOUBLE_ERROR = 1.0e-12;

public:
	Test();
	void runTests();
	void testPlanarWavevector();
	bool planarWavevectorWorks();
};