#ifndef XORSHIFT_RANDOM_NUMBER_GENERATOR_H
#define XORSHIFT_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGeneratorInterface.h"

class XorshiftRandomNumberGenerator: public RandomNumberGeneratorInterface {
  unsigned long long state;
  unsigned long long sizeInWords;

public:
  XorshiftRandomNumberGenerator(unsigned long long);
  RandomNumber generate();
};

#endif /* end of include guard: XORSHIFT_RANDOM_NUMBER_GENERATOR_H */
