#ifndef RANDOM_NUMBER_GENERATOR_INTERFACE_H
#define RANDOM_NUMBER_GENERATOR_INTERFACE_H

class RandomNumber {
public:
  unsigned long long numberOfBits;
  unsigned long long * randomNumber;

  RandomNumber(unsigned long long);
  ~RandomNumber();
  RandomNumber(const RandomNumber&) = delete;
  RandomNumber(RandomNumber&&);
  RandomNumber& operator=(const RandomNumber&) = delete;
  RandomNumber& operator=(RandomNumber&&);
};

class RandomNumberGeneratorInterface {
public:
  virtual RandomNumber generate() = 0;
};


#endif /* end of include guard: RANDOM_NUMBER_GENERATOR_INTERFACE_H */
