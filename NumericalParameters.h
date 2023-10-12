#pragma once

// L is the finite system size in units of 1/kF, where kF is the Fermi wavevector of the dual isotropic (scaled) system
// cutoffWavevector marks the truncation (in magnitude) of sums over wavevectors --- also in units of kF
//		in the limit of large kF * L >> 1, a cutoffWavevector >~ 2-5 includes the dominant contribution

struct NumericalParameters {
	double L = 1, cutoffWavevector = 5;

	NumericalParameters() {}
	NumericalParameters(double L, double cutoffWavevector) : L(L), cutoffWavevector(cutoffWavevector) {}
};
