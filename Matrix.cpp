#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : Eigen::MatrixXcd(rows, columns) {}

// accessors: following Eigen notation of "m[i][j]" -> m(i, j) is the ith row and jth column of m
std::complex<double>& Matrix::operator()(unsigned int row, unsigned int column) {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

const std::complex<double>& Matrix::operator()(unsigned int row, unsigned int column) const {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

const Matrix Matrix::operator*(const Matrix& matrix) const {
	return this->Eigen::MatrixXcd::operator*(matrix);
}

// non-member functions

std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix) {
	return Eigen::operator<<(outputStream, matrix);
}

Matrix operator*(const std::complex<double> complex, const Matrix& matrix) {
	return matrix.Eigen::MatrixXcd::operator*(complex);
}

Matrix operator*(const Matrix& matrix, const std::complex<double> complex) {
	return matrix.Eigen::MatrixXcd::operator*(complex);
}

Matrix operator*(const double realScalar, const Matrix& matrix) {
	return matrix.Eigen::MatrixXcd::operator*(realScalar);
}

Matrix operator*(const Matrix& matrix, const double realScalar) {
	return matrix.Eigen::MatrixXcd::operator*(realScalar);
}