#pragma once
#include "Test.h"
#include "RandomGenerator.h"
#include "Parameters.h"

class TestInputStructs : public Test {
private:
	RandomGenerator randomGenerator;
	const int NUMBER_OF_TESTS = 10; // just checking assignment, not statistics

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