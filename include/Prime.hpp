#ifndef PRIME_HPP_
#define PRIME_HPP_

#include <set>

#include "Number.hpp"

bool is_prime_naive(const Number n);

auto is_prime_odds(const Number n) -> bool;

auto sieve_of_erastothenes(const Number n) -> std::set<Number>;

#endif
