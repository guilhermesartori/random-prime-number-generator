#ifndef XORSHIFT_RANDOM_NUMBER_GENERATOR_H
#define XORSHIFT_RANDOM_NUMBER_GENERATOR_H

class XorshiftRandomNumber {
public:
  unsigned long long numberOfBits;
  unsigned long long * randomNumber;

  XorshiftRandomNumber(unsigned long long);
  ~XorshiftRandomNumber();
  XorshiftRandomNumber(XorshiftRandomNumber&) = delete;
  XorshiftRandomNumber(XorshiftRandomNumber&&);
  XorshiftRandomNumber& operator=(XorshiftRandomNumber&) = delete;
  XorshiftRandomNumber& operator=(XorshiftRandomNumber&&);
};

class XorshiftRandomNumberGenerator {
  unsigned long long state;
  unsigned long long sizeInWords;

public:
  XorshiftRandomNumberGenerator(unsigned long long);
  ~XorshiftRandomNumberGenerator();
  XorshiftRandomNumber generate();
};

#endif /* end of include guard:  */
