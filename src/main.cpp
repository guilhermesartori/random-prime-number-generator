#include <iostream>
#include "RandomNumberGeneratorInterface.h"
#include "XorshiftRandomNumberGenerator.h"

int main(int argc, char const *argv[]) {
  XorshiftRandomNumberGenerator xorshift{ 4096ULL };
  RandomNumberGeneratorInterface& rng{ xorshift };
  auto number = rng.generate();
  for (unsigned long long i = 0; i < number.numberOfBits/64; i++) {
    std::cout << number.randomNumber[i];
  }
  std::cout << std::endl;

  return 0;
}
