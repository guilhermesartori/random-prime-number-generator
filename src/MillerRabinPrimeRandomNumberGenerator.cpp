#include "MillerRabinPrimeRandomNumberGenerator.h"

MillerRabinPrimeRandomNumberGenerator::MillerRabinPrimeRandomNumberGenerator(
  RandomNumberGenerator* generator): generator{ generator } { }

unsigned long long MillerRabinPrimeRandomNumberGenerator::generate() {
  return generator->generate();
}
