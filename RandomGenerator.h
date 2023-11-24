#pragma once
#include <random>
#include <chrono>
#include <cmath>
#include "Complex.h"

class RandomGenerator {
private:
	std::uniform_real_distribution<double> distribution;
	std::default_random_engine randomEngine;
	double randomMin, randomMax;

public:
	RandomGenerator();
	RandomGenerator(double randomMin, double randomMax);

	void setNewMinAndMax(double randomMin, double randomMax);

	int randomInt();
	double randomDouble();
	Complex randomComplex();

private:
	void initialize();
};