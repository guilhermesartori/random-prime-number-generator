#ifndef MWC_RANDOM_NUMBER_GENERATOR_H
#define MWC_RANDOM_NUMBER_GENERATOR_H

#include "RandomNumberGenerator.h"
#include <cstdint>
#include <chrono>

/*
 * Classe para geração de números aleatórios com o método MWC.
 */
template <int Bits>
class MultiplyWithCarryRandomNumberGenerator: public RandomNumberGenerator<Bits>
{
  // Armazena o último número aleatório gerado
  uint64_t state;

public:

  // Construtor
  MultiplyWithCarryRandomNumberGenerator() {
    // Utiliza o tempo do sistema como seed inicial
    const auto time = std::chrono::system_clock::now();
    this->state = std::chrono::duration_cast<std::chrono::milliseconds>(time
      .time_since_epoch()).count() & 0xFFFFFFFF;
  }

  // Gera um número aleatório
  big_integer<Bits> generate() {
    big_integer<Bits> number{};
    big_integer<Bits> aux{};

    // Numeros maiores que 64 bits são a concatenação de vários números de 64
    for (auto i = 0; i < Bits/64; i++) {

      // Parametros recomendados por Marsaglia
      state = (0xFFFFDA61 * (state & 0xFFFFFFFF)) + (state >> 32);
      aux = state;

      // Concatenação dos valores gerados
      number += (aux << 64*i);
    }
    return number;
  }

};

#endif /* end of include guard: MWC_RANDOM_NUMBER_GENERATOR_H */
