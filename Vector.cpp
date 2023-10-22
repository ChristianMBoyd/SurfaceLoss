#include "Vector.h"

Vector::Vector() {}

Vector::Vector(Matrix diagonalMatrix) {
	// needs Matrix::returnAsDiagonalMatrix() first
}

Vector::Vector(int columns) : Matrix(1, columns) {}

Matrix Vector::returnAsDiagonalMatrix() {
	auto objectRepresentation = LinearAlgebraObject::createFromEigenObject(matrixExpression.diagonal());
	return Matrix(objectRepresentation);
}