#pragma once
#include "Test.h"
#include "LinearAlgebraObject.h"

class TestLinearAlgebra : public Test {
private:
	LinearAlgebraObject linearAlgebraObject;

public:
	TestLinearAlgebra();
	void runTests();

	void testOperatorOverloads();
	void checkOperatorOverloadFunctions();
	void checkCopyAssignment();
	template<typename leftDerivedMatrixType, typename rightDerivedMatrixType>
	bool twoEigenObjectsAreEqual(const Eigen::MatrixBase<leftDerivedMatrixType>& leftEigenObject,
		const Eigen::MatrixBase<rightDerivedMatrixType>& rightEigenObject);
	bool twoLinearAlgebraObjectsAreEqual(const LinearAlgebraObject& leftObject, const LinearAlgebraObject& rightObject);
	void checkAddition();
	void checkSubtraction();
	void checkMultiplication();
	void checkScalarMultiplication();
	void checkMatrixMultiplication();
};