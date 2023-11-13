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
	std::cout << "Testing...\n";

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
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