#ifndef MWC_RANDOM_NUMBER_GENERATOR_H
#define MWC_RANDOM_NUMBER_GENERATOR_H

#define M_Z_SET 678934
#define M_W 467567
#define M_Z 125681

#include "RandomNumberGeneratorInterface.h"

class MultiplyWithCarryRandomNumberGenerator: public RandomNumberGeneratorInterface {
  unsigned long long state;
  unsigned long long numberOfBits;

public:
  MultiplyWithCarryRandomNumberGenerator(unsigned long long);
  RandomNumber generate();
};

#endif /* end of include guard: MWC_RANDOM_NUMBER_GENERATOR_H */
