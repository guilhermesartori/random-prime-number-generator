#ifndef MWC_RANDOM_NUMBER_GENERATOR_H
#define MWC_RANDOM_NUMBER_GENERATOR_H

#define M_Z_SET 678934
#define M_W 467567
#define M_Z 125681

#include "RandomNumberGenerator.h"

class MultiplyWithCarryRandomNumberGenerator: public RandomNumberGenerator {
  unsigned long long state;

public:
  MultiplyWithCarryRandomNumberGenerator();
  unsigned long long generate();
};

#endif /* end of include guard: MWC_RANDOM_NUMBER_GENERATOR_H */
