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
	Eigen::MatrixXcd matrixExpression; // base matrix object used for matrices, vectors, solvers, etc.

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

// defer scalar multiplication to Eigen
template<class scalarClass>
LinearAlgebraObject operator*(const scalarClass& leftScalar, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject(leftScalar * rightObject.matrixExpression);
}

template<typename derivedMatrixType>
LinearAlgebraObject operator*(const Eigen::MatrixBase<derivedMatrixType>& leftMatrixExpression, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject(leftMatrixExpression * rightObject.matrixExpression);
}