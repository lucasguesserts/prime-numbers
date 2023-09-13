#include <catch2/catch_all.hpp>

#include "Prime.hpp"
#include "PrimeNumbers.hpp"

TEST_CASE("Prime test", "[Prime]") {
    SECTION("naive") {
        for (const auto n : SOME_PRIME_NUMBERS) {
            CHECK(is_prime(n));
        }
    }
}
