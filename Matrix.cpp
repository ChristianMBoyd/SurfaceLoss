#include "Matrix.h"

Matrix::Matrix() {}

Matrix::Matrix(const LinearAlgebraObject& linearAlgebraObject) {
	this->matrixExpression = linearAlgebraObject.matrixExpression;
}

Matrix::Matrix(int rows, int cols) {
	this->matrixExpression = Eigen::MatrixXcd(rows, cols);
}

Matrix Matrix::operator+(const Matrix& nextMatrix) const {
	const LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject sum = *thisPointer + *nextPointer;
	return Matrix(sum);
}

Matrix Matrix::operator-(const Matrix& nextMatrix) const {
	const LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject difference = *thisPointer - *nextPointer;
	return Matrix(difference);
}

Matrix Matrix::operator*(const Matrix& nextMatrix) const {
	const LinearAlgebraObject* thisPointer = this;
	const LinearAlgebraObject* nextPointer = &nextMatrix;
	LinearAlgebraObject product = *thisPointer * *nextPointer;
	return Matrix(product);
}

// accessors: following Eigen notation of "m[i][j]" -> m(i, j) is the ith row and jth column of m
std::complex<double>& Matrix::operator()(unsigned int row, unsigned int column) {
	return this->matrixExpression(row, column);
}

const std::complex<double>& Matrix::operator()(unsigned int row, unsigned int column) const {
	return this->matrixExpression(row, column);
}

bool Matrix::isEqualToDoublePrecision(const Matrix& comparisonMatrix) const {
	return this->matrixExpression.isApprox(comparisonMatrix.matrixExpression);
}

unsigned int Matrix::numberOfRows() {
	return this->matrixExpression.rows();
}

unsigned int Matrix::numberOfColumns() {
	return this->matrixExpression.cols();
}

unsigned int Matrix::size() {
	return numberOfRows() * numberOfColumns();
}

void Matrix::transposeInPlace() {
	matrixExpression.transposeInPlace();
}

Matrix Matrix::returnMatrixTranspose() {
	auto transposedObject = LinearAlgebraObject::createFromEigenObject(matrixExpression.transpose());
	return Matrix(transposedObject);
}

// non-member operator overloads

bool operator==(const Matrix& leftMatrix, const Matrix& rightMatrix) {
	return leftMatrix.isEqualToDoublePrecision(rightMatrix);
}