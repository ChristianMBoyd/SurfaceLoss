#pragma once
#include <iostream>
#include "PlanarWavevector.h"
#include "NumericalError.h"
#include "Mass.h"
#include "DielectricConstant.h"
#include "ModelParameters.h"

class Test{
private:
	PlanarWavevector qPlanar;
	Mass mass;
	DielectricConstant eps;
	ModelParameters modelParams;

	const double DOUBLE_ERROR = 1.0e-12;
	bool PASSED_TESTS = true;

public:
	Test();
	void runTests();
	bool twoDoublesAreEqual(double first, double second);

	void testPlanarWavevector();
	bool planarWavevectorWorks();

	void testMass();
	bool massWorks();

	void testDielectricConstant();
	bool dielectricConstantWorks();

	void testModelParameters();
	bool modelParametersWorks();
};