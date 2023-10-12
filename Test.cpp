#include "Test.h"

// Note on error output: convention is to include \n at the end of all partial statements [e.g., specific error messages].
//		Errors are then called according to cout << "error: " << error.what(); 

Test::Test() {
}

void Test::runTests() {
	std::cout << "Testing...\n";

	testPlanarWavevector();
	testMass();
	testDielectricConstant();
	testModelParameters();

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

void Test::testMass() {
	try {
		massWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct Mass has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool Test::massWorks() {
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

void Test::testDielectricConstant() {
	try {
		dielectricConstantWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct DielectricConstant has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool Test::dielectricConstantWorks() {
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

void Test::testModelParameters() {
	try {
		modelParametersWorks();
	}
	catch (NumericalError error) {
		std::cout << "Struct ModelParameters has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

bool Test::modelParametersWorks() {
	double frequency = 1.1;
	double linewidth = 0.11;
	double plasmaToFermiRatio = 1.2;
	modelParams = ModelParameters(frequency, linewidth, plasmaToFermiRatio);

	bool frequency_Passed = twoDoublesAreEqual(frequency, modelParams.frequency);
	if (!frequency_Passed) {
		throw NumericalError("frequency differs from input!\n");
	}
	bool linewidth_Passed = twoDoublesAreEqual(linewidth, modelParams.linewidth);
	if (!linewidth_Passed) {
		throw NumericalError("linewidth differs from input!\n");
	}
	bool plasmaToFermiRatio_Passed = twoDoublesAreEqual(plasmaToFermiRatio, modelParams.plasmaToFermiRatio);
	if (!plasmaToFermiRatio_Passed) {
		throw NumericalError("plasmaToFermiRatio differs from input!\n");
	}

	return true;
}
