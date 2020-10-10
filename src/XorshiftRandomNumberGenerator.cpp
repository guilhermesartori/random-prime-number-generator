#include <iostream>
#include <string>
#include <chrono>
#include "XorshiftRandomNumberGenerator.h"

XorshiftRandomNumberGenerator::XorshiftRandomNumberGenerator(unsigned long long
  numberOfBits) {
  this->sizeInWords = numberOfBits/64;
  const auto time = std::chrono::system_clock::now();
  this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
    .time_since_epoch()).count();
  state ^= state << 17;
  state ^= state >> 23;
  state ^= state << 51;
}

RandomNumber XorshiftRandomNumberGenerator::generate() {
  RandomNumber randomNumber{ this->sizeInWords*64 };
  for (unsigned long long i = 0; i < this->sizeInWords; i++) {
    state ^= state << 13;
    state ^= state >> 7;
    state ^= state << 17;
    randomNumber.randomNumber[i] = state;
  }
  return randomNumber;
}
