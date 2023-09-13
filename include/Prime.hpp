#ifndef PRIME_HPP_
#define PRIME_HPP_

#include "Number.hpp"

auto integer_sqrt(const Number n) -> Number;

bool is_prime_naive(const Number n); // O(N)

auto is_prime_odds(const Number n) -> bool; // O(sqrt(N))

auto sieve_of_erastothenes(const Number n) -> NumberSet; //  O(N log log N)
auto sieve_of_erastothenes_opt(const Number n) -> NumberSet; //  O(N log log N)
auto is_prime_erastothenes(const Number n, const NumberSet & primes) -> bool;

#endif
