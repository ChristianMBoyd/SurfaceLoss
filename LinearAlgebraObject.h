#pragma once
// math includes
#include <cmath>
#include <complex>
#include <vector>
// Linear algebra includes
#include "Eigen/Dense"
// To do: include MKL

// This is a wrapper class incorporating the necessary linear algebra methods using Eigen to handle the details
// All details are built out of an internal Eigen::MatrixXd object, with custom function wrappers as appropriate

struct LinearAlgebraObject {
protected:
	Eigen::MatrixXcd matrixExpression; // base matrix object, used for matrices, vectors, solvers, etc.

public:
	LinearAlgebraObject() {}

	// allow underlying object to be constructed from arbitrary expressions
	template <typename genericMatrixType>
	LinearAlgebraObject(const Eigen::MatrixBase<genericMatrixType>& genericMatrixExpression) : matrixExpression(genericMatrixExpression) {}

	// operator overloads: defer to Eigen::MatrixXd underlying operations
	LinearAlgebraObject operator+(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return LinearAlgebraObject(this->matrixExpression + nextLinearAlgebraObject.matrixExpression);
	}

	LinearAlgebraObject operator*(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return LinearAlgebraObject(this->matrixExpression * nextLinearAlgebraObject.matrixExpression);
	}

	LinearAlgebraObject operator-(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return LinearAlgebraObject(this->matrixExpression - nextLinearAlgebraObject.matrixExpression);
	}
};