#pragma once
// math includes
#include <cmath>
#include <complex>
#include <vector>
// Linear algebra includes
#include "Eigen/Dense"
// To do: include MKL

// This is an Eigen wrapper, which accesses all of the linear algebra functions via an internal Eigen::MatrixXcd object

struct LinearAlgebraObject {
	Eigen::MatrixXcd matrixExpression; // base matrix object, used for matrices, vectors, solvers, etc.

	LinearAlgebraObject() {}

	// allow underlying object to be constructed from arbitrary Eigen::MatrixBase expressions
	template <typename derivedMatrixType>
	LinearAlgebraObject(const Eigen::MatrixBase<derivedMatrixType>& genericMatrixExpression) : matrixExpression(genericMatrixExpression) {}

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

// multiplication is isolated to support promotion to scalar types via Eigen
template<typename scalarType>
LinearAlgebraObject operator*(const scalarType& leftScalar, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject(leftScalar * rightObject.matrixExpression);
}
template<typename scalarType>
LinearAlgebraObject operator*(const LinearAlgebraObject& leftObject, const scalarType& rightScalar) {
	return operator*(rightScalar, leftObject);
}