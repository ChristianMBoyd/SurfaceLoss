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
		std::cout << "Class Matrix has failed its tests!  \nReason: unspecified error on constructor call!\n";
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkConstructorFunctions() {
	Matrix defaultMatrix;
	Matrix rowsAndColumnsMatrix;
	Matrix matrixConstructor(defaultMatrix);
	randomGenerator = RandomGenerator(1, 1000); // positive number of rows/columns
	for (int counter = 0; counter < NUMBER_OF_ASSIGNMENT_TESTS; counter++) {
		int rows = int(std::floor(randomGenerator.randomDouble()));
		int columns = int(std::floor(randomGenerator.randomDouble()));
		rowsAndColumnsMatrix = Matrix(rows, columns);
	}
}

void TestMatrix::testAccessors() {
	try {
		checkAccessors();
	}
	catch (AssignmentError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAccessors() {
	randomGenerator = RandomGenerator(); // random values on complex unit square
	Matrix matrix(NUMBER_OF_ASSIGNMENT_TESTS, NUMBER_OF_ASSIGNMENT_TESTS);
	for (int row = 0; row < NUMBER_OF_ASSIGNMENT_TESTS; row++) {
		for (int column = 0; column < NUMBER_OF_ASSIGNMENT_TESTS; column++) {
			auto randomComplex = randomGenerator.randomComplex();
			matrix(row, column) = randomComplex;
			if (!twoComplexesAreEqual(matrix(row, column), randomComplex)) {
				throw AssignmentError("matrix(row, column)", matrix(row, column), randomComplex);
			}
		}
	}
}


// Caution: relies on state of randomGenerator object at time of calling -- a bit hacky
Matrix TestMatrix::randomMatrix(unsigned int rows, unsigned int columns) {
	Matrix randomMatrix(rows, columns);
	for (unsigned int row_index = 0; row_index < rows; row_index++) {
		for (unsigned int column_index = 0; column_index < columns; column_index++) {
			randomMatrix(row_index, column_index) = randomGenerator.randomComplex();
		}
	}
	return randomMatrix;
}

void TestMatrix::testEquals() {
	try {
		checkEquals();
		checkIsNotEquals();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkEquals() {
	randomGenerator = RandomGenerator(); // random values on complex unit square
	Matrix baseMatrix = randomMatrix(NUMBER_OF_ASSIGNMENT_TESTS, NUMBER_OF_ASSIGNMENT_TESTS);
	Matrix derivedMatrix = baseMatrix;
	if (!(baseMatrix == derivedMatrix)) {
		throw NumericalError("one matrix copied from another is not deemed equal!\n");
	}
	derivedMatrix(0, 0) = randomGenerator.randomComplex();
	if (baseMatrix == derivedMatrix) {
		throw NumericalError("matrices with one unequal entry were deemed equal!\n");
	}
}

void TestMatrix::checkIsNotEquals() {
	randomGenerator = RandomGenerator(); // random values on complex unit square
	Matrix baseMatrix = randomMatrix(NUMBER_OF_ASSIGNMENT_TESTS, NUMBER_OF_ASSIGNMENT_TESTS);
	Matrix derivedMatrix = baseMatrix;
	if (baseMatrix != derivedMatrix) {
		throw NumericalError("identical matrices were deemed unequal!\n");
	}
	derivedMatrix(0, 0) = randomGenerator.randomComplex();
	if (!(baseMatrix != derivedMatrix)) {
		throw NumericalError("matrices differing by a single entry were not deemed unequal!\n");
	}
	derivedMatrix = randomMatrix(NUMBER_OF_ASSIGNMENT_TESTS, NUMBER_OF_ASSIGNMENT_TESTS);
	if (!(baseMatrix != derivedMatrix)) {
		throw NumericalError("two randomly generated matrices were deemed equal!\n");
	}
}

void TestMatrix::testMultiplication() {
	try {
		checkScalarMultiplication();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
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
	matrix(0, 0) = Complex(1.5, 1.5);
	matrix(0, 1) = Complex(0, 3.0);
	matrix(1, 0) = Complex(3.0, 0);
	matrix(1, 1) = Complex(-2, -2);

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
	auto scalar = Complex(2.0, -3.0);
	Matrix matrix(2, 2);

	matrix(0, 0) = Complex(10, -10);
	matrix(0, 1) = Complex(-2, 2.5);
	matrix(1, 0) = Complex(1.0, 0.1);
	matrix(1, 1) = Complex(0.5, -1.5);

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