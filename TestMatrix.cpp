#include "TestMatrix.h"
#include "Matrix.h"

TestMatrix::TestMatrix() {}

void TestMatrix::runTests() {
	std::cout << "Testing Matrix class...\n";

	testConstructors();

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
		std::cout << "Class Matrix has failed its tests!  Reason: unspecified constructor error.\n";
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkConstructorFunctions() {
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 0) = 0;
	eigenMatrix(0, 1) = std::complex<double>(1.0, -1.0);
	eigenMatrix(1, 0) = 0.2;
	eigenMatrix(1, 1) = std::complex<double>(-2.5, 1.3);

	linearAlgebraObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	matrix = Matrix(linearAlgebraObject);
	
	matrix = Matrix(2, 2);
	
	Matrix newMatrix;
}