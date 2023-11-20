#include "TestRandomGenerator.h"

TestRandomGenerator::TestRandomGenerator() : randomMin(-1.0), randomMax(1.0) {
	initializeTestParameters();
}

TestRandomGenerator::TestRandomGenerator(double randomMin, double randomMax) : randomMin(randomMin), randomMax(randomMax) {
	if (randomMax < randomMin) {
		this->randomMin = randomMax;
		this->randomMax = randomMin;
	}
	initializeTestParameters();
}

void TestRandomGenerator::initializeTestParameters() {
	bias = (randomMin + randomMax) / 2;
	biasTolerance = relativeBiasTolerance * std::abs(randomMax);
}


void TestRandomGenerator::runTests() {
	std::cout << "Testing RandomGenerator class...\n";

	testRandomDoubles();
	testRandomComplexes();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void TestRandomGenerator::testRandomDoubles() {
	try {
		checkRandomDoubles();
	}
	catch (NumericalError error) {
		std::cout << "Class RandomGenerator has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestRandomGenerator::checkRandomDoubles() {
	double averageDouble = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		double randomDouble = randomGenerator.randomDouble();
		if (!randomDoubleIsValid(randomDouble)) {
			throw NumericalError("RandomGenerator generates random doubles outside preset range!\n");
		}
		averageDouble += randomDouble;
	}
	averageDouble /= NUMBER_OF_TESTS;
	if (!averageDoubleIsValid(averageDouble)) {
		throw NumericalError("RandomGenerator generates random doubles with average " + std::to_string(averageDouble) + " after " +
			std::to_string(NUMBER_OF_TESTS) + " runs\n");
	}
}

bool TestRandomGenerator::randomDoubleIsValid(double randomDouble) {
	return (randomMin < randomDouble) && (randomDouble < randomMax);
}

bool TestRandomGenerator::averageDoubleIsValid(double averageDouble) {
	return (bias - biasTolerance < averageDouble) && (averageDouble < bias + biasTolerance);
}

void TestRandomGenerator::testRandomComplexes() {
	try {
		checkRandomComplexes();
	}
	catch (NumericalError error) {
		std::cout << "Class RandomGenerator has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestRandomGenerator::checkRandomComplexes() {
	Complex averageComplex = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		auto randomComplex = randomGenerator.randomComplex();
		if (!randomComplexIsValid(randomComplex)) {
			throw NumericalError("RandomGenerator generates random complexes outside preset range!\n");
		}
		averageComplex += randomComplex;
	}
	averageComplex /= NUMBER_OF_TESTS;
	if (!averageComplexIsValid(averageComplex)) {
		throw NumericalError("RandomGenerator generates random complexes with average: (" + std::to_string(averageComplex.real()) + ", "
			+ std::to_string(averageComplex.imag()) + ") after " + std::to_string(NUMBER_OF_TESTS) + " runs\n");
	}
}

bool TestRandomGenerator::randomComplexIsValid(Complex randomComplex) {
	bool realIsValid = randomDoubleIsValid(randomComplex.real());
	bool imagIsValid = randomDoubleIsValid(randomComplex.imag());
	return realIsValid && imagIsValid;
}

bool TestRandomGenerator::averageComplexIsValid(Complex averageComplex) {
	bool realAverageIsValid = averageDoubleIsValid(averageComplex.real());
	bool imagAverageIsValid = averageDoubleIsValid(averageComplex.imag());
	return realAverageIsValid && imagAverageIsValid;
}