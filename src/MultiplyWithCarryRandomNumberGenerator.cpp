#include <chrono>
#include "MultiplyWithCarryRandomNumberGenerator.h"

MultiplyWithCarryRandomNumberGenerator::MultiplyWithCarryRandomNumberGenerator()
{
  const auto time = std::chrono::system_clock::now();
  this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
    .time_since_epoch()).count() & 0xFFFFFFFF;
}

unsigned long long MultiplyWithCarryRandomNumberGenerator::generate() {
  state = (0xFFFFDA61 * (state & 0xFFFFFFFF)) + (state >> 32);
  return state;
}
