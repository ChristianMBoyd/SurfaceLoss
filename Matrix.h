#pragma once
#include "Eigen/Dense"
#include "Complex.h"
#include <iostream>

// This is an Eigen::MatrixXcd wrapper with basic operations wrapped and necessary functionality extended

class Matrix : protected Eigen::MatrixXcd {
public:
	Matrix() : Eigen::MatrixXcd() {}
	Matrix(unsigned int rows, unsigned int columns);
	template<typename derivedMatrixType>
	Matrix(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);

	// basic operator overloads
	Complex& operator()(unsigned int row, unsigned int column);
	const Complex& operator()(unsigned int row, unsigned int column) const;
	const Matrix operator*(const Matrix& matrix) const;
	bool operator==(const Matrix& matrix);

	template<typename derivedMatrixType>
	Matrix& operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);


	// external operator overloads
	friend std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix);
	friend Matrix operator*(const Complex complex, const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix, const Complex complex);
	friend Matrix operator*(const double realScalar, const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix, const double realScalar);
};

// templated function definitions
template<typename derivedMatrixType>
Matrix::Matrix(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) : Eigen::MatrixXcd(eigenExpression) {}

template<typename derivedMatrixType>
Matrix& Matrix::operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) {
	this->Eigen::MatrixXcd::operator=(eigenExpression);
	return *this;
}



