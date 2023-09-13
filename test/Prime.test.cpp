#include <catch2/catch_all.hpp>

#include "Prime.hpp"
#include "PrimeNumbers.hpp"

#define RUN(f) \
SECTION("f") { \
    for (const auto n : SOME_PRIME_NUMBERS) { \
        CHECK(f(n)); \
    } \
}

TEST_CASE("Prime test", "[Prime]") {
    RUN(is_prime_naive);
    RUN(is_prime_odds);
}

TEST_CASE("sieve of erastothenes", "[Prime]") {
    const auto N = Number(1000);
    const auto actual = sieve_of_erastothenes(N);
    CHECK(actual == PRIME_NUMBERS_TILL_1000);
}
