#include <iostream>
#include "XorshiftRandomNumberGenerator.h"

int main(int argc, char const *argv[]) {
  auto xorshift = XorshiftRandomNumberGenerator(4096ULL);
  auto number = xorshift.generate();
  for (unsigned long long i = 0; i < number.numberOfBits/64; i++) {
    std::cout << number.randomNumber[i];
  }
  std::cout << std::endl;
  return 0;
}
