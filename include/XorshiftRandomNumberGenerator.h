#ifndef XORSHIFT_RANDOM_NUMBER_GENERATOR_H
#define XORSHIFT_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGenerator.h"

class XorshiftRandomNumberGenerator: public RandomNumberGenerator {
  unsigned long long state;

public:
  XorshiftRandomNumberGenerator();
  unsigned long long generate();
};

#endif /* end of include guard: XORSHIFT_RANDOM_NUMBER_GENERATOR_H */
