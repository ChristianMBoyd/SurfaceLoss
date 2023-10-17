#pragma once
// math includes
#include <cmath>
#include <complex>
#include <vector>
// Linear algebra includes
#include "Eigen/Dense"
// To do: include MKL

// This is an Eigen wrapper, which accesses all of the linear algebra functions via an internal Eigen::MatrixXcd object

class LinearAlgebraObject {
public:
	Eigen::MatrixXcd matrixExpression; // base matrix object used for matrices, vectors, solvers, etc.

	LinearAlgebraObject();
	// static method to avoid Eigen->LinearAlgebraObject(Eigen) conflicts in function templates
	template <typename derivedMatrixType>
	static LinearAlgebraObject createFromEigenObject(const Eigen::MatrixBase<derivedMatrixType>& genericMatrixExpression);
	// operator overloads: defer matrix operations to Eigen 
	LinearAlgebraObject operator+(const LinearAlgebraObject& nextLinearAlgebraObject);
	LinearAlgebraObject operator*(const LinearAlgebraObject& nextLinearAlgebraObject);
	LinearAlgebraObject operator-(const LinearAlgebraObject& nextLinearAlgebraObject);
};

// defer scalar multiplication to Eigen
template<class scalarClass>
LinearAlgebraObject operator*(const scalarClass& leftScalar, const LinearAlgebraObject& rightObject);
template<class scalarClass>
LinearAlgebraObject operator*(const LinearAlgebraObject& leftObject, const scalarClass& rightScalar);

// template function definitions below

template <typename derivedMatrixType>
LinearAlgebraObject LinearAlgebraObject::createFromEigenObject(const Eigen::MatrixBase<derivedMatrixType>& genericMatrixExpression) {
	LinearAlgebraObject linearAlgebraObject;
	linearAlgebraObject.matrixExpression = genericMatrixExpression;
	return linearAlgebraObject;
}

template<class scalarClass>
LinearAlgebraObject operator*(const scalarClass& leftScalar, const LinearAlgebraObject& rightObject) {
	return LinearAlgebraObject::createFromEigenObject(leftScalar * rightObject.matrixExpression);
}

template<class scalarClass>
LinearAlgebraObject operator*(const LinearAlgebraObject& leftObject, const scalarClass& rightScalar) {
	return rightScalar * leftObject;
}