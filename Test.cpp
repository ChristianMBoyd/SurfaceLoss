#include "Test.h"

// Note on error output: convention is to include '\n' at the end of all partial statements [e.g., specific error messages].
//		Errors are then called according to cout << "error: " << error.what(); 

Test::Test() {
	initializeRandomNumberGenerator();
}

void Test::initializeRandomNumberGenerator() {
	unitDistribution = std::uniform_real_distribution<double>(-1.0, 1.0);
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
	double sum = 0;
	bool validValues = true;
	int valuesToTest = 100;
	for (int counter = 0; counter < valuesToTest; counter++) {
		double randomDouble = generateRandomUnitDouble();
		if ((randomDouble > 1) || (randomDouble < -1)){
			validValues = false;
			break;
		}
		sum += randomDouble;
	}
	if (!validValues) {
		throw NumericalError("Test base class generates random doubles outside preset range!\n");
	}
	double average = sum / valuesToTest;
	double tolerance = 0.5;
	bool validAverage = (average > -tolerance) && (average < tolerance);
	if (!validAverage) {
		throw NumericalError("Test base class generates random doubles with average: " + std::to_string(average) + "\n");
	}
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
	std::complex<double> sum = 0;
	bool validValues = true;
	int valuesToTest = 100;
	for (int counter = 0; counter < valuesToTest; counter++) {
		auto randomComplex = generateRandomUnitComplex();
		bool validRealValue = (randomComplex.real() >= -1) && (randomComplex.real() <= 1);
		bool validImagValue = (randomComplex.imag() >= -1) && (randomComplex.imag() <= 1);
		if (!validRealValue || !validImagValue) {
			validValues = false;
			break;
		}
		sum += randomComplex;
	}
	if (!validValues) {
		throw NumericalError("Test base class generates random complexes outside preset range!\n");
	}
	auto average = sum / (1.0 * valuesToTest);
	double tolerance = 0.5;
	bool validRealAverage = (average.real() > -tolerance) && (average.real() < tolerance);
	bool validImagAverage = (average.imag() > -tolerance) && (average.imag() < tolerance);
	if (!validRealAverage || !validImagAverage) {
		throw NumericalError("Test base class generates random complexes with average: (" + std::to_string(average.real()) + ", "
			+ std::to_string(average.imag()) + ")\n");
	}
}

bool Test::twoDoublesAreEqual(double first, double second) {
	return (std::abs(first - second) < DOUBLE_ERROR);
}

bool Test::twoComplexesAreEqual(std::complex<double> leftValue, std::complex<double> rightValue) {
	bool realValuesAreEqual = twoDoublesAreEqual(leftValue.real(), rightValue.real());
	bool imagValuesAreEqual = twoDoublesAreEqual(leftValue.imag(), rightValue.imag());
	return realValuesAreEqual && imagValuesAreEqual;
}

double Test::generateRandomUnitDouble() {
	return unitDistribution(randomEngine);
}

// here, we mean complexes are restricted to lie within the unit *square*, not the unit circle
std::complex<double> Test::generateRandomUnitComplex() {
	double real = generateRandomUnitDouble();
	double imag = generateRandomUnitDouble();
	return std::complex<double>(real, imag);
}