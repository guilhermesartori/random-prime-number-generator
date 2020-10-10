#include <chrono>
#include "MultiplyWithCarryRandomNumberGenerator.h"

MultiplyWithCarryRandomNumberGenerator::MultiplyWithCarryRandomNumberGenerator(unsigned long long numberOfBits) {
  const auto time = std::chrono::system_clock::now();
  this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
    .time_since_epoch()).count() & 0xFFFFFFFF;
  this->numberOfBits = numberOfBits;
}

RandomNumber MultiplyWithCarryRandomNumberGenerator::generate() {
  RandomNumber number{ this->numberOfBits };
  for (unsigned long long i = 0; i < this->numberOfBits/64; i++) {
    state = (0xFFFFDA61 * (state & 0xFFFFFFFF)) + (state >> 32);
    number.randomNumber[i] = state;
  }
  return number;
}
