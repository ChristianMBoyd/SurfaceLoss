#include "Vector.h"

Vector::Vector() : Matrix(1, 3) {} // currently create a 3-column vector as the default to ensure only 1 row on construction

Vector::Vector(Matrix diagonalMatrix) {
	// needs Matrix::returnAsDiagonalMatrix() first
}

Vector::Vector(int columns) : Matrix(1, columns) {}