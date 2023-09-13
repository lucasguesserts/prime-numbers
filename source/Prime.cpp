#include <cmath>
#include <iterator>
#include <stdexcept>
#include <vector>

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
    for (auto i = Number(3); i < limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

auto sieve_of_erastothenes(const Number n) -> NumberSet {
    auto pool = NumberSet();
    auto primes = NumberSet();
    // initialize pool
    for (auto i = Number(2); i <= n; ++i) {
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

auto sieve_of_erastothenes_opt(const Number n) -> NumberSet {
    // create list of primes in [0 ... n]
    std::vector<bool> bs(n, true);
    NumberSet primes;
    bs[0] = bs[1] = false;
    for (auto i = Number(2); i <= n; ++i) {
        if (bs[i]) {
            primes.insert(i);
            for (auto j = i * i; j <= n; j += i) {
                bs[j] = 0;
            }
        }
    }
    return primes;
}

auto is_prime_erastothenes(const Number n, const NumberSet & primes) -> bool {
    const auto last_prime = *(std::prev(primes.end()));
    if (n > last_prime * last_prime) {
        throw std::runtime_error("the input value must be smaller than the square of the last prime");
    }
    if (primes.count(n) > 0) { return true; }
    for (const auto i : primes) {
        if (n % i == 0) { return false; }
    }
    return true;
}
