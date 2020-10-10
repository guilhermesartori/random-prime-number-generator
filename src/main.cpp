#include <iostream>
#include "RandomNumberGenerator.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"
#include "MillerRabinPrimeRandomNumberGenerator.h"

int main(int argc, char const *argv[]) {
  XorshiftRandomNumberGenerator* xorshift{ new XorshiftRandomNumberGenerator{ } };
  // MultiplyWithCarryRandomNumberGenerator mwc{ };
  MillerRabinPrimeRandomNumberGenerator prime_rng{ xorshift };
  auto number = prime_rng.generate();
  std::cout << std::hex << number << std::endl;
  return 0;
}
