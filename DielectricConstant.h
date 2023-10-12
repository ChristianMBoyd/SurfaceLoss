#pragma once

struct DielectricConstant {
	double epsx = 1, epsy = 1, epsz = 1;

	DielectricConstant() {}
	DielectricConstant(double epsx, double epsy, double epsz) : epsx(epsx), epsy(epsy), epsz(epsz) {}
};