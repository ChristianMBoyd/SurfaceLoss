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

	// static method to avoid template conflicts with multiplication overloads [avoid Eigen->LinearAlgebraObject(Eigen) in function template]
	template <typename derivedMatrixType>
	static LinearAlgebraObject createFromEigenObject(const Eigen::MatrixBase<derivedMatrixType>& genericMatrixExpression) {
		LinearAlgebraObject linearAlgebraObject;
		linearAlgebraObject.matrixExpression = genericMatrixExpression;
		return linearAlgebraObject;
	}

	// operator overloads: defer matrix operations to Eigen 
	LinearAlgebraObject operator+(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return createFromEigenObject(this->matrixExpression + nextLinearAlgebraObject.matrixExpression);
	}

	LinearAlgebraObject operator*(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return createFromEigenObject(this->matrixExpression * nextLinearAlgebraObject.matrixExpression);
	}

	LinearAlgebraObject operator-(const LinearAlgebraObject& nextLinearAlgebraObject) {
		return createFromEigenObject(this->matrixExpression - nextLinearAlgebraObject.matrixExpression);
	}
};

// also defer scalar multiplication to Eigen
template<class scalarClass>
LinearAlgebraObject operator*(const scalarClass& leftScalar, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject::createFromEigenObject(leftScalar * rightObject.matrixExpression);
}

template<typename derivedMatrixType>
LinearAlgebraObject operator*(const Eigen::MatrixBase<derivedMatrixType>& leftMatrixExpression, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject::createFromEigenObject(leftMatrixExpression * rightObject.matrixExpression);
}