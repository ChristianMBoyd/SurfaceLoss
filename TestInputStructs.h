#pragma once
#include "Test.h"
#include "Parameters.h"

class TestInputStructs : public Test {
private:
	PlanarWavevector qPlanar;
	Mass mass;
	DielectricConstant eps;
	ModelParameters modelParameters;
	NumericalParameters numericalParameters;
	Parameters parameters;

public:
	TestInputStructs();
	void runTests();

	void testPlanarWavevector();
	bool planarWavevectorWorks();

	void testMass();
	bool massWorks();

	void testDielectricConstant();
	bool dielectricConstantWorks();

	void testModelParameters();
	bool modelParametersWorks();

	void testNumericalParameters();
	bool numericalParametersWorks();
};