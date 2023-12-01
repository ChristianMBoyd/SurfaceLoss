#pragma once
#include "Eigen/Dense"
#include "Complex.h"
#include <iostream>

// This is an Eigen::MatrixXcd wrapper with basic operations wrapped and desired functionality extended

class Matrix : protected Eigen::MatrixXcd {
public:
	Matrix() : Eigen::MatrixXcd() {}
	Matrix(unsigned int rows, unsigned int columns);
	template<typename derivedMatrixType>
	Matrix(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);

	// basic operator overloads
	Complex& operator()(unsigned int row, unsigned int column);
	const Complex& operator()(unsigned int row, unsigned int column) const;
	const Matrix operator+(const Matrix& matrix) const;
	const Matrix operator-(const Matrix& matrix) const;
	const Matrix operator*(const Matrix& matrix) const;
	const Matrix operator*(const Complex complexScalar) const;
	const Matrix operator* (const double realScalar) const;
	const Matrix operator*(const int realScalar) const;
	bool operator==(const Matrix& matrix);
	bool operator!=(const Matrix& matrix);

	template<typename derivedMatrixType>
	Matrix& operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);

	// external operator overloads
	friend std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix);
};

// external scalar * matrix product overalods
Matrix operator*(const Complex complex, const Matrix& matrix);
Matrix operator*(const double realScalar, const Matrix& matrix);
Matrix operator*(const int realScalar, const Matrix& matrix);

// templated function definitions
template<typename derivedMatrixType>
Matrix::Matrix(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) : Eigen::MatrixXcd(eigenExpression) {}

template<typename derivedMatrixType>
Matrix& Matrix::operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) {
	this->Eigen::MatrixXcd::operator=(eigenExpression);
	return *this;
}