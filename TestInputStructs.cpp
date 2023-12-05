#include "TestInputStructs.h"

TestInputStructs::TestInputStructs() {}

void TestInputStructs::runTests() {
	std::cout << "Testing input structs...\n";

	testPlanarWavevector();
	testMass();
	testDielectricConstant();
	testModelParameters();
	testNumericalParameters();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void TestInputStructs::testPlanarWavevector() {
	try {
		checkPlanarWavevectorFunctions();
	}
	catch (Exception& exception) {
		std::cout << "Struct PlanarWavevector has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestInputStructs::checkPlanarWavevectorFunctions() {
	randomGenerator = RandomGenerator(); // values centered at 0
	double qx, qy, magnitude;
	PlanarWavevector q;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		qx = randomGenerator.randomDouble();
		qy = randomGenerator.randomDouble();
		magnitude = std::sqrt(qx * qx + qy * qy);
		q = PlanarWavevector(qx, qy);
		if (!twoDoublesAreEqual(qx, q.qx)) {
			throw NumericalError("q.qx", q.qx, qx);
		}
		if (!twoDoublesAreEqual(qy, q.qy)) {
			throw NumericalError("q.qy", q.qy, qy);
		}
		if (!twoDoublesAreEqual(magnitude, q.magnitude)) {
			throw NumericalError("q.magnitude", q.magnitude, magnitude);
		}
	}
}

void TestInputStructs::testMass() {
	try {
		checkMassFunctions();
	}
	catch (Exception& exception) {
		std::cout << "Struct Mass has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestInputStructs::checkMassFunctions() {
	randomGenerator = RandomGenerator(0, 100); // positive values, reasonable range
	double mx, mz;
	Mass mass;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		mx = randomGenerator.randomDouble();
		mz = randomGenerator.randomDouble();
		mass = Mass(mx, mz);
		if (!twoDoublesAreEqual(mx, mass.mx)) {
			throw NumericalError("mass.mx", mass.mx, mx);
		}
		if (!twoDoublesAreEqual(mz, mass.mz)) {
			throw NumericalError("mass.mz", mass.mz, mz);
		}
		if (!twoDoublesAreEqual(1.0, mass.mx * mass.my)) {
			throw NumericalError("mass.my = " + stringConverter.toString(mass.my)
				+ " is not normalized according to mass.mx * mass.my = 1!\n");
		}
	}
}

void TestInputStructs::testDielectricConstant() {
	try {
		checkDielectricConstantFunctions();
	}
	catch (Exception& exception) {
		std::cout << "Struct DielectricConstant has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestInputStructs::checkDielectricConstantFunctions() {
	randomGenerator = RandomGenerator(1, 100); // realistic, non-vacuum values
	double epsx, epsy, epsz;
	DielectricConstant eps;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		epsx = randomGenerator.randomDouble();
		epsy = randomGenerator.randomDouble();
		epsz = randomGenerator.randomDouble();
		eps = DielectricConstant(epsx, epsy, epsz);
		if (!twoDoublesAreEqual(epsx, eps.epsx)) {
			throw NumericalError("eps.epsx", eps.epsx, epsx);
		}
		if (!twoDoublesAreEqual(epsy, eps.epsy)) {
			throw NumericalError("eps.epsy", eps.epsy, epsy);
		}
		if (!twoDoublesAreEqual(epsz, eps.epsz)) {
			throw NumericalError("eps.epsz", eps.epsz, epsz);
		}
	}
}

void TestInputStructs::testModelParameters() {
	try {
		checkModelParametersFunctions();
	}
	catch (Exception& exception) {
		std::cout << "Struct ModelParameters has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestInputStructs::checkModelParametersFunctions() {
	randomGenerator = RandomGenerator(0, 10); // reasonable (other than linewidth), positive values
	double frequency, linewidth, plasmaToFermiRatio;
	ModelParameters modelParameters;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		frequency = randomGenerator.randomDouble();
		linewidth = randomGenerator.randomDouble();
		plasmaToFermiRatio = randomGenerator.randomDouble();
		modelParameters = ModelParameters(frequency, linewidth, plasmaToFermiRatio);
		if (!twoDoublesAreEqual(frequency, modelParameters.frequency)) {
			throw NumericalError("modelParameters.frequency", modelParameters.frequency, frequency);
		}
		if (!twoDoublesAreEqual(linewidth, modelParameters.linewidth)) {
			throw NumericalError("modelParameters.linewidth", modelParameters.linewidth, linewidth);
		}
		if (!twoDoublesAreEqual(plasmaToFermiRatio, modelParameters.plasmaToFermiRatio)) {
			throw NumericalError("modelParameters.plasmaToFermiRatio", modelParameters.plasmaToFermiRatio, plasmaToFermiRatio);
		}
	}
}

void TestInputStructs::testNumericalParameters() {
	try {
		checkNumericalParametersFunctions();
	}
	catch (Exception& exception) {
		std::cout << "Struct NumericalParameters has failed its tests.  \nReason: ";
		std::cout << exception.what();
		PASSED_TESTS = false;
	}
}

void TestInputStructs::checkNumericalParametersFunctions() {
	randomGenerator = RandomGenerator(1, 100); // realistic, positive values
	double L, cutoffWavevector;
	NumericalParameters numericalParameters;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		L = randomGenerator.randomDouble();
		cutoffWavevector = randomGenerator.randomDouble();
		numericalParameters = NumericalParameters(L, cutoffWavevector);
		if (!twoDoublesAreEqual(L, numericalParameters.L)) {
			throw NumericalError("numericalParameters.L", numericalParameters.L, L);
		}
		if (!twoDoublesAreEqual(cutoffWavevector, numericalParameters.cutoffWavevector)) {
			throw NumericalError("numericalParameters.cutoffWavevector", numericalParameters.cutoffWavevector,
				cutoffWavevector);
		}
	}
}