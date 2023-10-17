#include "Matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(const LinearAlgebraObject& linearAlgebraObject) {
	this->matrixExpression = linearAlgebraObject.matrixExpression;
}

Matrix::Matrix(int rows, int cols) {
	this->matrixExpression = Eigen::MatrixXcd(rows, cols);
}

Matrix Matrix::operator+(const Matrix& nextMatrix) {
	LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject sum = *thisPointer + *nextPointer;
	return Matrix(sum);
}

Matrix Matrix::operator-(const Matrix& nextMatrix) {
	LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject difference = *thisPointer - *nextPointer;
	return Matrix(difference);
}

Matrix Matrix::operator*(const Matrix& nextMatrix) {
	LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject product = *thisPointer * *nextPointer;
	return Matrix(product);
}

bool Matrix::isEqualToDoublePrecision(const Matrix& comparisonMatrix) const {
	return this->matrixExpression.isApprox(comparisonMatrix.matrixExpression);
}

// non-member operator overloads

bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix) {
	return leftMatrix.isEqualToDoublePrecision(rightMatrix);
}