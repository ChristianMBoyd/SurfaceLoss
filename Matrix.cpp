#include "Matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns) : Eigen::MatrixXcd(rows, columns) {}

// accessors: following Eigen notation of "m[i][j]" -> m(i, j) is the ith row and jth column of m
Complex& Matrix::operator()(unsigned int row, unsigned int column) {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

const Complex& Matrix::operator()(unsigned int row, unsigned int column) const {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

const Matrix Matrix::operator+(const Matrix& matrix) const {
	return this->Eigen::MatrixXcd::operator+(matrix);
}

const Matrix Matrix::operator-(const Matrix& matrix) const {
	return this->Eigen::MatrixXcd::operator-(matrix);
}

const Matrix Matrix::operator*(const Matrix& matrix) const {
	return this->Eigen::MatrixXcd::operator*(matrix);
}

const Matrix Matrix::operator*(const Complex complex) const {
	return this->Eigen::MatrixXcd::operator*(complex);
}

const Matrix Matrix::operator* (const double realScalar) const {
	return this->Eigen::MatrixXcd::operator*(realScalar);
}

const Matrix Matrix::operator*(const int realScalar) const {
	return this->Eigen::MatrixXcd::operator*(realScalar);
}

bool Matrix::operator==(const Matrix& matrix) {
	return this->isApprox(matrix);
}

bool Matrix::operator!=(const Matrix& matrix) {
	return !(this->operator==(matrix));
}

// non-member functions

std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix) {
	return Eigen::operator<<(outputStream, matrix);
}

Matrix operator*(const Complex complex, const Matrix& matrix) {
	return matrix * complex;
}

Matrix operator*(const double realScalar, const Matrix& matrix) {
	return matrix * realScalar;
}

Matrix operator*(const int realScalar, const Matrix& matrix) {
	return matrix * realScalar;
}