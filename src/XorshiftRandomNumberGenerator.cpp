#include <chrono>
#include "XorshiftRandomNumberGenerator.h"

XorshiftRandomNumberGenerator::XorshiftRandomNumberGenerator() {
  const auto time = std::chrono::system_clock::now();
  this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
    .time_since_epoch()).count();
}

unsigned long long XorshiftRandomNumberGenerator::generate() {
  state ^= state << 13;
  state ^= state >> 7;
  state ^= state << 17;
  return state;
}
