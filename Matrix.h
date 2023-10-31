#pragma once
#include "Eigen/Dense"
#include <complex>
#include <iostream>

// Test: implement as direct Eigen::MatrixXcd object

class Matrix : protected Eigen::MatrixXcd {
public:
	Matrix() : Eigen::MatrixXcd() {}
	Matrix(unsigned int rows, unsigned int columns);
	template<typename derivedMatrixType>
	Matrix(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);

	// basic operator overloads
	std::complex<double>& operator()(unsigned int row, unsigned int column);
	const std::complex<double>& operator()(unsigned int row, unsigned int column) const;
	const Matrix operator*(const Matrix& matrix) const;

	template<typename derivedMatrixType>
	Matrix& operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression);


	// external operator overloads
	friend std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix);
	friend Matrix operator*(const std::complex<double> complex, const Matrix& matrix);
	friend Matrix operator*(const Matrix& matrix, const std::complex<double> complex);
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



