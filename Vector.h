#pragma once
#include "Eigen/Dense"
#include <complex>
#include <iostream>

// Test: implement as direct Eigen::MatrixXcd object

class Vector : protected Eigen::MatrixXcd {
public:
	Vector() : Eigen::MatrixXcd() {}
	Vector(unsigned int rows, unsigned int columns);

	// template overrides
	template<typename derivedMatrixType>
	Vector(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) : Eigen::MatrixXcd(eigenExpression) {}

	template<typename derivedMatrixType>
	Vector& operator=(const Eigen::MatrixBase<derivedMatrixType>& eigenExpression) {
		this->Eigen::MatrixXcd::operator=(eigenExpression);
		return *this;
	}

	// basic operator overloads
	std::complex<double>& operator()(unsigned int row, unsigned int column);
	const std::complex<double>& operator()(unsigned int row, unsigned int column) const;

	friend std::ostream& operator<<(std::ostream& outputStream, const Vector& vector);
};

std::ostream& operator<<(std::ostream& outputStream, const Vector& vector);