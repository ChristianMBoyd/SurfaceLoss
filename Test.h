#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <cmath>
#include "Complex.h"
#include "NumericalError.h"

class Test{
public: 
	Test();
	virtual void runTests();
	double generateRandomUnitDouble(); // defined below checkRandomDoubleGenerator()
	Complex generateRandomUnitComplex(); // defined below checkRandomComplexGenerator()
	bool twoDoublesAreEqual(double first, double second);
	bool twoComplexesAreEqual(Complex leftValue, Complex rightValue);

private:
	const double DOUBLE_ERROR = 1.0e-12, BIAS_TOLERANCE = 0.5;
	const int NUMBER_OF_TESTS = 100, RANDOM_MIN = -1, RANDOM_MAX = 1;
	double BIAS;
	std::uniform_real_distribution<double> unitDistribution;
	std::default_random_engine randomEngine;

	void initializeRandomNumberGenerator();

	void testRandomDoubleGenerator();
	void checkRandomDoubleGenerator();
	bool randomDoubleIsValid(double randomDouble);
	bool averageDoubleIsValid(double averageDouble);

	void testRandomComplexGenerator();
	void checkRandomComplexGenerator();
	bool randomComplexIsValid(Complex randomComplex);
	bool averageComplexIsValid(Complex averageComplex);

protected:
	bool PASSED_TESTS = true;
};