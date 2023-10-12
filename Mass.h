#pragma once

// units of mass are mx * my = mDOS == 1
// mz is given in units of this mDOS

struct Mass {
	double mx = 1, my = 1, mz = 1;

	Mass() {}
	Mass(double mx, double mz) : mx(mx), mz(mz) {
		calculate_my();
	}

	void calculate_my() {
		my = 1.0 / mx;
	}
};