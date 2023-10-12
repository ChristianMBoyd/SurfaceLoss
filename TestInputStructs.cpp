#include "TestInputStructs.h"

TestInputStructs::TestInputStructs() {}

void TestInputStructs::runTests() {
	std::cout << "Testing...\n";

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
		planarWavevectorWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct PlanarWavevector has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool TestInputStructs::planarWavevectorWorks() {
	double qx = 0.1;
	double qy = 0.01;
	double magnitude = std::sqrt(qx * qx + qy * qy);
	qPlanar = PlanarWavevector(qx, qy);

	bool qx_Passed = twoDoublesAreEqual(qx, qPlanar.qx);
	if (!qx_Passed) {
		throw NumericalError("qx differs from input!\n");
	}
	bool qy_Passed = twoDoublesAreEqual(qy, qPlanar.qy);
	if (!qy_Passed) {
		throw NumericalError("qy differs from input!\n");
	}
	bool magnitude_Passed = twoDoublesAreEqual(magnitude, qPlanar.magnitude);
	if (!magnitude_Passed) {
		throw NumericalError("magnitude differs from input!\n");
	}

	return true;
}

void TestInputStructs::testMass() {
	try {
		massWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct Mass has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool TestInputStructs::massWorks() {
	double mx = 0.3;
	double mz = 10.4;
	double my = 1.0 / mx;
	mass = Mass(mx, mz);

	bool mx_Passed = twoDoublesAreEqual(mx, mass.mx);
	if (!mx_Passed) {
		throw NumericalError("mx differs from input!\n");
	}
	bool my_CalculatedCorrectly = twoDoublesAreEqual(my, mass.my);
	if (!my_CalculatedCorrectly) {
		throw NumericalError("my calculated incorrectly from input!\n");
	}
	bool mz_Passed = twoDoublesAreEqual(mz, mass.mz);
	if (!mz_Passed) {
		throw NumericalError("mz differs from input!\n");
	}
	bool normalizedPlanarComponents = twoDoublesAreEqual(1.0, mass.mx * mass.my);
	if (!normalizedPlanarComponents) {
		throw NumericalError("mx and my do not multiply to 1 (unit mass)!\n");
	}

	return true;
}

void TestInputStructs::testDielectricConstant() {
	try {
		dielectricConstantWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct DielectricConstant has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool TestInputStructs::dielectricConstantWorks() {
	double epsx = 13.5;
	double epsy = 18.5;
	double epsz = 8.5;
	eps = DielectricConstant(epsx, epsy, epsz);

	bool epsx_Passed = twoDoublesAreEqual(epsx, eps.epsx);
	if (!epsx_Passed) {
		throw NumericalError("epsx differs from input!\n");
	}
	bool epsy_Passed = twoDoublesAreEqual(epsy, eps.epsy);
	if (!epsy_Passed) {
		throw NumericalError("epsy differs from input!\n");
	}
	bool epsz_Passed = twoDoublesAreEqual(epsz, eps.epsz);
	if (!epsz_Passed) {
		throw NumericalError("epsz differs from input!\n");
	}

	return true;
}

void TestInputStructs::testModelParameters() {
	try {
		modelParametersWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct ModelParameters has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool TestInputStructs::modelParametersWorks() {
	double frequency = 1.1;
	double linewidth = 0.11;
	double plasmaToFermiRatio = 1.2;
	modelParameters = ModelParameters(frequency, linewidth, plasmaToFermiRatio);

	bool frequency_Passed = twoDoublesAreEqual(frequency, modelParameters.frequency);
	if (!frequency_Passed) {
		throw NumericalError("frequency differs from input!\n");
	}
	bool linewidth_Passed = twoDoublesAreEqual(linewidth, modelParameters.linewidth);
	if (!linewidth_Passed) {
		throw NumericalError("linewidth differs from input!\n");
	}
	bool plasmaToFermiRatio_Passed = twoDoublesAreEqual(plasmaToFermiRatio, modelParameters.plasmaToFermiRatio);
	if (!plasmaToFermiRatio_Passed) {
		throw NumericalError("plasmaToFermiRatio differs from input!\n");
	}

	return true;
}

void TestInputStructs::testNumericalParameters() {
	try {
		numericalParametersWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct NumericalParameters has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool TestInputStructs::numericalParametersWorks() {
	double L = 50;
	double cutoffWavevector = 4.5;
	numericalParameters = NumericalParameters(L, cutoffWavevector);

	bool L_Passed = twoDoublesAreEqual(L, numericalParameters.L);
	if (!L_Passed) {
		throw NumericalError("L differs from input!\n");
	}
	bool cutoffWavevector_Passed = twoDoublesAreEqual(cutoffWavevector, numericalParameters.cutoffWavevector);
	if (!cutoffWavevector_Passed) {
		throw NumericalError("cutoffWavevector differs from input!\n");
	}

	return true;
}