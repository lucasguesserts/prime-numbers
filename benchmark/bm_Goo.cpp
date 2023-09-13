#include <catch2/catch_all.hpp>

int goo() {
    return 42;
}

TEST_CASE("Goo", "[benchmark][Goo]") {
    BENCHMARK("goo") {
        return goo();
    };
}
