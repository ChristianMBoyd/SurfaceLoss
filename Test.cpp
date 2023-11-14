#include "Test.h"

// Note on error output: convention is to include '\n' at the end of all partial statements [e.g., specific error messages].
//		Errors are then called according to cout << "error: " << error.what(); 

Test::Test() {
	initializeRandomNumberGenerator();
}

void Test::initializeRandomNumberGenerator() {
	BIAS = (RANDOM_MIN + RANDOM_MAX) / 2.0;
	unitDistribution = std::uniform_real_distribution<double>(RANDOM_MIN, RANDOM_MAX);
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	randomEngine = std::default_random_engine(seed);
}

void Test::runTests() {
	std::cout << "Testing Test base class...\n";

	testRandomDoubleGenerator();
	testRandomComplexGenerator();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void Test::testRandomDoubleGenerator() {
	try {
		checkRandomDoubleGenerator();
	}
	catch (NumericalError error) {
		std::cout << "Class Test has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void Test::checkRandomDoubleGenerator() {
	double averageDouble = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		double randomDouble = generateRandomUnitDouble();
		if (!randomDoubleIsValid(randomDouble)) {
			throw NumericalError("Test base class generates random doubles outside preset range!\n");
		}
		averageDouble += randomDouble;
	}
	averageDouble /= NUMBER_OF_TESTS;
	if (!averageDoubleIsValid(averageDouble)) {
		throw NumericalError("Test base class generates random doubles with average " + std::to_string(averageDouble) + " after " +
			std::to_string(NUMBER_OF_TESTS) + " runs\n");
	}
}

double Test::generateRandomUnitDouble() {
	return unitDistribution(randomEngine);
}

bool Test::randomDoubleIsValid(double randomDouble) {
	return (RANDOM_MIN < randomDouble) && (randomDouble < RANDOM_MAX);
}

bool Test::averageDoubleIsValid(double averageDouble) {
	return (BIAS - BIAS_TOLERANCE < averageDouble) && (averageDouble < BIAS + BIAS_TOLERANCE);
}

void Test::testRandomComplexGenerator() {
	try {
		checkRandomComplexGenerator();
	}
	catch (NumericalError error) {
		std::cout << "Class Test has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void Test::checkRandomComplexGenerator() {
	Complex averageComplex = 0;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		auto randomComplex = generateRandomUnitComplex();
		if (!randomComplexIsValid(randomComplex)) {
			throw NumericalError("Test base class generates random complexes outside preset range!\n");
		}
		averageComplex += randomComplex;
	}
	averageComplex /= NUMBER_OF_TESTS;
	if (!averageComplexIsValid(averageComplex)) {
		throw NumericalError("Test base class generates random complexes with average: (" + std::to_string(averageComplex.real()) + ", "
			+ std::to_string(averageComplex.imag()) + ") after " + std::to_string(NUMBER_OF_TESTS) + " runs\n");
	}
}

// here, we mean complexes are restricted to lie within the unit *square*, not the unit circle
Complex Test::generateRandomUnitComplex() {
	double real = generateRandomUnitDouble();
	double imag = generateRandomUnitDouble();
	return Complex(real, imag);
}

bool Test::randomComplexIsValid(Complex randomComplex) {
	bool realIsValid = randomDoubleIsValid(randomComplex.real());
	bool imagIsValid = randomDoubleIsValid(randomComplex.imag());
	return realIsValid && imagIsValid;
}

bool Test::averageComplexIsValid(Complex averageComplex) {
	bool realAverageIsValid = averageDoubleIsValid(averageComplex.real());
	bool imagAverageIsValid = averageDoubleIsValid(averageComplex.imag());
	return realAverageIsValid && imagAverageIsValid;
}

bool Test::twoDoublesAreEqual(double first, double second) {
	return (std::abs(first - second) < DOUBLE_ERROR);
}

bool Test::twoComplexesAreEqual(Complex leftValue, Complex rightValue) {
	bool realValuesAreEqual = twoDoublesAreEqual(leftValue.real(), rightValue.real());
	bool imagValuesAreEqual = twoDoublesAreEqual(leftValue.imag(), rightValue.imag());
	return realValuesAreEqual && imagValuesAreEqual;
}