#include "RandomGenerator.h"

// defaults to random values within the unit line, (-1,1)
RandomGenerator::RandomGenerator() : randomMin(-1.0), randomMax(1.0) {
	initialize();
}

RandomGenerator::RandomGenerator(double randomMin, double randomMax) : randomMin(randomMin), randomMax(randomMax) {
	if (randomMin > randomMax) {
		this->randomMax = randomMin;
		this->randomMin = randomMax;
	}
	initialize();
}

void RandomGenerator::initialize() {
	distribution = std::uniform_real_distribution<double>(randomMin, randomMax);
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	randomEngine = std::default_random_engine(seed);
}

void RandomGenerator::setNewMinAndMax(double randomMin, double randomMax) {
	this->randomMin = randomMin;
	this->randomMax = randomMax;
	initialize();
}

int RandomGenerator::randomInt() {
	return int(distribution(randomEngine));
}

double RandomGenerator::randomDouble() {
	return distribution(randomEngine);
}

Complex RandomGenerator::randomComplex() {
	double real = randomDouble();
	double imag = randomDouble();
	return Complex(real, imag);
}