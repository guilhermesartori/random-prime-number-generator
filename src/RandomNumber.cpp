#include "RandomNumberGeneratorInterface.h"

RandomNumber::RandomNumber(unsigned long long numberOfBits) {
  this->numberOfBits = numberOfBits;
  this->randomNumber = new unsigned long long[numberOfBits];
}

RandomNumber::~RandomNumber() {
  delete[] randomNumber;
}

RandomNumber::RandomNumber(RandomNumber&& other) {
  this->randomNumber = other.randomNumber;
  this->numberOfBits = other.numberOfBits;
  other.randomNumber = nullptr;
  other.numberOfBits = 0;
}

RandomNumber& RandomNumber::operator=(RandomNumber&& other) {
  delete[] this->randomNumber;
  this->randomNumber = other.randomNumber;
  this->numberOfBits = other.numberOfBits;
  other.randomNumber = nullptr;
  other.numberOfBits = 0;

  return *this;
}
