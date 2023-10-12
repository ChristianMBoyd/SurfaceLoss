#pragma once
#include "DielectricConstant.h"
#include "Mass.h"
#include "ModelParameters.h"
#include "PlanarWavevector.h"
#include "NumericalParameters.h"

struct Parameters {
	PlanarWavevector planarWavevector;
	DielectricConstant dielectricConstant;
	Mass mass;
	ModelParameters modelParameters;
	NumericalParameters numericalParameters;

	Parameters() {} // each of previous have valid default constructors
};