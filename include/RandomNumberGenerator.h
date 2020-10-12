#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

#include <boost/multiprecision/cpp_int.hpp>

template <int Bits>
using big_integer = boost::multiprecision::number<
  boost::multiprecision::cpp_int_backend<
    Bits,
    Bits,
    boost::multiprecision::unsigned_magnitude,
    boost::multiprecision::checked,
    void
  >
>;

template <int Bits>
class RandomNumberGenerator {
public:
  virtual big_integer<Bits> generate() = 0;
};


#endif /* end of include guard: RANDOM_NUMBER_GENERATOR_H */
