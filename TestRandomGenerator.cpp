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
	randomGenerator = RandomGenerator(randomMin, randomMax);
}


void TestRandomGenerator::runTests() {
	std::cout << "Testing RandomGenerator class...\n";

	testRandomDoubles();
	testRandomInts();
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
	catch (Exception& exception) {
		std::cout << "Class RandomGenerator has failed its tests.  \nReason: ";
		std::cout << exception.what();
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
			std::to_string(NUMBER_OF_TESTS) + " runs!\n");
	}
}

bool TestRandomGenerator::randomDoubleIsValid(double randomDouble) {
	return (randomMin < randomDouble) && (randomDouble < randomMax);
}

bool TestRandomGenerator::averageDoubleIsValid(double averageDouble) {
	return (bias - biasTolerance < averageDouble) && (averageDouble < bias + biasTolerance);
}

void TestRandomGenerator::testRandomInts() {
	try {
		checkRandomInts();
	}
	catch (Exception& exception) {
		std::cout << "Class RandomGenerator has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestRandomGenerator::checkRandomInts() {
	double average = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		int randomInt = randomGenerator.randomInt();
		if (!randomIntIsValid(randomInt)) {
			throw NumericalError("RandomGenerator generates random ints outside preset range!\n");
		}
		average += randomInt;
	}
	average /= NUMBER_OF_TESTS;
	if (!averageIntIsValid(average)) {
		throw NumericalError("RandomGenerator generates ints with (double) average " + std::to_string(average) + " after "
			+ std::to_string(NUMBER_OF_TESTS) + " runs!\n");
	}
}

bool TestRandomGenerator::randomIntIsValid(int randomInt) {
	bool isUpperBound = (randomInt == int(randomMax));
	bool isLowerBound = (randomInt == int(randomMin));
	if (isUpperBound || isLowerBound) {
		return true;
	}
	return randomDoubleIsValid(randomInt); // defer to double testing within bounds
}

bool TestRandomGenerator::averageIntIsValid(int averageInt) {
	return averageDoubleIsValid(averageInt); // defer to double testing
}

bool TestRandomGenerator::averageIntIsValid(double averageInt) {
	return averageDoubleIsValid(averageInt); // defer to double testing
}

void TestRandomGenerator::testRandomComplexes() {
	try {
		checkRandomComplexes();
	}
	catch (Exception& exception) {
		std::cout << "Class RandomGenerator has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestRandomGenerator::checkRandomComplexes() {
	Complex averageComplex = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		Complex randomComplex = randomGenerator.randomComplex();
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