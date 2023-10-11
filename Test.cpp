#include "Test.h"


Test::Test() {
}

void Test::runTests() {
	std::cout << "Testing...\n";

	testPlanarWavevector();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "Some tests did not pass.\n";
	}
}

void Test::testPlanarWavevector() {
	try {
		planarWavevectorWorks();
	}

	catch(NumericalError error) {
		std::cout << "Struct PlanarWavevector has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool Test::planarWavevectorWorks() {
	double qx = 0.1;
	double qy = 0.01;
	double magnitude = std::sqrt(qx * qx + qy * qy);

	qPlanar = PlanarWavevector(qx, qy);
	double difference = std::abs(qPlanar.magnitude - magnitude);

	NumericalError differenceIsTooLarge;
	if (difference > DOUBLE_ERROR) {
		throw differenceIsTooLarge;
		return false;
	}
	return true;
}
