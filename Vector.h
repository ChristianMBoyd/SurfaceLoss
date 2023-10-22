#pragma once
#include "Matrix.h"

// Vector is implemented as a Matrix object with one row

class Vector : public Matrix {
public:
	Vector();
	Vector(Matrix diagonalMatrix);
	Vector(int columns);

	// To do: finish Vector class -- decide how to handle various components/inheritance!
};