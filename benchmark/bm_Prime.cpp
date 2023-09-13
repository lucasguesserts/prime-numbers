#include <catch2/catch_all.hpp>

#include "Prime.hpp"

TEST_CASE("Prime test - small number", "[benchmark][Prime]") {
    const auto N = Number(27644437);
    const auto primes = sieve_of_erastothenes_opt(11083);
    BENCHMARK("naive") {
        return is_prime_naive(N);
    };
    BENCHMARK("odds") {
        return is_prime_odds(N);
    };
    BENCHMARK("erastothenes") {
        return is_prime_erastothenes(N, primes);
    };
}

TEST_CASE("Prime test - large number", "[benchmark][Prime]") {
    const auto N = Number(1000000007);
    const auto primes = sieve_of_erastothenes_opt(36011);
    BENCHMARK("odds") {
        return is_prime_odds(N);
    };
    BENCHMARK("erastothenes") {
        return is_prime_erastothenes(N, primes);
    };
}

TEST_CASE("Prime test - sieve of erastothenes", "[benchmark][Prime]") {
    const auto SMALL = Number(10000);
    BENCHMARK("small") {
        return sieve_of_erastothenes(SMALL);
    };
    BENCHMARK("small") {
        return sieve_of_erastothenes_opt(SMALL);
    };
}

