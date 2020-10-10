#include <iostream>
#include "RandomNumberGeneratorInterface.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"

int main(int argc, char const *argv[]) {
  XorshiftRandomNumberGenerator xorshift{ 4096ULL };
  MultiplyWithCarryRandomNumberGenerator mwc{ 4096ULL };
  RandomNumberGeneratorInterface& rng{ xorshift };
  auto number = rng.generate();
  for (unsigned long long i = 0; i < number.numberOfBits/64; i++) {
    std::cout << std::hex << number.randomNumber[i] << '\n';
  }
  std::cout << std::endl;

  return 0;
}
