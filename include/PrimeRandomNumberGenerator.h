#ifndef PRIME_RNG_H
#define PRIME_RNG_H

#include "RandomNumberGenerator.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"

// Tipos de geradores de números primos
enum class Generator {
  XORSHIFT, MWC
};

/*
 * Classe abstrata que representa um gerador de números primos genérico.
 */
template<int Bits>
class PrimeRandomNumberGenerator {
protected:
  // Gerador de números aleatórios
  std::unique_ptr<RandomNumberGenerator<Bits>> generator;

  // Número de iterações para o algoritmo de primalidade
  int iterations;

  // Computa x^y mod p.
  big_integer<Bits+Bits> powerMod(big_integer<Bits+Bits> x, big_integer<Bits+
    Bits> y, big_integer<Bits+Bits> p) {
    big_integer<Bits+Bits> result = 1;
    x = x % p;
    while (y > 0) {
      if (y & 1)
      result = (result*x) % p;
      y = y>>1;
      x = (x*x) % p;
    }
    return result;
  }

  // Verifica se n é primo. Deve ser implementado por subclasses.
  virtual bool isPrime(big_integer<Bits> n) = 0;

public:

  /* Construtor
   * Generator::XORSHIFT para utilizar um RNG xorshift, Generator::MWC para um
   * gerador MWC.
   * iterations determina o número de iterações executadas pelo algoritmo proba-
   * bilístico que verifica a primalidade
   */
  PrimeRandomNumberGenerator(Generator generator, int iterations):
    iterations { iterations } {
    switch (generator) {
      case Generator::XORSHIFT:
        this->generator = std::unique_ptr<RandomNumberGenerator<Bits>>{
          new XorshiftRandomNumberGenerator<Bits>{}
        };
        break;
      case Generator::MWC:
        this->generator = std::unique_ptr<RandomNumberGenerator<Bits>>{
          new MultiplyWithCarryRandomNumberGenerator<Bits>{}
        };
        break;
    }
  }

  // Gera um número primo aleatório.
  big_integer<Bits> generate() {
    big_integer<Bits> number{};
    bool numberIsPrime;

    /* Gera um numero aleatório, checa se ele é primo, repete o processo até
     * conseguir um primo.
     */
    do {
      number = this->generator->generate();
      numberIsPrime = this->isPrime(number);
    } while(!numberIsPrime);

    return number;
  }

};


#endif /* end of include guard: PRIME_RNG_H */
