#pragma once
#include "LinearAlgebraObject.h"

class Matrix : protected LinearAlgebraObject {
public:
	Matrix();
	Matrix(const LinearAlgebraObject& linearAlgebraObject);
	Matrix(int rows, int cols);

	Matrix operator+(const Matrix& nextMatrix) const;
	Matrix operator-(const Matrix& nextMatrix) const;
	Matrix operator*(const Matrix& nextMatrix) const;
	template<class scalarClass>
	Matrix operator*(const scalarClass& scalar) const;
	std::complex<double>& operator()(unsigned int row, unsigned int column);
	const std::complex<double>& operator()(unsigned int row, unsigned int column) const;

	bool isEqualToDoublePrecision(const Matrix& comparisonMatrix) const;
	unsigned int numberOfRows();
	unsigned int numberOfColumns();
	unsigned int size();
};

// non-member operator overloads
template<class scalarClass>
Matrix operator*(const scalarClass& leftScalar, const Matrix& rightMatrix);
bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix);

// template function definitions:

template<class scalarClass>
Matrix Matrix::operator*(const scalarClass& scalar) const {
	const LinearAlgebraObject* thisPointer = this;
	LinearAlgebraObject product = scalar * *thisPointer;
	return Matrix(product);
}

template<class scalarClass>
Matrix operator*(const scalarClass& leftScalar, const Matrix& rightMatrix) {
	return rightMatrix.operator*(leftScalar);
}