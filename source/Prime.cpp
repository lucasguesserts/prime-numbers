#include <cmath>

#include "Prime.hpp"

bool is_prime_naive(const Number n) {
    for (auto i = Number(2); i < n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

auto is_prime_odds(const Number n) -> bool {
    const auto limit = static_cast<Number>(std::floor(std::sqrt(n)));
    for (auto i = Number(3); i < limit; i+=2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
