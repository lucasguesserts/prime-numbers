#ifndef PRIME_HPP_
#define PRIME_HPP_

#include <set>

#include "Number.hpp"

auto integer_sqrt(const Number n) -> Number;

bool is_prime_naive(const Number n); // O(N)

auto is_prime_odds(const Number n) -> bool; // O(sqrt(N))

auto sieve_of_erastothenes(const Number n) -> std::set<Number>; //  O(N log log N)

#endif
