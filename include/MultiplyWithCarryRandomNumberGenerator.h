#ifndef MWC_RANDOM_NUMBER_GENERATOR_H
#define MWC_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGenerator.h"
#include <cstdint>
#include <chrono>

template <int Bits>
class MultiplyWithCarryRandomNumberGenerator: public RandomNumberGenerator<Bits> {
  uint64_t state;

public:
  MultiplyWithCarryRandomNumberGenerator() {
    const auto time = std::chrono::system_clock::now();
    this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
      .time_since_epoch()).count() & 0xFFFFFFFF;
  }

  big_integer<Bits> generate() {
    big_integer<Bits> number{};
    big_integer<Bits> aux{};
    for (auto i = 0; i < Bits/64; i++) {
      state = (0xFFFFDA61 * (state & 0xFFFFFFFF)) + (state >> 32);
      aux = state;
      number += (aux << 64*i);
    }
    return number;
  }
};

#endif /* end of include guard: MWC_RANDOM_NUMBER_GENERATOR_H */
