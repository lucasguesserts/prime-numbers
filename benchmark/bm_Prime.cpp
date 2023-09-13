#include <catch2/catch_all.hpp>

#include "Prime.hpp"

TEST_CASE("Prime test - small number", "[benchmark][Prime]") {
    const auto N = Number(27644437);
    BENCHMARK("naive") {
        return is_prime_naive(N);
    };
}
