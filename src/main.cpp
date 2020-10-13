#include <iostream>
#include "MillerRabinPrimeRandomNumberGenerator.h"
#include "FermatPrimeRandomNumberGenerator.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"

constexpr int BITS = 512;
constexpr int ITERATIONS = 100;

void millerRabinXorshift() {
  MillerRabinPrimeRandomNumberGenerator<BITS> generator{
    Generator::XORSHIFT,
    ITERATIONS
  };

  std::cout << "Miller-Rabin with XORSHIFT: " << std::hex
    << generator.generate() << std::endl << std::endl;
}

void millerRabinMWC() {
  MillerRabinPrimeRandomNumberGenerator<BITS> generator{
    Generator::MWC,
    ITERATIONS
  };

  std::cout << "Miller-Rabin with Multiply-with-Carry: " << std::hex
    << generator.generate() << std::endl << std::endl;
}

void fermatXorshift() {
  FermatPrimeRandomNumberGenerator<BITS> generator{
    Generator::XORSHIFT,
    ITERATIONS
  };

  std::cout << "Fermat with XORSHIFT: " << std::hex
    << generator.generate() << std::endl << std::endl;
}

void fermatMWC() {
  FermatPrimeRandomNumberGenerator<BITS> generator{
    Generator::MWC,
    ITERATIONS
  };

  std::cout << "Fermat with Multiply-with-Carry: "<< std::hex
    << generator.generate() << std::endl << std::endl;
}

void xorshift() {
  XorshiftRandomNumberGenerator<BITS> generator{};
  std::cout << "XORSHIFT: "<< std::hex
    << generator.generate() << std::endl << std::endl;
}

void mwc() {
  MultiplyWithCarryRandomNumberGenerator<BITS> generator{};
  std::cout << "Multiply-with-Carry: " << std::hex
    << generator.generate() << std::endl << std::endl;
}

int main(int argc, char const *argv[]) {
  millerRabinXorshift();
  millerRabinMWC();
  fermatXorshift();
  fermatMWC();
  xorshift();
  mwc();
}
