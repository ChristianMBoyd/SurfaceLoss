#pragma once
#include "Matrix.h"

class Vector : public Matrix {
public:
	Vector();
	Vector(Matrix diagonalMatrix);
	Vector(int columns);

	Matrix returnAsDiagonalMatrix();

	// To do: finish Vector class -- decide how to handle various components/inheritance!
};