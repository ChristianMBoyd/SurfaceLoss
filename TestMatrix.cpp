#include "TestMatrix.h"
#include "Matrix.h"

TestMatrix::TestMatrix() {}

void TestMatrix::runTests() {
	std::cout << "Testing Matrix class...\n";

	testConstructors();
	testOperatorOverloads();
	testPropertyFunctions();
	testManipulationFunctions();
	testVectorFeatures();

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

void TestMatrix::testOperatorOverloads() {
	try {
		checkAddition();
		checkSubtraction();
		checkScalarMultiplication();
		checkMatrixMultiplication();
		checkEquality();
	}

	catch (NumericalError e) {
		std::cout << "Class Matrix has failed its tests.  Reason: " << e.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAddition() {
	Eigen::MatrixXcd eigenMatrix(2, 2), secondEigenMatrix(2, 2);
	eigenMatrix(0, 0) = std::complex<double>(1.0, -1.0);
	eigenMatrix(0, 1) = 2.0;
	eigenMatrix(1, 0) = -2.0;
	eigenMatrix(1, 1) = std::complex<double>(-1.0, 1.0);
	secondEigenMatrix = 2.1 * eigenMatrix;

	LinearAlgebraObject firstObject, secondObject, sumObject;
	firstObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	secondObject = LinearAlgebraObject::createFromEigenObject(secondEigenMatrix);
	sumObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix + secondEigenMatrix);

	Matrix firstMatrix(firstObject), secondMatrix(secondObject), sumMatrix(sumObject);
	
	bool additionWorks = (firstMatrix + secondMatrix == sumMatrix);
	if (!additionWorks) {
		throw NumericalError("sum of Matrix objects differs from Matrix constructed from sum!\n");
	}
}

void TestMatrix::checkSubtraction() {
	Eigen::MatrixXcd eigenMatrix(2, 2), secondEigenMatrix(2, 2);
	eigenMatrix(0, 0) = std::complex<double>(-1.0, -1.0);
	eigenMatrix(0, 1) = 1.1;
	eigenMatrix(1, 0) = -2.6;
	eigenMatrix(1, 1) = std::complex<double>(-1.2, 0.01);
	secondEigenMatrix = 1.5 * eigenMatrix;

	LinearAlgebraObject firstObject, secondObject, diffObject;
	firstObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	secondObject = LinearAlgebraObject::createFromEigenObject(secondEigenMatrix);
	diffObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix - secondEigenMatrix);

	Matrix firstMatrix(firstObject), secondMatrix(secondObject), diffMatrix(diffObject);

	bool subtractionWorks = (firstMatrix - secondMatrix == diffMatrix);
	if (!subtractionWorks) {
		throw NumericalError("subtracting two Matrix objects differs from a Matrix constructed from the difference!\n");
	}
}

void TestMatrix::checkScalarMultiplication() {
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 1) = std::complex<double>(-1.0, -1.0);
	eigenMatrix(0, 0) = 1.1;
	eigenMatrix(1, 1) = -2.6;
	eigenMatrix(1, 0) = std::complex<double>(-1.2, 0.01);

	auto complexScalar = std::complex<double>(-1.54, 0.08345);
	
	LinearAlgebraObject object, multObject;
	object = LinearAlgebraObject::createFromEigenObject(eigenMatrix);

	Matrix matrix(object), multMatrix(complexScalar * object);

	bool scalarMultiplicationWorks = (complexScalar * matrix == multMatrix);
	if (!scalarMultiplicationWorks) {
		throw NumericalError("scalar multiplication of a Matrix object does not equal scalar multiplication of the underlying matrix!\n");
	}
}

void TestMatrix::checkMatrixMultiplication() {
	Eigen::MatrixXcd eigenMatrix(2, 2), secondEigenMatrix(2, 2);
	eigenMatrix(0, 1) = std::complex<double>(-1.0, -1.0);
	eigenMatrix(0, 0) = 1.1;
	eigenMatrix(1, 1) = -2.6;
	eigenMatrix(1, 0) = std::complex<double>(-1.2, 0.01);
	secondEigenMatrix(1, 1) = std::complex<double>(-1.0, -1.0);
	secondEigenMatrix(1, 0) = std::complex<double>(0.01, 1.05);
	secondEigenMatrix(0, 1) = std::complex<double>(1.05, -2.1);
	secondEigenMatrix(0, 0) = std::complex<double>(-1.2, 0.01);

	LinearAlgebraObject firstObject, secondObject, multObject;
	firstObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	secondObject = LinearAlgebraObject::createFromEigenObject(secondEigenMatrix);
	multObject = LinearAlgebraObject::createFromEigenObject(eigenMatrix * secondEigenMatrix);

	Matrix firstMatrix(firstObject), secondMatrix(secondObject), multMatrix(multObject);

	bool matrixMultiplicationWorks = (firstMatrix * secondMatrix == multMatrix);
	if (!matrixMultiplicationWorks) {
		throw NumericalError("multplication of Matrix objects does not equal underlying matrix product!\n");
	}
}

void TestMatrix::checkEquality() {
	Eigen::MatrixXcd eigenMatrix1(2, 2), eigenMatrix2(2, 2);
	eigenMatrix1(0, 0) = std::complex<double>(-2.0, 1.5);
	eigenMatrix1(0, 1) = 5.5;
	eigenMatrix1(1, 0) = -eigenMatrix1(0, 0);
	eigenMatrix1(1, 1) = eigenMatrix1(1, 0) + eigenMatrix1(0, 1);

	auto object1 = LinearAlgebraObject::createFromEigenObject(eigenMatrix1);
	auto object2 = LinearAlgebraObject::createFromEigenObject(eigenMatrix2);

	Matrix matrix1(object1), matrix2(object2);

	bool sameMatricesAreEqual = (matrix1 == 1.0 * matrix1);
	if (!sameMatricesAreEqual) {
		throw NumericalError("Matrix::operator== does not return equality on 1.0*Matrix!\n");
	}
	bool differentMatricesAreEqual = (matrix1 == matrix2);
	if (differentMatricesAreEqual) {
		throw NumericalError("Matrix::opeartor== declares to Matrix objects equal with unequal underlying matrices!\n");
	}
}

void TestMatrix::testPropertyFunctions() {
	try {
		checkDimensions();
		checkIsEqualToDoublePrecision();
	}

	catch (NumericalError e) {
		std::cout << "Class Matrix has failed its tests.  Reason: " << e.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkDimensions() {
	Eigen::MatrixXcd eigenMatrix(23, 15);
	auto object = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	Matrix matrix(object);

	bool rowsWorks = (matrix.numberOfRows() == eigenMatrix.rows());
	if (!rowsWorks) {
		throw NumericalError("Matrix::numberOfRows() returns a value different than the underlying matrix!\n");
	}
	bool colsWorks = (matrix.numberOfColumns() == eigenMatrix.cols());
	if (!colsWorks) {
		throw NumericalError("Matrix::numberofColumns() returns a value different than the underlying matrix!\n");
	}
	bool sizeWorks = (matrix.size() == eigenMatrix.size());
	if (!sizeWorks) {
		throw NumericalError("Matrix::size() does not equal the size (rows * columns) of the underlying matrix!\n");
	}
}
void TestMatrix::checkIsEqualToDoublePrecision() {
	Eigen::MatrixXcd eigenMatrix1(2, 2), eigenMatrix2(2, 2);
	eigenMatrix1(0, 0) = std::complex<double>(1.0, -0.5);
	eigenMatrix1(0, 1) = -1.5;
	eigenMatrix1(1, 0) = -eigenMatrix1(0, 0);
	eigenMatrix1(1, 1) = eigenMatrix1(1, 0) + eigenMatrix1(0, 1);

	auto object1 = LinearAlgebraObject::createFromEigenObject(eigenMatrix1);
	auto object2 = LinearAlgebraObject::createFromEigenObject(eigenMatrix2);

	Matrix matrix1(object1), matrix2(object2);

	bool sameMatricesAreEqual = matrix1.isEqualToDoublePrecision(1.0 * matrix1);
	if (!sameMatricesAreEqual) {
		throw NumericalError("a Matrix object does not equal itself * 1.0!\n");
	}
	bool differentMatricesAreEqual = matrix1.isEqualToDoublePrecision(matrix2);
	if (differentMatricesAreEqual) {
		throw NumericalError("two Matrix objects are deemed equal with unequal underlying matrices!\n");
	}
}

void TestMatrix::testManipulationFunctions() {
	try {
		checkAccessors();
		checkTransposeInPlace();
		checkTranspose();
	}

	catch (NumericalError e) {
		std::cout << "Class Matrix has failed its tests.  Reason: " << e.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAccessors() {
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 0) = std::complex<double>(1.0, 1.0);
	eigenMatrix(0, 1) = std::complex<double>(-1.0, 1.0);
	eigenMatrix(1, 0) = std::complex<double>(1.0, -1.0);
	eigenMatrix(1, 1) = std::complex<double>(-1.0, -1.0);

	LinearAlgebraObject object = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	Matrix matrix(object);

	Eigen::MatrixXcd eigenComparison(2, 2);
	eigenComparison(0, 0) = matrix(0, 0);
	eigenComparison(0, 1) = matrix(0, 1);
	eigenComparison(1, 0) = matrix(1, 0);
	eigenComparison(1, 1) = matrix(1, 1);

	bool returnValuesWork = eigenComparison.isApprox(eigenMatrix);
	if (!returnValuesWork) {
		throw NumericalError("Matrix::operator() does not return the correct values!\n");
	}

	// assign new values and check against
	matrix(0, 0) = 2.0 * eigenMatrix(0, 0);
	matrix(0, 1) = 2.0 * eigenMatrix(0, 1);
	matrix(1, 0) = 2.0 * eigenMatrix(1, 0);
	matrix(1, 1) = 2.0 * eigenMatrix(1, 1);

	eigenMatrix = 2.0 * eigenMatrix;
	eigenComparison(0, 0) = matrix(0, 0);
	eigenComparison(0, 1) = matrix(0, 1);
	eigenComparison(1, 0) = matrix(1, 0);
	eigenComparison(1, 1) = matrix(1, 1);

	bool assignmentWorks = eigenComparison.isApprox(eigenMatrix);
	if (!assignmentWorks) {
		throw NumericalError("Matrix::operator() does not assign values to underlying matrix correctly!\n");
	}
}

void TestMatrix::checkTransposeInPlace() {
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 0) = 0;
	eigenMatrix(0, 1) = std::complex<double>(0, 1.0);
	eigenMatrix(1, 0) = std::complex<double>(1, 0);
	eigenMatrix(1, 1) = std::complex<double>(1, 1);
	Eigen::MatrixXcd eigenTransposedMatrix = eigenMatrix.transpose();

	auto object = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	auto transposedObject = LinearAlgebraObject::createFromEigenObject(eigenTransposedMatrix);

	Matrix matrix(object), transposedMatrix(transposedObject);

	matrix.transposeInPlace();
	bool matrixIsEqualAfterTransposing = (matrix == transposedMatrix);
	if (!matrixIsEqualAfterTransposing) {
		throw NumericalError("Matrix::transposeInPlace() results in an underlying matrix that was not correctly transposed!\n");
	}
}

void TestMatrix::checkTranspose() {
	Eigen::MatrixXcd eigenMatrix(2, 2);
	eigenMatrix(0, 0) = 0;
	eigenMatrix(0, 1) = std::complex<double>(0, 1.0);
	eigenMatrix(1, 0) = std::complex<double>(1, 0);
	eigenMatrix(1, 1) = std::complex<double>(1, 1);
	Eigen::MatrixXcd eigenTransposedMatrix = eigenMatrix.transpose();

	auto object = LinearAlgebraObject::createFromEigenObject(eigenMatrix);
	auto transposedObject = LinearAlgebraObject::createFromEigenObject(eigenTransposedMatrix);

	Matrix matrix(object), transposedMatrix(transposedObject);

	bool matrixIsEqualAfterTransposing = (matrix.returnMatrixTranspose() == transposedMatrix);
	if (!matrixIsEqualAfterTransposing) {
		throw NumericalError("Matrix::transpose() returns a Matrix whose underlying matrix was not correctly transposed!\n");
	}
}

void TestMatrix::testVectorFeatures() {
	Vector vector(2, 2);
	vector(0, 0) = 0;
	vector(0, 1) = std::complex<double>(0, 1);
	vector(1, 0) = std::complex<double>(1, 0);
	vector(1, 1) = std::complex<double>(1, 1);

	std::cout << "Vector input from extending base class:\n";
	std::cout << vector << std::endl;
}