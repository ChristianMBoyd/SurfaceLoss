#include "TestMatrix.h"
#include "Matrix.h"

TestMatrix::TestMatrix() {}

void TestMatrix::runTests() {
	std::cout << "Testing Matrix class...\n";

	testConstructors();
	testAccessors();
	testRandomMatrix();
	testEquals();
	testScalarMultiplication();
	testAddition();
	testSubtraction();
	testMatrixMultiplication();

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
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		int rows = indexGenerator.randomInt();
		int columns = indexGenerator.randomInt();
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
	Matrix matrix(matrixDimension, matrixDimension);
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex randomComplex = valueGenerator.randomComplex();
		matrix(randomRow, randomColumn) = randomComplex;
		if (!twoComplexesAreEqual(matrix(randomRow, randomColumn), randomComplex)) {
			throw AssignmentError("matrix(randomRow, randomColumn)", matrix(randomRow, randomColumn), randomComplex);
		}
	}
}

// Caution: relies on state of valueGenerator object at time of calling -- a bit hacky
Matrix TestMatrix::randomMatrix(unsigned int rows, unsigned int columns) {
	Matrix randomMatrix(rows, columns);
	for (unsigned int row_index = 0; row_index < rows; row_index++) {
		for (unsigned int column_index = 0; column_index < columns; column_index++) {
			randomMatrix(row_index, column_index) = valueGenerator.randomComplex();
		}
	}
	return randomMatrix;
}

// Caution: relies on state of valueGenerator AND indexGenerator at time of calling
Matrix TestMatrix::randomMatrix() {
	int rows = indexGenerator.randomInt();
	int columns = indexGenerator.randomInt();
	return randomMatrix(rows, columns);
}

void TestMatrix::testRandomMatrix() {
	try {
		checkRandomMatrix();
	}
	catch (...) {
		std::cout << "Class Matrix has failed its tests.  \nReason: unspecified error on randomMatrix() call!";
		PASSED_TESTS = false;
	}
}

// purely construction/assignment tests
void TestMatrix::checkRandomMatrix() {
	Matrix randomMatrix;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		randomMatrix = this->randomMatrix();
		int rows = indexGenerator.randomInt();
		int columns = indexGenerator.randomInt();
		randomMatrix = this->randomMatrix(rows, columns);
	}
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
	Matrix baseMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix derivedMatrix = baseMatrix;
	if (!(baseMatrix == derivedMatrix)) {
		throw NumericalError("one matrix copied from another is not deemed equal!\n");
	}
	derivedMatrix(0, 0) = valueGenerator.randomComplex();
	if (baseMatrix == derivedMatrix) {
		throw NumericalError("matrices with one unequal entry were deemed equal!\n");
	}
}

void TestMatrix::checkIsNotEquals() {
	Matrix baseMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix derivedMatrix = baseMatrix;
	if (baseMatrix != derivedMatrix) {
		throw NumericalError("identical matrices were deemed unequal!\n");
	}
	derivedMatrix(0, 0) = valueGenerator.randomComplex();
	if (!(baseMatrix != derivedMatrix)) {
		throw NumericalError("matrices differing by a single entry were not deemed unequal!\n");
	}
	derivedMatrix = randomMatrix(matrixDimension, matrixDimension);
	if (!(baseMatrix != derivedMatrix)) {
		throw NumericalError("two randomly generated matrices were deemed equal!\n");
	}
}

void TestMatrix::testScalarMultiplication() {
	try {
		checkIntMultiplication();
		checkDoubleMultiplication();
		checkComplexMultiplication();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkIntMultiplication() {
	Matrix matrix = randomMatrix(matrixDimension, matrixDimension);
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		int randomInt = indexGenerator.randomInt();
		Matrix productMatrix = randomInt * matrix;
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex matrixComponent = randomInt * matrix(randomRow, randomColumn);
		Complex productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(int) * (Matrix) multiplication does not equal component-wise result!\n");
		}
		productMatrix = matrix * randomInt;
		productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(Matrix) * (int) multiplication does not equal component-wise result!\n");
		}
	}
}

void TestMatrix::checkDoubleMultiplication() {
	Matrix matrix = randomMatrix(matrixDimension, matrixDimension);
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		double randomDouble = valueGenerator.randomDouble();
		Matrix productMatrix = randomDouble * matrix;
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex matrixComponent = randomDouble * matrix(randomRow, randomColumn);
		Complex productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(double) * (Matrix) multiplication does not equal component-wise result!\n");
		}
		productMatrix = matrix * randomDouble;
		productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(Matrix) * (double) multiplication does not equal component-wise result!\n");
		}
	}
}

void TestMatrix::checkComplexMultiplication() {
	Matrix matrix = randomMatrix(matrixDimension, matrixDimension);
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		Complex randomComplex = valueGenerator.randomComplex();
		Matrix productMatrix = randomComplex * matrix;
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex matrixComponent = randomComplex * matrix(randomRow, randomColumn);
		Complex productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(Complex) * (Matrix) multiplication does not equal component-wise result!\n");
		}
		productMatrix = matrix * randomComplex;
		productComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(matrixComponent, productComponent)) {
			throw NumericalError("(Matrix) * (Complex) multiplication does not equal component-wise result!\n");
		}
	}
}

void TestMatrix::testAddition() {
	try {
		checkAddition();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkAddition() {
	Matrix leftMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix rightMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix sumMatrix = leftMatrix + rightMatrix;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex sum = leftMatrix(randomRow, randomColumn) + rightMatrix(randomRow, randomColumn);
		Complex sumComponent = sumMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(sum, sumComponent)) {
			throw NumericalError("Matrix addition is not equal to component-wise addition!\n");
		}
	}
}

void TestMatrix::testSubtraction() {
	try {
		checkSubtraction();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkSubtraction() {
	Matrix leftMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix rightMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix differenceMatrix = leftMatrix - rightMatrix;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex difference = leftMatrix(randomRow, randomColumn) - rightMatrix(randomRow, randomColumn);
		Complex differenceComponent = differenceMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(difference, differenceComponent)) {
			throw NumericalError("Matrix subtraction is not equal to component-wise subtraction!\n");
		}
	}
}

void TestMatrix::testMatrixMultiplication() {
	try {
		checkMatrixMultiplication();
	}
	catch (NumericalError error) {
		std::cout << "Class Matrix has failed its tests.  \nReason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestMatrix::checkMatrixMultiplication() {
	Matrix leftMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix rightMatrix = randomMatrix(matrixDimension, matrixDimension);
	Matrix productMatrix = leftMatrix * rightMatrix;
	for (int counter = 0; counter < NUMBER_OF_TESTS; counter++) {
		unsigned int randomRow = indexGenerator.randomInt() % matrixDimension;
		unsigned int randomColumn = indexGenerator.randomInt() % matrixDimension;
		Complex productComponent = 0; // manually sum over components below
		for (int innerIndex = 0; innerIndex < matrixDimension; innerIndex++) {
			productComponent += leftMatrix(randomRow, innerIndex) * rightMatrix(innerIndex, randomColumn);
		}
		Complex productMatrixComponent = productMatrix(randomRow, randomColumn);
		if (!twoComplexesAreEqual(productComponent, productMatrixComponent)) {
			throw NumericalError("Matrix multiplication does not equal component-wise operation!\n");
		}
	}
}