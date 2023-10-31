#include "TestMatrix.h"
#include "Matrix.h"

TestMatrix::TestMatrix() {}

void TestMatrix::runTests() {
	std::cout << "Testing Matrix class...\n";

	testConstructors();
	testAccessors();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void TestMatrix::testConstructors() {
	try {
		checkConstructorFunctions();
	}
	catch (...) {
		std::cout << "Class Matrix has failed its tests!  Reason: unspecified constructor error (possibly Eigen-dependent).\n";
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkConstructorFunctions() {
	Matrix defaultMatrix;
	Matrix rowsAndColsMatrix(2, 60);
	
	// Eigen-specific from this point on
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 0) = std::complex<double>(1, 1);
	eigenMatrix(1, 0) = 2.0 * eigenMatrix(0, 0);
	eigenMatrix(0, 1) = std::complex<double>(-1, 1) * eigenMatrix(1, 0);
	eigenMatrix(1, 1) = -eigenMatrix(0, 0);

	Matrix eigenConstructedMatrix(eigenMatrix);
	Matrix scalarEigenExpressionMatrix(std::complex<double>(0.2, -1.5) * eigenMatrix);
	Matrix eigenExpressionMatrix(eigenMatrix * eigenMatrix - eigenMatrix);
}

void TestMatrix::testAccessors() {
	try {
		checkAccessorRecall();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAccessorRecall() {
	// finish, then implement checkAccessorAssignment()
	// do these before establishing an operator== test, so on and so forth
}