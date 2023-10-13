#include "TestLinearAlgebra.h"

TestLinearAlgebra::TestLinearAlgebra() {}

void TestLinearAlgebra::runTests() {
	std::cout << "Testing linear algebra implementation...\n";

	// fill in

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void TestLinearAlgebra::testOperatorOverloads() {
	try {
		checkOperatorOverloadFunctions();
	}
	catch (NumericalError error) {
		std::cout << "Struct PlanarWavevector has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestLinearAlgebra::checkOperatorOverloadFunctions() {
	// implement tests
}