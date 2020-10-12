#include <iostream>
#include "MillerRabinPrimeRandomNumberGenerator.h"
#include "FermatPrimeRandomNumberGenerator.h"

int main(int argc, char const *argv[]) {
  FermatPrimeRandomNumberGenerator<64> prime_rng{ Generator::XORSHIFT };
  std::cout << prime_rng.generate() << std::endl;
  return 0;
}
