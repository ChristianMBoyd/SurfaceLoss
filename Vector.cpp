#include "Vector.h"

Vector::Vector(unsigned int rows, unsigned int columns) : Eigen::MatrixXcd(rows, columns) {}

// accessors: following Eigen notation of "m[i][j]" -> m(i, j) is the ith row and jth column of m
std::complex<double>& Vector::operator()(unsigned int row, unsigned int column) {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

const std::complex<double>& Vector::operator()(unsigned int row, unsigned int column) const {
	return this->Eigen::MatrixXcd::operator()(row, column);
}

// non-member functions

std::ostream& operator<<(std::ostream& outputStream, const Vector& vector) {
	return Eigen::operator<<(outputStream, vector);
}
