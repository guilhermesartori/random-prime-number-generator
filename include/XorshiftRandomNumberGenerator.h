#ifndef XORSHIFT_RANDOM_NUMBER_GENERATOR_H
#define XORSHIFT_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGenerator.h"
#include <chrono>
#include <cstdint>

/*
 * Classe para geração de números aleatórios com o método XORSHIFT.
 */
template <int Bits>
class XorshiftRandomNumberGenerator: public RandomNumberGenerator<Bits> {
  // Armazena o último número aleatório gerado
  uint32_t state;

public:

  // Construtor
  XorshiftRandomNumberGenerator() {
    // Utiliza o tempo do sistema como seed inicial
    const auto time = std::chrono::system_clock::now();
    this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
      .time_since_epoch()).count();
  }

  // Gera um número aleatório
  big_integer<Bits> generate() {
    big_integer<Bits> number{};
    big_integer<Bits> aux{};

    // Numeros maiores que 32 bits são a concatenação de vários números de 32
    for (auto i = 0; i < Bits/32; i++) {

      // Parametros recomendados por Marsaglia
      state ^= state << 13;
      state ^= state >> 3;
      state ^= state << 17;
      aux = state;

      // Concatenação dos valores gerados
      number += (aux << 32*i);
    }

    return number;
  }

};



#endif /* end of include guard: XORSHIFT_RANDOM_NUMBER_GENERATOR_H */
