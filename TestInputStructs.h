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
	Parameters parameters; // only a struct of default-constructed above objects

public:
	TestInputStructs();
	void runTests();

	void testPlanarWavevector();
	void checkPlanarWavevectorFunctions();

	void testMass();
	void checkMassFunctions();

	void testDielectricConstant();
	void checkDielectricConstantFunctions();

	void testModelParameters();
	void checkModelParametersFunctions();

	void testNumericalParameters();
	void checkNumericalParametersFunctions();
};