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
}

void TestLinearAlgebra::checkCopyAssignment() {
	
	// To do: implement a way to check for matrix equality

	Eigen::MatrixXcd matrix1(2, 2), matrix2(1, 1);

	matrix1(0, 0) = std::complex<double>(1.0, 3.0);
	matrix1(0, 1) = std::complex<double>(0, 1.0);
	matrix1(1, 0) = std::complex<double>(1.0, -3.0);
	matrix1(1, 1) = 1.0;

	matrix2(0, 0) = matrix1(0, 0);

	std::cout << "matrix1: " << std::endl;
	std::cout << matrix1 << std::endl;
	std::cout << "matrix2: " << std::endl;
	std::cout << matrix2 << std::endl;

	linearAlgebraObject = LinearAlgebraObject(matrix1);
	std::cout << "copying matrix1 into linearAlgebraObject:" << std::endl;
	std::cout << linearAlgebraObject.matrixExpression << std::endl;

	linearAlgebraObject = LinearAlgebraObject(matrix2);
	std::cout << "copying matrix2 into linearAlgebraObject:" << std::endl;
	std::cout << linearAlgebraObject.matrixExpression << std::endl;

	linearAlgebraObject = LinearAlgebraObject(matrix1 + 2 * matrix1);
	std::cout << "copying 'matrix1 + 2 * matrix1' into linearAlgebraObject:" << std::endl;
	std::cout << linearAlgebraObject.matrixExpression << std::endl;
}