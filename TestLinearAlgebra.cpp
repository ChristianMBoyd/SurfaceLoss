#include "TestLinearAlgebra.h"

TestLinearAlgebra::TestLinearAlgebra() {}

void TestLinearAlgebra::runTests() {
	std::cout << "Testing linear algebra implementation...\n";

	testOperatorOverloads();

	if (PASSED_TESTS) {
		std::cout << "All test cases passed.\n";
	}
	else {
		std::cout << "FAILED!\n";
	}
}

void TestLinearAlgebra::testOperatorOverloads() {
	try {
		checkOperatorOverloadFunctions();
	}
	catch (NumericalError error) {
		std::cout << "Struct LinearAlgebraObject has failed its tests.  Reason: ";
		std::cout << error.what();
		PASSED_TESTS = false;
	}
}

void TestLinearAlgebra::checkOperatorOverloadFunctions() {
	checkCopyAssignment();
	checkAddition();
	checkSubtraction();
	checkMultiplication();
}

void TestLinearAlgebra::checkCopyAssignment() {
	Eigen::MatrixXcd matrix1(2, 2), matrix2(1, 1);
	// iniitalize matrix1
	matrix1(0, 0) = std::complex<double>(1.0, 3.0);
	matrix1(0, 1) = std::complex<double>(0, 1.0);
	matrix1(1, 0) = std::complex<double>(1.0, -3.0);
	matrix1(1, 1) = 1.0;
	// initialize matrix2
	matrix2(0, 0) = matrix1(0, 0);

	linearAlgebraObject = LinearAlgebraObject(matrix1);
	bool matrixExpressionEqualsMatrix1 = twoEigenObjectsAreEqual(matrix1, linearAlgebraObject.matrixExpression);
	if (!matrixExpressionEqualsMatrix1) {
		throw NumericalError("matrixExpression differs from constructor input!\n");
	}
	linearAlgebraObject = LinearAlgebraObject(matrix1 + 2.0 * matrix1);
	matrix1 += 2.0 * matrix1;
	bool matrixExpressionResolvedEigenExpression = twoEigenObjectsAreEqual(matrix1, linearAlgebraObject.matrixExpression);
	if (!matrixExpressionResolvedEigenExpression) {
		throw NumericalError("LinearAlgebraObject did not resolve Eigen matrix expression in copy constructor!\n");
	}
	linearAlgebraObject = LinearAlgebraObject(matrix2);
	bool matrixExpressionDynamicallyResized = twoEigenObjectsAreEqual(matrix2, linearAlgebraObject.matrixExpression);
	if (!matrixExpressionDynamicallyResized) {
		throw NumericalError("matrixExpression was not able to dynamically resize!\n");
	}

	LinearAlgebraObject copyObject = linearAlgebraObject;
	bool copyConstructed = twoLinearAlgebraObjectsAreEqual(copyObject, linearAlgebraObject);
	if (!copyConstructed) {
		throw NumericalError("copy-construced object differs from initial LinearAlgebraObject!\n");
	}
}

template<typename leftDerivedMatrixType, typename rightDerivedMatrixType>
bool TestLinearAlgebra::twoEigenObjectsAreEqual(const Eigen::MatrixBase<leftDerivedMatrixType>& leftEigenObject,
  const Eigen::MatrixBase<rightDerivedMatrixType>& rightEigenObject) {
	bool sameNumberOfColumns = (leftEigenObject.cols() == rightEigenObject.cols());
	if (!sameNumberOfColumns) {
		return false;
	}
	bool sameNumberOfRows = (leftEigenObject.rows() == rightEigenObject.rows());
	if (!sameNumberOfRows) {
		return false;
	}
	return leftEigenObject.isApprox(rightEigenObject);
}

bool TestLinearAlgebra::twoLinearAlgebraObjectsAreEqual(const LinearAlgebraObject& leftObject, const LinearAlgebraObject& rightObject) {
	return twoEigenObjectsAreEqual(leftObject.matrixExpression, rightObject.matrixExpression);
}

void TestLinearAlgebra::checkAddition() {
	Eigen::MatrixXcd matrix(2, 2);
	// initialize
	matrix(0, 0) = 1.0;
	matrix(0, 1) = std::complex<double>(1.0, 2.0);
	matrix(1, 0) = std::complex<double>(1.0, -2.0);
	matrix(1, 1) = 2.0;

	linearAlgebraObject = LinearAlgebraObject(matrix);
	LinearAlgebraObject objectFromAddition = linearAlgebraObject + linearAlgebraObject;
	linearAlgebraObject = LinearAlgebraObject(matrix + matrix);

	bool additionWorks = twoLinearAlgebraObjectsAreEqual(linearAlgebraObject, objectFromAddition);
	if (!additionWorks) {
		throw NumericalError("addition of LinearAlgebraObjects is not equal to addition of Eigen objects!\n");
	}
}

void TestLinearAlgebra::checkSubtraction() {
	Eigen::MatrixXcd matrix1(2, 2), matrix2(2,2);
	// initialize
	matrix1(0, 0) = 5.0;
	matrix1(0, 1) = std::complex<double>(3.0, 2.0);
	matrix1(1, 0) = std::complex<double>(-1.0, -2.0);
	matrix1(1, 1) = -2.0;

	matrix2 = matrix1;
	matrix2(1, 1) = 5.0;
	matrix2(0, 1) = std::complex<double>(2.0, 3.0);

	LinearAlgebraObject matrix1Object(matrix1), matrix2Object(matrix2), differenceObject;
	linearAlgebraObject = matrix1Object - matrix2Object;

	bool subtractionWorks = twoEigenObjectsAreEqual(matrix1 - matrix2, linearAlgebraObject.matrixExpression);
	if (!subtractionWorks) {
		throw NumericalError("subtraction of LinearAlgebraObjects is not equal to subtraction of Eigen objects!\n");
	}
}

void TestLinearAlgebra::checkMultiplication() {
	checkScalarMultiplication();
	checkMatrixMultiplication();
}

void TestLinearAlgebra::checkScalarMultiplication() {
	Eigen::MatrixXcd matrix(2, 2);
	// initialize
	matrix(0, 0) = std::complex<double>(1.0, 2.0);
	matrix(0, 1) = std::complex<double>(0, 1.0);
	matrix(1, 0) = std::complex<double>(1.0, 0);
	matrix(1, 1) = 1.5;

	// integer test
	linearAlgebraObject = 2 * LinearAlgebraObject(matrix);
	Eigen::MatrixXcd matrixProduct = 2 * matrix;
	bool integerProductWorks = twoEigenObjectsAreEqual(matrixProduct, linearAlgebraObject.matrixExpression);
	if (!integerProductWorks) {
		throw NumericalError("scalar (int) multiplication of LinearAlgebraObject does not equal Eigen operation!\n");
	}

	// complex test
	auto complexScalar = std::complex<double>(2.0, 4.234546);
	matrixProduct = complexScalar * matrix;
	linearAlgebraObject = complexScalar * LinearAlgebraObject(matrix);
	bool complexProductWorks = twoEigenObjectsAreEqual(matrixProduct, linearAlgebraObject.matrixExpression);
	if (!complexProductWorks) {
		throw NumericalError("scalar (complex) multiplication of LinearAlgebraObject does not equal Eigen operation!\n");
	}
}

void TestLinearAlgebra::checkMatrixMultiplication() {
	Eigen::MatrixXcd matrix1(2, 2), matrix2(2, 2);
	// initialize
	matrix1(0, 0) = std::complex<double>(2.0, 3.0);
	matrix1(1, 0) = std::complex<double>(-1.0, 2.0);
	matrix1(0, 1) = std::complex<double>(1.0, -2.5) * matrix1(0, 0);
	matrix1(1, 1) = std::complex<double>(-5.1, 0.01);
	matrix2 = std::complex<double>(-1.3, 0.04) * matrix1;

	Eigen::MatrixXcd matrixProduct = matrix1 * matrix2;
	LinearAlgebraObject object1(matrix1), object2(matrix2), objectProduct(matrix1 * matrix2);
	linearAlgebraObject = object1 * object2;

	bool matrixProductsAreEqual = twoLinearAlgebraObjectsAreEqual(linearAlgebraObject, objectProduct);
	if (!matrixProductsAreEqual) {
		throw NumericalError("matrix product of LinearAlgebraObjects does not equal Eigen expression!\n");
	}

}