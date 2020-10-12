#ifndef XORSHIFT_RANDOM_NUMBER_GENERATOR_H
#define XORSHIFT_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGenerator.h"
#include <chrono>
#include <cstdint>

template <int Bits>
class XorshiftRandomNumberGenerator: public RandomNumberGenerator<Bits> {
  uint32_t state;

public:
  XorshiftRandomNumberGenerator() {
    const auto time = std::chrono::system_clock::now();
    this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
      .time_since_epoch()).count();
  }

  big_integer<Bits> generate() {

    big_integer<Bits> number{};
    big_integer<Bits> aux{};

    for (auto i = 0; i < Bits/32; i++) {
      aux = 0;
      state ^= state << 13;
      state ^= state >> 3;
      state ^= state << 17;
      aux += state;
      number += (aux << 32*i);
    }
    return number;
  }

  big_integer<Bits> test() {
    big_integer<Bits> test { Bits };
    return Bits;
  }
};



#endif /* end of include guard: XORSHIFT_RANDOM_NUMBER_GENERATOR_H */
