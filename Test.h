#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <complex>
#include <cmath>
#include "NumericalError.h"

class Test{
private:
	const double DOUBLE_ERROR = 1.0e-12;
	std::uniform_real_distribution<double> unitDistribution;
	std::default_random_engine randomEngine;

	void initializeRandomNumberGenerator();

protected:
	bool PASSED_TESTS = true;

public:
	Test();
	virtual void runTests();
	bool twoDoublesAreEqual(double first, double second);
	bool twoComplexesAreEqual(std::complex<double> leftValue, std::complex<double> rightValue);
	double generateRandomUnitDouble();
	std::complex<double> generateRandomUnitComplex();
};