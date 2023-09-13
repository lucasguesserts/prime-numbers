#include <catch2/catch_all.hpp>
#include <string>

#include "Number.hpp"
#include "Prime.hpp"
#include "PrimeNumbers.hpp"

#define RUN(f)                                    \
    SECTION("f") {                                \
        for (const auto n : SOME_PRIME_NUMBERS) { \
            CHECK(f(n));                          \
        }                                         \
    }

TEST_CASE("Prime test", "[Prime]") {
    RUN(is_prime_naive);
    RUN(is_prime_odds);
    SECTION("is_prime_erastothenes") {
        const auto primes = sieve_of_erastothenes_opt(200);
        for (const auto n : SOME_PRIME_NUMBERS) {
            CHECK(is_prime_erastothenes(n, primes));
        }
    }
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

TEST_CASE("sieve of erastothenes - opt", "[Prime]") {
    SECTION("basic cases") {
        SECTION("2") {
            const auto N = Number(2);
            const auto actual = sieve_of_erastothenes_opt(N);
            const auto expected = std::set<Number>{2};
            CHECK(actual == expected);
        }
        SECTION("5") {
            const auto N = Number(5);
            const auto actual = sieve_of_erastothenes_opt(N);
            const auto expected = std::set<Number>{2, 3, 5};
            CHECK(actual == expected);
        }
    }
    SECTION("large case") {
        const auto N = Number(1000);
        const auto actual = sieve_of_erastothenes_opt(N);
        const auto expected = PRIME_NUMBERS_TILL_1000;
        CHECK(actual == expected);
    }
}

auto factorization_test(const Number x, const Factorization expected) {
    SECTION(std::to_string(x)) {
        const auto actual = factorize(x);
        CHECK(actual == expected);
    }
}

TEST_CASE("factorization", "[Prime]") {
    factorization_test(3, {{3, 1}});
    factorization_test(100, {{2, 2}, {5, 2}});
    factorization_test(6753, {{3, 1}, {2251, 1}});
    factorization_test(2762424, {{2, 3}, {3, 5}, {7, 2}, {29, 1}});
}
