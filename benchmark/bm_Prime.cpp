#include <catch2/catch_all.hpp>

#include "Prime.hpp"

TEST_CASE("Prime test - small number", "[benchmark][Prime]") {
    const auto N = Number(27644437);
    BENCHMARK("naive") {
        return is_prime_naive(N);
    };
    BENCHMARK("odds") {
        return is_prime_odds(N);
    };
}

TEST_CASE("Prime test - large number", "[benchmark][Prime]") {
    const auto N = Number(1000000007);
    BENCHMARK("odds") {
        return is_prime_odds(N);
    };
}

TEST_CASE("Prime test - sieve of erastothenes", "[benchmark][Prime]") {
    const auto SMALL = Number(10000);
    const auto LARGE = Number(10000000);
    BENCHMARK("small") {
        return sieve_of_erastothenes(SMALL);
    };
    BENCHMARK("large") {
        return sieve_of_erastothenes(LARGE);
    };
}

