#ifndef MILLER_RABIN_PRIME_RNG_H
#define MILLER_RABIN_PRIME_RNG_H

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
class MillerRabinPrimeRandomNumberGenerator {
private:
  std::unique_ptr<RandomNumberGenerator<Bits>> generator;

  big_integer<Bits+Bits> power(big_integer<Bits+Bits> x, big_integer<Bits+Bits> y, big_integer<Bits+Bits> p) {
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

  bool miillerTest(big_integer<Bits+Bits> d, big_integer<Bits> n) {
      // Pick a random number in [2..n-2]
      // Corner cases make sure that n > 4
      big_integer<Bits+Bits> a{ this->generator->generate() % n };
      while (a == n-1 || a == 1ULL || a == 0ULL)
        a = this->generator->generate() % n;


      // Compute a^d % n
      big_integer<Bits+Bits> x = power(a, d, n);

      if (x == 1ULL  || x == n-1ULL)
        return true;

      // Keep squaring x while one of the following doesn't
      // happen
      // (i)   d does not reach n-1
      // (ii)  (x^2) % n is not 1
      // (iii) (x^2) % n is not n-1
      while (d != n-1)
      {
          x = (x * x) % n;
          d *= 2ULL;


          if (x == 1ULL)
            return false;
          if (x == n-1ULL)
            return true;
      }

      // Return composite
      return false;
  }

public:
  MillerRabinPrimeRandomNumberGenerator(Generator generator) {
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
    if (n == 1)
      return false;
    else if (n == 2)
      return true;
    else if (n == 3)
      return true;
    else if (n % 2 == 0)
      return false;
    else {
      big_integer<Bits+Bits> d = n - 1;
      while (d % 2 == 0)
        d /= 2;

      for (int i = 0; i < k; i++)
        if (!miillerTest(d, n))
          return false;

      return true;
    }
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

#endif /* end of include guard: MILLER_RABIN_PRIME_RNG_H */
