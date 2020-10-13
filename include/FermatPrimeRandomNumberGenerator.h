#ifndef FERMAT_PRIME_RNG_H
#define FERMAT_PRIME_RNG_H

#include <memory>
#include <random>
#include <limits>
#include <iostream>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "XorshiftRandomNumberGenerator.h"
#include "MultiplyWithCarryRandomNumberGenerator.h"
#include "PrimeRandomNumberGenerator.h"


/* Classe para geração de números aleatórios utilizando o algoritmo de
 * primalidade de fermat.
 */
template <int Bits>
class FermatPrimeRandomNumberGenerator: public PrimeRandomNumberGenerator<Bits>
{
protected:
  /* Verifica se n é primo, utilizando o algoritmo de primalidade de Fermat. */
  bool isPrime(big_integer<Bits> n) {

    // Corner cases
    if (n == 2 || n == 3)
      return true;
    if (n <= 1 || n % 2 == 0)
      return false;

    /* Algoritmo probabilistico, entao executa o numero de iterações que foi
     * definido
     */
    for (auto i = 0; i < this->iterations; i++) {
      // Encontrar um a tal que 1 < a < n - 1
      big_integer<Bits+Bits> a{ 0 };
      while (a < 2 || a == n - 1)
      a = this->generator->generate() % n;

      // Calcular a^(n-1) mod n
      auto x = this->powerMod(a, n-1, n);

      // Se a^(n-1) mod n != 1, n é composto
      if (x != 1)
      return false;
    }

    return true;
  }

public:
  using PrimeRandomNumberGenerator<Bits>::PrimeRandomNumberGenerator;
};

#endif /* end of include guard: FERMAT_PRIME_RNG_H */
