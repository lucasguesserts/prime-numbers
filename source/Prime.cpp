#include <cmath>
#include <set>

#include "Prime.hpp"

auto integer_sqrt(const Number n) -> Number {
    return static_cast<Number>(std::floor(std::sqrt(n)));
}

bool is_prime_naive(const Number n) {
    for (auto i = Number(2); i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

auto is_prime_odds(const Number n) -> bool {
    const auto limit = integer_sqrt(n);
    for (auto i = Number(3); i < limit; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

auto sieve_of_erastothenes(const Number n) -> std::set<Number> {
    auto pool = std::set<Number>();
    auto primes = std::set<Number>();
    // initialize pool
    for (auto i = Number(2); i < n; ++i) {
        pool.insert(i);
    }
    while (!pool.empty()) {
        const auto prime_number = *pool.begin();
        primes.insert(prime_number);
        // remove the multiples of 'prime_number'
        for (auto it = pool.begin(); it != pool.end();) {
            if (*it % prime_number == 0) {
                it = pool.erase(it);
            } else {
                ++it;
            }
        }
    }
    return primes;
}
