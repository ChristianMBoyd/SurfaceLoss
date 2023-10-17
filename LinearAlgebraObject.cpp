#include "LinearAlgebraObject.h"

LinearAlgebraObject::LinearAlgebraObject() {}

// operator overloads: defer matrix operations to Eigen 
LinearAlgebraObject LinearAlgebraObject::operator+(const LinearAlgebraObject& nextLinearAlgebraObject) {
	return createFromEigenObject(this->matrixExpression + nextLinearAlgebraObject.matrixExpression);
}

LinearAlgebraObject LinearAlgebraObject::operator*(const LinearAlgebraObject& nextLinearAlgebraObject) {
	return createFromEigenObject(this->matrixExpression * nextLinearAlgebraObject.matrixExpression);
}

LinearAlgebraObject LinearAlgebraObject::operator-(const LinearAlgebraObject& nextLinearAlgebraObject) {
	return createFromEigenObject(this->matrixExpression - nextLinearAlgebraObject.matrixExpression);
}