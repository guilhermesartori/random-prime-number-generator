#ifndef FERMAT_PRIME_RNG_H
#define FERMAT_PRIME_RNG_H

#include <memory>
#include <random>
#include <limits>
#include <iostream>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"
#include "PrimeRandomNumberGenerator.h"

template <int Bits>
class FermatPrimeRandomNumberGenerator {
private:
  std::unique_ptr<RandomNumberGenerator<Bits>> generator;

  big_integer<Bits+Bits> powerMod(big_integer<Bits+Bits> x, big_integer<Bits+Bits> y, big_integer<Bits+Bits> p) {
  	big_integer<Bits+Bits> res = 1;	 // Initialize result
  	x = x % p; // Update x if it is more than or
  				// equal to p
  	while (y > 0)
  	{
  		// If y is odd, multiply x with result
  		if (y & 1)
  			res = (res*x) % p;

  		// y must be even now
  		y = y>>1; // y = y/2
  		x = (x*x) % p;
  	}
  	return res;
  }

public:
  FermatPrimeRandomNumberGenerator(Generator generator) {
    switch (generator) {
      case Generator::XORSHIFT:
        this->generator = std::unique_ptr<RandomNumberGenerator<Bits>>{new XorshiftRandomNumberGenerator<Bits>{}};
        break;
      case Generator::MWC:
        this->generator = std::unique_ptr<RandomNumberGenerator<Bits>>{new MultiplyWithCarryRandomNumberGenerator<Bits>{}};
        break;
    }
  }

  bool isPrime(big_integer<Bits> n) {
    int k = 10;

    // Corner cases
    if (n == 2 || n == 3)
      return true;
    if (n == 1 || n % 2 == 0)
      return false;

    for (auto i = 0; i < k; i++) {
      // Encontrar um a tal que 1 < a < n - 1
      big_integer<Bits+Bits> a{ 0 };
      while (a < 2 || a == n - 1)
      a = this->generator->generate() % n;

      // Calcular a^(n-1) mod n
      auto x = powerMod(a, n-1, n);

      // Se a^(n-1) mod n != 1, n é composto
      if (x != 1)
        return false;
    }

    return true;
  }

  big_integer<Bits> generate() {
    big_integer<Bits> number = this->generator->generate();
    bool numberIsPrime = this->isPrime(number);
    while(!numberIsPrime) {
      number = this->generator->generate();
      numberIsPrime = this->isPrime(number);
    }
    return number;
  }
};

#endif /* end of include guard: FERMAT_PRIME_RNG_H */
