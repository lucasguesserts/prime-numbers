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
