#pragma once
#include "LinearAlgebraObject.h"

struct Matrix : public LinearAlgebraObject {
	Matrix() {}
	Matrix(const LinearAlgebraObject& linearAlgebraObject) {
		this->matrixExpression = linearAlgebraObject.matrixExpression;
	}
	Matrix(int rows, int cols) {
		this->matrixExpression = Eigen::MatrixXcd(rows, cols);
	}
};