#ifndef MILLER_RABIN_PRIME_RNG_H
#define MILLER_RABIN_PRIME_RNG_H

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
 * primalidade de Miller-Rabin.
 */
template <int Bits>
class MillerRabinPrimeRandomNumberGenerator: public PrimeRandomNumberGenerator<
Bits> {
protected:

  /* Teste  de miller-rabin
   * q satisfaz n-1 = q*2^k
   * n é o número sendo testado
   * returna true se n é provavelmente primo e false se n é composto
   */
  bool millerRabinTest(big_integer<Bits+Bits> q, big_integer<Bits> n) {

      // Gera um número aleatório 1 < a < n-1
      big_integer<Bits+Bits> a{ this->generator->generate() % n };
      while (a == n-1 || a <= 1)
        a = this->generator->generate() % n;


      // Computa a^q mod n
      big_integer<Bits+Bits> x = this->powerMod(a, q, n);

      // Se a^q mod n = 1 ou n-1, n é provavelmente primo
      if (x == 1  || x == n-1)
        return true;

      // Executa k vezes, em que k satisfaz n-1 = q*2^k
      for (; q != n-1; q *= 2) {
          // computa (a^q)² mod n
          x = (x * x) % n;

          // Se (a^q)² mod n = 1, n é composto
          if (x == 1)
            return false;

          // Se (a^q)² = n-1, n é provavelmente primo
          if (x == n-1)
            return true;
      }

      // n é composto
      return false;
  }

  /* Verifica se n é primo
   *
   */
  bool isPrime(big_integer<Bits> n) {

    // Corner cases
    if (n == 1 || n % 2 == 0)
      return false;
    else if (n == 2 || n == 3)
      return true;

    // Teste de primalidade
    else {

      // Encontra q tal que q*2^k = n-1
      big_integer<Bits+Bits> q = n - 1;
      while (q % 2 == 0)
        q /= 2;

      /* Algoritmo probabilistico, entao executa o numero de iterações que foi
       * definido
       */
      for (int i = 0; i < this->iterations; i++)
        // Executa o teste de miller-rabin. Se falhar, o número é composto.
        if (!millerRabinTest(q, n))
          return false;

      return true;
    }
  }

public:
  using PrimeRandomNumberGenerator<Bits>::PrimeRandomNumberGenerator;
};

#endif /* end of include guard: MILLER_RABIN_PRIME_RNG_H */
