#pragma once

// frequencies are in units of the plasma frequency in the dual (scaled) isotropic system

struct ModelParameters {
	double frequency = 1, linewidth = 0.1, plasmaToFermiRatio = 1;

	ModelParameters() {}
	ModelParameters(double frequency, double linewidth, double plasmaToFermiRatio) :
		frequency(frequency), linewidth(linewidth), plasmaToFermiRatio(plasmaToFermiRatio) {}
};