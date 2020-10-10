#ifndef MILLER_RABIN_PRIME_RNG_H
#define MILLER_RABIN_PRIME_RNG_H

#include <memory>
#include "RandomNumberGenerator.h"

class MillerRabinPrimeRandomNumberGenerator {
  std::unique_ptr<RandomNumberGenerator> generator;

public:
  MillerRabinPrimeRandomNumberGenerator(RandomNumberGenerator&);
  MillerRabinPrimeRandomNumberGenerator(RandomNumberGenerator*);

  unsigned long long generate();
};

#endif /* end of include guard: MILLER_RABIN_PRIME_RNG_H */
