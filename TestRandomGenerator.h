#pragma once
#include "Test.h"
#include "RandomGenerator.h"

class TestRandomGenerator : public Test{
private:
	const int NUMBER_OF_TESTS = 100;
	const double relativeBiasTolerance = 0.5; // sets tolerance based on randomMax, currently generous measure of statistics
	double bias, biasTolerance, randomMin, randomMax;
	RandomGenerator randomGenerator;

public: 
	TestRandomGenerator();
	TestRandomGenerator(double randomMin, double randomMax);
	void runTests();

private:
	void initializeTestParameters();

	void testRandomDoubles();
	void checkRandomDoubles();
	bool randomDoubleIsValid(double randomDouble);
	bool averageDoubleIsValid(double averageDouble);

	void testRandomComplexes();
	void checkRandomComplexes();
	bool randomComplexIsValid(Complex randomComplex);
	bool averageComplexIsValid(Complex averageComplex);
};