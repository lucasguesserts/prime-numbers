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
    SECTION("basic cases") {
        SECTION("2") {
            const auto N = Number(2);
            const auto actual = sieve_of_erastothenes(N);
            const auto expected = std::set<Number>{2};
            CHECK(actual == expected);
        }
        SECTION("5") {
            const auto N = Number(5);
            const auto actual = sieve_of_erastothenes(N);
            const auto expected = std::set<Number>{2, 3, 5};
            CHECK(actual == expected);
        }
    }
    SECTION("large case") {
        const auto N = Number(1000);
        const auto actual = sieve_of_erastothenes(N);
        const auto expected = PRIME_NUMBERS_TILL_1000;
        CHECK(actual == expected);
    }
}
