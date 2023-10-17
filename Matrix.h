#pragma once
#include "LinearAlgebraObject.h"

class Matrix : protected LinearAlgebraObject {
public:
	Matrix();
	Matrix(const LinearAlgebraObject& linearAlgebraObject);
	Matrix(int rows, int cols);

	Matrix operator+(const Matrix& nextMatrix);
	Matrix operator-(const Matrix& nextMatrix);
	Matrix operator*(const Matrix& nextMatrix);
	template<class scalarClass>
	Matrix operator*(const scalarClass& scalar);

	bool isEqualToDoublePrecision(const Matrix& comparisonMatrix) const;
};

// non-member operator overloads
template<class scalarClass>
Matrix operator*(const scalarClass& leftScalar, const Matrix& rightMatrix);
bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix);

// template function definitions below

template<class scalarClass>
Matrix Matrix::operator*(const scalarClass& scalar) {
	LinearAlgebraObject* thisPointer = this;
	LinearAlgebraObject product = scalar * *thisPointer;
	return Matrix(product);
}

template<class scalarClass>
Matrix operator*(const scalarClass& leftScalar, const Matrix& rightMatrix) {
	return rightMatrix * leftScalar;
}