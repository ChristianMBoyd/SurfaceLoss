#pragma once
#include <cmath>

struct PlanarWavevector {
	double qx, qy, magnitude;

	PlanarWavevector() : qx(0.0), qy(0.0), magnitude(0.0) {}
	PlanarWavevector(double qx, double qy) : qx(qx), qy(qy) {
		setMagnitude();
	}

	void setMagnitude() {
		magnitude = std::sqrt(qx * qx + qy * qy);
	}
};