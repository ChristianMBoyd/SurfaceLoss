#include "TestMatrix.h"
#include "Matrix.h"

TestMatrix::TestMatrix() {}

void TestMatrix::runTests() {
	std::cout << "Testing Matrix class...\n";

	testConstructors();
	testAccessors();
	testEquals();
	testMultiplication();

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

	// Eigen-specific tests
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
		checkAccessors();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAccessors() {
	Matrix matrix(2, 2);
	matrix(0, 0) = std::complex<double>(0, 0);
	matrix(0, 1) = std::complex<double>(0, 1.0);
	matrix(1, 0) = std::complex<double>(1.0, 0);
	matrix(1, 1) = matrix(1, 0) + matrix(0, 1);

	std::complex<double> oneZeroComponent = std::complex<double>(1.0, 0);
	bool assignedCorrectly = twoComplexesAreEqual(oneZeroComponent, matrix(1, 0));
	if (!assignedCorrectly) {
		throw NumericalError("Class Matrix assignment value and recall value are not equal!\n");
	}
}

void TestMatrix::testEquals() {
	try {
		checkEquals();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkEquals() {
	Matrix matrix1(2, 2), matrix2(2, 2);
	matrix1(0, 0) = std::complex<double>(-1.5, 2.0);
	matrix1(0, 1) = std::complex<double>(0, 1.0);
	matrix1(1, 0) = std::complex<double>(1.5, -3);
	matrix1(1, 1) = std::complex<double>(0.5, 5.5);

	matrix2 = matrix1;
	bool matricesAreEqual = (matrix1 == matrix2);
	if (!matricesAreEqual) {
		throw NumericalError("Class Matrix operator== finds two matrices set to another unequal!\n");
	}

	matrix2(1, 0) = std::complex<double>(-2.4, 1.5);
	matricesAreEqual = (matrix2 == matrix1);
	if (matricesAreEqual) {
		throw NumericalError("Class Matrix operator== finds unequal matrices to be equal!\n");
	}
}

void TestMatrix::testMultiplication() {
	try {
		checkScalarMultiplication();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkScalarMultiplication() {
	checkDoubleMultiplication();
	checkComplexMultiplication();
}

void TestMatrix::checkDoubleMultiplication() {
	double scale = 3.56;
	Matrix matrix(2, 2);
	matrix(0, 0) = std::complex<double>(1.5, 1.5);
	matrix(0, 1) = std::complex<double>(0, 3.0);
	matrix(1, 0) = std::complex<double>(3.0, 0);
	matrix(1, 1) = std::complex<double>(-2, -2);

	Matrix productMatrix = scale * matrix;
	Matrix rightProductMatrix = matrix * scale;
	matrix(0, 0) = scale * matrix(0, 0);
	matrix(0, 1) = scale * matrix(0, 1);
	matrix(1, 0) = scale * matrix(1, 0);
	matrix(1, 1) = scale * matrix(1, 1);

	bool productMatricesAreEqual = (matrix == productMatrix);
	if (!productMatricesAreEqual) {
		throw NumericalError("Class Matrix component-wise double multiplication is not equal to matrix multiplication with double!\n");
	}

	bool rightProductWorks = (matrix == rightProductMatrix);
	if (!rightProductWorks) {
		throw NumericalError("Class Matrix scalar multiplication with double does not commute!\n");
	}
}

void TestMatrix::checkComplexMultiplication() {
	auto scalar = std::complex<double>(2.0, -3.0);
	Matrix matrix(2, 2);

	matrix(0, 0) = std::complex<double>(10, -10);
	matrix(0, 1) = std::complex<double>(-2, 2.5);
	matrix(1, 0) = std::complex<double>(1.0, 0.1);
	matrix(1, 1) = std::complex<double>(0.5, -1.5);

	Matrix productMatrix = scalar * matrix;
	Matrix rightProductMatrix = matrix * scalar;

	matrix(0, 0) = scalar * matrix(0, 0);
	matrix(0, 1) = scalar * matrix(0, 1);
	matrix(1, 0) = scalar * matrix(1, 0);
	matrix(1, 1) = scalar * matrix(1, 1);

	bool productWorks = (matrix == productMatrix);
	if (!productWorks) {
		throw NumericalError("Class Matrix component-wise complex multiplication does not equal matrix multiplication!\n");
	}

	bool rightProductWorks = (matrix == rightProductMatrix);
	if (!rightProductWorks) {
		throw NumericalError("Class Matrix multiplication with a complex scalar does not commute!\n");
	}
}