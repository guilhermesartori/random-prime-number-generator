#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

#include <boost/multiprecision/cpp_int.hpp>

/* Definição do tipo big_integer, que representa um inteiro sem sinal de tamanho
 * igual a Bits.
 */
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

/*
 * Classe abstrata que representa um gerador de números aleatórios genérico
 */
template <int Bits>
class RandomNumberGenerator {
public:
  // Gera um número aleatório. Deve ser implementado pelas subclasses.
  virtual big_integer<Bits> generate() = 0;
};


#endif /* end of include guard: RANDOM_NUMBER_GENERATOR_H */
